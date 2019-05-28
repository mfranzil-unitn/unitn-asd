#include "got.h"
#include <cassert>
#include <chrono>
#include <fstream>
#include <queue>
#include <set>
#include <thread>
#include <vector>

#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4

ifstream in("input.txt");
ofstream out("output.txt");

int N, M;
vector<vector<int>> map;
vector<vector<int>> mask;

set<pair<int, int>> removed;

struct posix : pair<int, int> {
    int j;
    int i;
};
//vector<vector<pair<int, int>>> castles;

void divide(priority_queue<pair<int, posix>> tmps);
void print();
void get_size(int i, int j, int& size, bool dir[]);
void expand(int i, int j, int& size, int item, int& tries);

int main() {
    priority_queue<pair<int, posix>> tmps;

    in >> N >> M;

    map.resize(N);
    mask.resize(N);
    // castles.resize(N * M);

    for (int i = 0; i < N; i++) {
        map.at(i).resize(M);
        mask.at(i).resize(M);
        for (int j = 0; j < M; j++) {
            int tmp;

            in >> tmp;

            map.at(i).at(j) = tmp;
            mask.at(i).at(j) = 0;

            if (tmp != 0) {
                posix tmp_el;
                tmp_el.i = i;
                tmp_el.j = j;
                tmps.push(make_pair(-tmp, tmp_el));
                //castles.at(tmp).insert(make_pair(i, j));
            }
        }
    }
    //srand(time(NULL));
    divide(tmps);
    /*
    ifstream in("input.txt");
    int trash;
    in >> trash >> trash;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            in >> trash;
            if (trash != 0 && trash != mask.at(i).at(j) && (mask.at(i).at(j) != -1 || mask.at(i).at(j) != 0)) {
                printf("!!!!! (%d, %d)", i, j);
            }
        }
    }*/

    /* printf("Castles:\n");
    for (int i = 0; i < M * N; i++) {
        printf("%d ", castles.at(i));
    }*/
    return 0;
}

void divide(priority_queue<pair<int, posix>> tmps) {
    /* for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int item = map.at(i).at(j);
            if (item != 0 && mask.at(i).at(j) == 0) {
                //int size = 1;
                //bool dir[4] = {1, 1, 1, 1};
                //mask.at(i).at(j) = item;
                //get_size(i, j, size, dir);
                //int tries = 0;
                //expand(i, j, size, item, tries);
                //if (size < item) {
                //  printf("Warning: i=%d, j=%d does not respect\n", i, j);
                //}
                //printf("%d, %d: %d\n", i, j, size);
                //print();
            }
        }
    }
*/
    while (!tmps.empty()) {
        pair<int, posix> current = tmps.top();
        tmps.pop();
        int item = -(current).first;
        int i = current.second.i;
        int j = current.second.j;

        if (mask.at(i).at(j) != 0 || map.at(i).at(j) == 0) {
            continue;
        }

        removed.clear();
        int size = 1;
        bool dir[4] = {1, 1, 1, 1};

        mask.at(i).at(j) = item;
        get_size(i, j, size, dir);

        if (size > item) {
            continue;
        }

        int tries = 0;
        expand(i, j, size, item, tries);

        if (size < item) {
            printf("Rado al suolo");
            for (const pair<int, int> item : removed) {
                printf(" (i=%d, j=%d),", item.first, item.second);
                map.at(item.first).at(item.second) = -1;  // non toccarmi
                mask.at(item.first).at(item.second) = 0;
            }
            printf(" (valore: %d, dim %d)\n", item, size);
        }

        if (size != item) {
            continue;
        }

        //printf("%d, %d: %d\n", i, j, size);
        print();
    } /*
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int item = map.at(i).at(j);
            if (item != 0 && mask.at(i).at(j) == 0) {
                removed.clear();
                int size = 1;
                bool dir[4] = {1, 1, 1, 1};
                mask.at(i).at(j) = -item;
                get_size(i, j, size, dir);

                int tries = 0;
                expand(i, j, size, item, tries);
                if (size < item) {
                    printf("Rado al suolo %d,%d (valore: %d, dim %d)\n", i, j, item, size);
                    for (const pair<int, int> item : removed) {
                        map.at(item.first).at(item.second) = 0;
                        mask.at(item.first).at(item.second) = 0;
                    }  //  printf("Warning: i=%d, j=%d does not respect\n", i, j);
                }
                //printf("%d, %d: %d\n", i, j, size);
                print();
            }
        }
    }*/
}

void expand(int i, int j, int& size, int item, int& tries) {
    /* if (map.at(i - 1).at(j) == item ||
        map.at(i + 1).at(j) == item ||
        map.at(i).at(j + 1) == item ||
        map.at(i).at(j - 1) == item) {
        return;*/

    if ((i > 0 && map.at(i - 1).at(j) == item && !removed.count(make_pair(i - 1, j))) ||
        (i < N - 1 && map.at(i + 1).at(j) == item && !removed.count(make_pair(i + 1, j))) ||
        (j > 0 && map.at(i).at(j - 1) == item && !removed.count(make_pair(i, j - 1))) ||
        (j < M - 1 && map.at(i).at(j + 1) == item && !removed.count(make_pair(i, j + 1)))) {
        printf("Found a conflict, should reset!\n");
        --size;
        return;
    }

    map.at(i).at(j) = item;
    mask.at(i).at(j) = item;
    removed.insert(make_pair(i, j));
    printf("expand(DIR, i=%d, j=%d, size=%d, item=%d, tries=%d)\n", i, j, size, item, tries);

    for (int k = 1; k <= 4; k++) {  // rendere randomico?
        if (tries >= 200000 || size >= item) {
            break;
        }
        // for (int n = 0; n < i*kj; n++) printf(" ");

        switch (k) {
            case UP: {
                if (i > 0 && map.at(i - 1).at(j) == 0) {
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
    removed.insert(make_pair(i, j));
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
            out << (mask.at(i).at(j) == -1 ? 0 : mask.at(i).at(j)) << "\t";
        }
        out << endl;
    }
    out << "***\n";
}