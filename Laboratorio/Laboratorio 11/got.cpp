#include "got.h"
#include <fstream>
#include <vector>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

ifstream in("input.txt");
ofstream out("output.txt");

int N, M;
vector<vector<int>> map;
vector<vector<int>> mask;
vector<int> castles;

void divide();
void print();
void get_size(int i, int j, int& size, bool dir[]);
void expand(int i, int j, int& size, int item, int& tries);

int main() {
    in >> N >> M;

    map.resize(N);
    mask.resize(N);
    castles.resize(N * M);

    for (int i = 0; i < N; i++) {
        map.at(i).resize(M);
        mask.at(i).resize(M);
        for (int j = 0; j < M; j++) {
            int tmp;

            in >> tmp;

            map.at(i).at(j) = tmp;
            mask.at(i).at(j) = 0;

            if (tmp != 0) {
                castles.at(tmp)++;
            }
        }
    }
    srand(time(NULL));
    divide();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
        }
    }
    /* printf("Castles:\n");
    for (int i = 0; i < M * N; i++) {
        printf("%d ", castles.at(i));
    }*/
}

void divide() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int item = map.at(i).at(j);
            if (item != 0 && mask.at(i).at(j) == 0) {
                int size = 1;
                bool dir[4] = {1, 1, 1, 1};
                mask.at(i).at(j) = item;
                //get_size(i, j, size, dir);

                int tries = 0;
                expand(i, j, size, item, tries);
                if (size < item) {
                    //  printf("Warning: i=%d, j=%d does not respect\n", i, j);
                }
                //printf("%d, %d: %d\n", i, j, size);
                print();
            }
        }
    }
}

void expand(int i, int j, int& size, int item, int& tries) {
    for (int k = 1; k <= 4; k++) {  // rendere randomico?
        if (tries >= 200000 || size >= item) {
            break;
        }
        printf("expand(DIR=%d, i=%d, j=%d, size=%d, item=%d, tries=%d)\n", k, i, j, size, item, tries);

        switch (k) {
            case UP: {
                if (i > 0 && map.at(i - 1).at(j) == 0) {
                    map.at(i - 1).at(j) = item;
                    mask.at(i - 1).at(j) = item;
                    expand(i - 1, j, ++size, item, ++tries);
                } /*else if (i > 0 && map.at(i - 1).at(j) == map.at(i).at(j)) {
                    map.at(i).at(j) = 0;
                    break;
                }*/
                else {
                    ++tries;
                    continue;
                }
            }; break;
            case DOWN: {
                if (i < N - 1 && map.at(i + 1).at(j) == 0) {
                    map.at(i + 1).at(j) = item;
                    mask.at(i + 1).at(j) = item;
                    expand(i + 1, j, ++size, item, ++tries);
                } /*else if (i > 0 && map.at(i + 1).at(j) == map.at(i).at(j)) {
                    map.at(i).at(j) = 0;
                    break;
                } */
                else {
                    ++tries;
                    continue;
                }
            }; break;
            case LEFT: {
                if (j > 0 && map.at(i).at(j - 1) == 0) {
                    map.at(i).at(j - 1) = item;
                    mask.at(i).at(j - 1) = item;
                    expand(i, j - 1, ++size, item, ++tries);
                } /*else if (i > 0 && map.at(i).at(j - 1) == map.at(i).at(j)) {
                    map.at(i).at(j) = 0;
                    break;
                } */
                else {
                    ++tries;
                    continue;
                }
            }; break;
            case RIGHT: {
                if (j < M - 1 && map.at(i).at(j + 1) == 0) {
                    map.at(i).at(j + 1) = item;
                    mask.at(i).at(j + 1) = item;
                    expand(i, j + 1, ++size, item, ++tries);
                } /*else if (i > 0 && map.at(i).at(j + 1) == map.at(i).at(j)) {
                    map.at(i).at(j) = 0;
                    break;
                } */
                else {
                    ++tries;
                    continue;
                }
            }; break;
        }
    }
/*
    if (size < item) {
        map.at(i).at(j) = 0;
        mask.at(i).at(j) = 0;
    }
*/
    //if (tries >= 200000) {
    //map.at(i).at(j) = 0;
    //mask.at(i).at(j) = -1;
    //}
}

void get_size(int i, int j, int& size, bool dir[]) {
    printf("get_size(i=%d, j=%d, size=%d)\n", i, j, size);
    for (int k = 1; k <= 4; k++) {
        if (dir[k - 1] == 0) {
            continue;
        }
        switch (k) {
            case UP: {
                if (i > 0 && map.at(i - 1).at(j) == map.at(i).at(j) && mask.at(i - 1).at(j) == 0) {
                    bool dir[4] = {1, 0, 1, 1};
                    mask.at(i - 1).at(j) = map.at(i).at(j);

                    get_size(i - 1, j, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case DOWN: {
                if (i < N - 1 && map.at(i + 1).at(j) == map.at(i).at(j) && mask.at(i + 1).at(j) == 0) {
                    bool dir[4] = {0, 1, 1, 1};
                    mask.at(i + 1).at(j) = map.at(i).at(j);
                    get_size(i + 1, j, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case LEFT: {
                if (j > 0 && map.at(i).at(j - 1) == map.at(i).at(j) && mask.at(i).at(j - 1) == 0) {
                    bool dir[4] = {1, 1, 1, 0};
                    mask.at(i).at(j - 1) = map.at(i).at(j);
                    get_size(i, j - 1, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case RIGHT: {
                if (j < M - 1 && map.at(i).at(j + 1) == map.at(i).at(j) && mask.at(i).at(j + 1) == 0) {
                    bool dir[4] = {1, 1, 0, 1};
                    mask.at(i).at(j + 1) = map.at(i).at(j);

                    get_size(i, j + 1, ++size, dir);
                } else {
                    continue;
                }
            }; break;
        }
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << mask.at(i).at(j) << "\t";
        }
        out << endl;
    }
    out << "***\n";
}