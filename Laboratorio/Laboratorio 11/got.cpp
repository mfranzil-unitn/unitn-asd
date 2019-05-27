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
            mask.at(i).at(j) = 1;

            if (tmp != 0) {
                castles.at(tmp)++;
            }
        }
    }

    while (true) {
        divide();
        print();
        break;
    }

    printf("Castles:\n");
    for (int i = 0; i < M * N; i++) {
        printf("%d ", castles.at(i));
    }
}

void divide() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int item = map.at(i).at(j);
            if (item != 0 && mask.at(i).at(j) == 1) {
                int size = 1;
                bool dir[4] = {1, 1, 1, 1};
                get_size(i, j, size, dir);

                if (size < item) {
                    int __rand = (rand() % 4) + 1;
                    switch (__rand) {
                    }
                    printf("%d, %d: %d\n", i, j, size);
                }
            }
        }
    }
}

void get_size(int i, int j, int& size, bool dir[]) {
    printf("get_size(%d, %d)\n", i, j);
    for (int k = 1; k <= 4; k++) {
        if (dir[k - 1] == 0) {
            continue;
        }
        switch (k) {
            case UP: {
                if (i > 0 && map.at(i - 1).at(j) == map.at(i).at(j)) {
                    bool dir[4] = {1, 0, 1, 1};
                    get_size(i - 1, j, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case DOWN: {
                if (i < N - 1 && map.at(i + 1).at(j) == map.at(i).at(j)) {
                    bool dir[4] = {0, 1, 1, 1};

                    get_size(i + 1, j, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case LEFT: {
                if (j > 0 && map.at(i).at(j - 1) == map.at(i).at(j)) {
                    bool dir[4] = {1, 1, 1, 0};

                    get_size(i + 1, j, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case RIGHT: {
                if (j < M - 1 && map.at(i).at(j + 1) == map.at(i).at(j)) {
                    bool dir[4] = {1, 1, 0, 1};

                    get_size(i + 1, j, ++size, dir);
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
            out << map.at(i).at(j) << "   ";
        }
        out << endl;
    }
    out << "***";
}