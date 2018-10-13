#include <fstream>
#include <vector>

using namespace std;

int main () {
    int N, tmp;
    vector<int> A;

    ifstream in("input.txt");
    in >> N;

    for (int i = 0; i < N; i++) {
        in >> tmp;
        A.push_back(tmp);
    }

    int maxSoFar = 0;
    int maxHere = 0;
    
    for (int i = 0; i < N; i++) {
        maxHere = max(maxHere + A[i], 0);
        maxSoFar = max(maxSoFar, maxHere);
    }

    ofstream out("output.txt");
    out << maxSoFar;

    return 0;
}