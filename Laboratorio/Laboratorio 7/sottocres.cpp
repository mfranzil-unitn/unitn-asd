#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<int> DP;

int main() {
    int N, tmp;
    vector<int> V;

    in >> N;

    for (int i = 0; i < N; i++) {
        in >> tmp;
        V.push_back(tmp);
    }

    DP.resize(N);

    int m = 0;
    for (int i = 0; i < N; i++) {
        DP.at(i) = V.at(i);

        for (int k = 0; k < i; k++) {
            if (V.at(k) <= V.at(i)) {
                DP.at(i) = max(DP.at(i),
                               V.at(i) + DP.at(k));
            }
        }

        m = max(m, DP.at(i));
    }
    out << m << endl;
    return 0;
}