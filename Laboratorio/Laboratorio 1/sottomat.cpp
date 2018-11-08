#include <fstream>
#include <vector>
using namespace std;

int main(void) {
    int R, C;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> R >> C;

    int data[R][C];
    int somme[R][C];

    for (int i = 1; i <= R; i++) {
        int sumRow = 0;
        for (int j = 1; j <= C; j++) {
            in >> data[i][j];
            sumRow += data[i][j];
            somme[i][j] = sumRow;
        }
    }

    int maxSoFar = -1;
    for (int c1 = 1; c1 <= C; c1++)
        for (int c2 = c1; c2 <= C; c2++) {
            int tot = 0;
            for (int r = 1; r <= R; r++) {
                int current = somme[r][c2] - somme[r][c1 - 1];
                tot = max(current, current + tot);
                maxSoFar = max(maxSoFar, tot);
            }
        }
    out << maxSoFar << endl;
    return 0;
}