#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> vic;
    int pre;
    int visit;
    int low;
};

void pokemon(int count, int node, int padre);
void pokemon2(int node, int padre, int radice, int count);

vector<Nodo *> G;
stack<int> cicli;
map<pair<int, int>, int> archi;
vector<vector<pair<int, int>>> cicli_archi;
map<pair<int, int>, bool> bridges;
int cycle_count = 0;

//vector<pair<int, int>> final_archi;

int main() {
    int N, M, from, to;

    ifstream in("input.txt");
    in >> N >> M;

    for (int i = 0; i < N; i++) {
        Nodo *tmp = new Nodo();
        tmp->pre = -1;
        tmp->low = -1;
        tmp->visit = false;
        G.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        in >> from >> to;
        archi[make_pair(from, to)] = 0;  // !
        G.at(to)->vic.push_back(from);
        G.at(from)->vic.push_back(to);
    }

    for (int i = 0; i < N; i++) {
        pokemon(1, i, -1);
    }

    cicli_archi.resize(N);

    for (int i = 0; i < N; i++) {
        pokemon2(i, -1, i, 1);
        //cout << G.size();
    }

    int size = cicli.size() - 1;
    //cout << size;
    for (int i = 0; i < size; i++) {
        int i1 = cicli.top();
        //cout << i1;
        cicli.pop();
        int i2 = cicli.top();
        cicli.pop();
        int i_new = __gcd(i1, i2);
        cicli.push(i_new);
    }

    int mcd = cicli.top();

    for (int i = 0; i < cycle_count; i++) {
        sort(cicli_archi.at(i).begin(), cicli_archi.at(i).end());
        for (int j = 0; j < cicli_archi.at(i).size(); j++) {
            archi[make_pair(cicli_archi.at(i).at(j).first, cicli_archi.at(i).at(j).second)] = j % mcd;
            // cout << cicli_archi.at(i).at(j).first << " " << cicli_archi.at(i).at(j).second << " " << archi[make_pair(from, to)] << endl;
        }
        //  cout << endl;
    }
    ofstream out("output.txt");

    out << cicli.top() << "\n";

    for (map<pair<int, int>, int>::iterator it = archi.begin(); it != archi.end(); ++it) {
        out /* << it->first.first << " " << it->first.second << " => " */ << it->second << '\n';
    }

    return 0;
}

void pokemon2(int node, int padre, int radice, int count) {
    int res = 1;

    Nodo *N = G.at(node);

    N->visit = true;

    for (int i = 0; i < N->vic.size(); i++) {
        Nodo *U = G.at(N->vic.at(i));

        bool a1, a2;
        try {
            a1 = bridges.at(make_pair(node, N->vic.at(i)));
        } catch (out_of_range ex) {
            a1 = false;
        }

        try {
            a2 = bridges.at(make_pair(N->vic.at(i), node));
        } catch (out_of_range ex) {
            a2 = false;
        }

        if (!a1 && !a2) {
            if (U->visit && N->vic.at(i) == radice && padre != radice) {
                cicli.push(count);

                if (N->vic.at(i) > node) {
                    cicli_archi.at(cycle_count).push_back(make_pair(node, N->vic.at(i)));
                } else {
                    cicli_archi.at(cycle_count).push_back(make_pair(N->vic.at(i), node));
                }

                cycle_count++;
            }

            if (!U->visit) {
                if (N->vic.at(i) > node) {
                    cicli_archi.at(cycle_count).push_back(make_pair(node, N->vic.at(i)));
                } else {
                    cicli_archi.at(cycle_count).push_back(make_pair(N->vic.at(i), node));
                }

                pokemon2(N->vic.at(i), node, radice, count + 1);
            }
        }
    }
}

void pokemon(int count, int node, int padre) {
    // cout << "Visiting edge " << node << " " << padre << endl;
    Nodo *N = G.at(node);

    N->low = count;
    N->pre = count;

    for (int i = 0; i < N->vic.size(); i++) {
        Nodo *U = G.at(N->vic.at(i));

        if (U->pre == -1) {
            pokemon(count + 1, N->vic.at(i), node);
        }

        if (N->low > U->low && padre != N->vic.at(i)) {
            N->low = U->low;
        }
    }

    if (N->pre == N->low && padre != -1) {
        //cout << "Marking bridge " << node << " " << padre;
        bridges[make_pair(node, padre)] = true;
    }
}