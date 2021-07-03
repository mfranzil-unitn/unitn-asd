#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

void pick_triangle(vector<char> triangoli, int start, int end, int pick);

int N;
map<string, bool> done;
set<int> results;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> N;

    if (N % 2 == 0) {
        throw new exception();
    }

    vector<char> triangoli(N);

    for (int i = 0; i < N; i++) {
        in >> triangoli.at(i);
    }

    for (int i = 1; i < N - 1; i++) {
        cout << "Calling from entrypoint " << i << "\n";
        pick_triangle(triangoli, 0, N - 1, i);
    }

    out << results.size() << "\n";
    for (auto& i : results) {
        out << i << " ";
    }
}

void pick_triangle(vector<char> triangoli, int start, int end, int pick) {
    char direzione = triangoli.at(pick);
    int future_start = start, future_end = end;
    triangoli.at(pick) = 'N';

    if (direzione == 's') {
        for (int i = pick - 1; i >= start; i--) {
            if (triangoli.at(i) != 'N') {
                triangoli.at(i) = 'N';
                break;
            }
        }
        while (triangoli.at(future_start) == 'N') {
            future_start++;
        }
    } else if (direzione == 'd') {
        for (int i = pick + 1; i <= end; i++) {
            if (triangoli.at(i) != 'N') {
                triangoli.at(i) = 'N';
                break;
            }
        }
        while (triangoli.at(future_end) == 'N') {
            future_end--;
        }
    }
    //cout << "pick_triangle(" << start << ", " << end << ", " << pick << ")\n";
    /*for (int i = 0; i < N; i++) {
            cout << triangoli.at(i) << " ";
        }
        cout << "\n";*/

    if (future_start == future_end) {
        results.insert(future_start);
    } else {
        for (int i = future_start + 1; i <= future_end - 1; i++) {
            if (triangoli.at(i) != 'N' &&
                !done.count(string(triangoli.begin(), triangoli.end()))) {
                pick_triangle(triangoli, future_start, future_end, i);
            }
        }
    }

    done.insert(pair<string, bool>(string(triangoli.begin(), triangoli.end()), true));
}