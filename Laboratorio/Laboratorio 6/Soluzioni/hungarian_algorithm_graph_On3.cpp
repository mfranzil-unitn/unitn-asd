#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

// Shamelessly taken from:
// https://swerc.eu/2017/problems/

#ifdef EVAL
ifstream in("input.txt");
ofstream out("output.txt");
#else
istream& in(cin);
ostream& out(cout);
#endif

// numero componenti, numero soldati
size_t nC, nS;

struct Coords {
    int x;
    int y;
    Coords(int _x, int _y) : x(_x), y(_y) {}
    unsigned distance(Coords const& other) const {
        return abs(x - other.x) + abs(y - other.y);
    }
    friend istream& operator>>(istream& iin, Coords& coords) {
        return iin >> coords.x >> coords.y;
    }
    friend ostream& operator<<(ostream& oout, Coords& coords) {
        oout << "(" << coords.x << ", " << coords.y << ")";
        return oout;
    }
};

// vettore componenti, vettore soldati, target
vector<Coords> components;
vector<Coords> soldiers;
Coords target(0.0f, 0.0f);

// Formulation of the Hungarian Algorithm on graphs with augmenting paths
// See:
//   https://www.cse.ust.hk/~golin/COMP572/Notes/Matching.pdf
class Problem {
    size_t const nx, ny;
    vector<vector<int>> costs;  // costs[soldato][componente] == costs[row][col]

   public:
    Problem(vector<Coords> const& components, vector<Coords>& soldiers, Coords const& target)
        : nx(components.size()), ny(components.size() + soldiers.size() - 1) {
        // Add phantom soldiers based at the target position
        soldiers.reserve(ny);
        for (size_t c = soldiers.size(); c < ny; c++)
            soldiers.push_back(target);
        // Build cost matrix with negative costs (to find the minimum one)
        for (auto comp : components) {
            vector<int> row;
            row.reserve(ny);
            for (auto soldier : soldiers) {
                int cost = soldier.distance(comp) + comp.distance(target);
                row.push_back(-cost);
            }
            costs.push_back(row);
        }
    }

    unsigned solve(vector<int>& log) {
        vector<int> xy(nx, -1), yx(ny, -1), lx(nx), ly(ny, 0), augmenting(ny);
        vector<bool> s(nx);
        vector<pair<int, int>> slack(ny, make_pair(0, 0));
        for (unsigned x = 0; x < nx; x++)
            lx[x] = *max_element(costs[x].cbegin(), costs[x].cend());
        for (unsigned root = 0; root < nx; root++) {
            fill(augmenting.begin(), augmenting.end(), -1);
            fill(s.begin(), s.end(), false);
            s[root] = true;
            for (unsigned y = 0; y < ny; y++)
                slack[y] = make_pair(lx[root] + ly[y] - costs[root][y], root);
            int y = -1;
            for (;;) {
                int delta = INT_MAX, x = -1;
                for (unsigned yy = 0; yy < ny; yy++)
                    if (augmenting[yy] == -1)
                        if (slack[yy].first < delta) {
                            delta = slack[yy].first;
                            x = slack[yy].second;
                            y = yy;
                        }
                assert(s[x]);
                if (delta > 0) {
                    for (unsigned x = 0; x < nx; x++)
                        if (s[x])
                            lx[x] -= delta;
                    for (unsigned y = 0; y < ny; y++)
                        if (augmenting[y] > -1)
                            ly[y] += delta;
                        else
                            slack[y].first -= delta;
                }
                assert(lx[x] + ly[y] == costs[x][y]);
                augmenting[y] = x;
                x = yx[y];
                if (x == -1)
                    break;
                s[x] = true;
                for (unsigned y = 0; y < ny; y++)
                    if (augmenting[y] == -1) {
                        pair<int, int> alt = make_pair(lx[x] + ly[y] - costs[x][y], x);
                        if (slack[y].first > alt.first)
                            slack[y] = alt;
                    }
            }
            while (y > -1) {
                int x = augmenting[y];
                int prec = xy[x];
                yx[y] = x;
                xy[x] = y;
                log[x] = y;
                y = prec;
            }
        }
        return -(accumulate(lx.cbegin(), lx.cend(), 0) + accumulate(ly.cbegin(), ly.cend(), 0));
    }
};

void read_input() {
    in >> nC >> nS;

    components.resize(nC, Coords(0.0f, 0.0f));
    soldiers.resize(nS, Coords(0.0f, 0.0f));

    for (size_t n = 0; n < nC; n++) {
        in >> components[n];
    }

    for (size_t m = 0; m < nS; m++) {
        in >> soldiers[m];
    }

    in >> target;
}

int main() {
    read_input();

    vector<int> logconsegne;
    logconsegne.resize(nC);

    Problem problem = new Problem(components, soldiers, target);
    int mincost = problem.solve(logconsegne);

    // "mesciu" o il "mastro" in dialetto salentino
    // http://www.dialettosalentino.it/mesciu.html
    int mesciuscintu = -1;
    for (size_t n = 0; n < nC; n++) {
        if (logconsegne[n] < (int)nS) {
            mesciuscintu = logconsegne[n];
            break;
        }
    }

    out << mincost << endl;
    for (size_t n = 0; n < nC; n++) {
        if (logconsegne[n] >= (int)nS) {
            out << mesciuscintu << endl;
        } else {
            out << logconsegne[n] << endl;
        }
    }

    return 0;
}
