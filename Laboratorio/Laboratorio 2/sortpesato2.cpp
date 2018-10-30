#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    vector<int> array1, array2;

    ifstream in("input.txt");
    in >> N;

    array1.resize(N + 1);
    array2.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        int tmp;
        in >> tmp;
        array1.at(i) = tmp;
        array2.at(i) = tmp;
    }

    int mosse = 0;
    int prezzo = 0;
    for (int i = 1; i <= N; i++) {
        if (array1.at(i) != i) {
            for (int j = 1; j <= N; j++) {  // cambiare 1 in i
                if (array1.at(j) == i) {
                    mosse++;
                    array1.at(j) = array1.at(i);
                    array1.at(i) = i;
                }
            }
        }
    }

    for (int i = N; i > 0; i--) {
        if (array2.at(i) != i) {
            for (int j = i - 1; j > 0; j--) {
                if (array2.at(j) == i) {
                    prezzo += i + array2.at(i);
                    array2.at(j) = array2.at(i);
                    array2.at(i) = i;
                }
            }
        }
    }

    /*for (int i = 1; i <= N; i++) {
        cout << array2.at(i) << " ";
    }*/

    ofstream out("output.txt");
    out << mosse << " " << prezzo;

    return 0;
}