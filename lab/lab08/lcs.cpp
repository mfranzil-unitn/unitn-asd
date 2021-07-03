#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> DP;

int main() {
    string T, U;
    
    in >> T >> U;

    int N = T.size();
    int M = U.size();

    DP = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (T[i - 1] == U[j - 1]) {
                DP.at(i).at(j) = DP.at(i - 1).at(j -1) + 1;
            } else {
                DP.at(i).at(j) = max(DP.at(i - 1).at(j),
                                     DP.at(i).at(j - 1));
            }
        }
    }

    out << DP.at(N).at(M);

    return 0;
}