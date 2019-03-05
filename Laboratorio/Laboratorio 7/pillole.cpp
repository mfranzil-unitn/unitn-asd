#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<long long int>> DP;

long long int zia(long long int i, long long int j) {
    cout << "zia(" << i << ", " << j << ");\n";
    if (DP.at(i).at(j) == -1) {
        if (i <= 0 && j <= 0) {
            DP.at(i).at(j) = 1;
        } else if (i > 0 && j == 0) {
            DP.at(i).at(j) = zia(i - 1, j + 1);
        } else if (i == 0 && j > 0) {
            DP.at(i).at(j) = zia(i, j - 1);
        } else {
            DP.at(i).at(j) = zia(i - 1, j + 1) + zia(i, j - 1);
        }
    }

    return DP.at(i).at(j);
}

int main() {
    long long int N;

    in >> N;

    DP = vector<vector<long long int>>(N + 1, vector<long long int>(N + 1, -1));

    out << zia(N, 0);

    return 0;
}
