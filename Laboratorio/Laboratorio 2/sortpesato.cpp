#include <climits>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<int> array;
    vector<bool> visitati;

    ifstream in("input.txt");
    int N;
    in >> N;
    array.resize(N + 1);
    visitati.resize(N + 1, false);

    for (int i = 1; i <= N; i++) {
        in >> array.at(i);
    }

    int mosse = 0;
    int prezzo = 0;
    for (int i = 1; i <= N; i++) {
        if (!visitati.at(i)) {
            if (array.at(i) != i) {
                int sum = 0;
                int mn = INT_MAX;
                int current = i;
                int num = 0;

                while (!visitati.at(array.at(current))) {
                    mn = min(mn, array.at(current));
                    sum += array.at(current);
                    visitati.at(array.at(current)) = true;
                    current = array.at(current);
                    num++;
                }
                int cp = (num - 1) * mn + sum - mn;
                if (mn != 1) {
                    cp = min(cp, 2 * (1 + mn) + num - 1 + sum - mn);
                }
                prezzo += cp;
                mosse += num - 1;
            }
            visitati[i] = true;
        }
    }
    ofstream out("output.txt");
    out << mosse << " " << prezzo << endl;
    return 0;
}
