#include "got.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <fstream>
#include <queue>
#include <random>
#include <set>
#include <vector>

#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4

ifstream in;
ofstream out;

int N, M;
vector<vector<int>> map;
vector<vector<int>> mask;

set<pair<int, int>> removed;

//vector<vector<pair<int, int>>> castles;

int divide(queue<pair<int, int>> tmps);
void print();
void get_size(int i, int j, int& size, bool dir[]);
void expand(int i, int j, int& size, int item, int& tries);

int main() {
    int min_so_far = INT32_MAX;
    out.open("output.txt");
    out.close();

    for (int p = 0; true; p++) {
        in.open("input.txt");
        out.open("output.txt", std::ofstream::out | std::ofstream::app);
        queue<pair<int, int>> tmps;

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

                map[i][j] = tmp;
                //mask[i][j] = 0;

                if (tmp != 0) {
                    tmps.push(make_pair(i, j));
                    //castles.at(tmp).insert(make_pair(i, j));
                }
            }
        }

        int rasi_al_suolo = divide(tmps);
        if (rasi_al_suolo < min_so_far) {
            printf("Rasi al suolo: %d\n", rasi_al_suolo);
            min_so_far = rasi_al_suolo;
            print();
        }
        in.close();
        out.close();
        map.clear();
        mask.clear();

        if (rasi_al_suolo == 0) {
            break;
        }
    } /*
    ifstream in("input.txt");
    int trash;
    in >> trash >> trash;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            in >> trash;
            if (trash != 0 && trash != mask[i][j] && (mask[i][j] != -1 || mask[i][j] != 0)) {
                //printf("!!!!! (%d, %d)", i, j);
            }
        }
    }
*/
    /* //printf("Castles:\n");
    for (int i = 0; i < M * N; i++) {
        //printf("%d ", castles.at(i));
    }*/
    return 0;
}

int divide(queue<pair<int, int>> tmps) {
    int res = 0;
    /* for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int item = map[i][j];
            if (item != 0 && mask[i][j] == 0) {
                //int size = 1;
                //bool dir[4] = {1, 1, 1, 1};
                //mask[i][j] = item;
                //get_size(i, j, size, dir);
                //int tries = 0;
                //expand(i, j, size, item, tries);
                //if (size < item) {
                //  //printf("Warning: i=%d, j=%d does not respect\n", i, j);
                //}
                ////printf("%d, %d: %d\n", i, j, size);
                //print();
            }
        }
    }
*/
    while (!tmps.empty()) {
        pair<int, int> current = tmps.front();
        tmps.pop();
        int i = current.first;
        int j = current.second;

        int item = map[i][j];
        if (mask[i][j] != 0 || map[i][j] == 0) {
            continue;
        }

        removed.clear();
        int size = 1;
        bool dir[4] = {1, 1, 1, 1};

        mask[i][j] = item;
        get_size(i, j, size, dir);

        if (size > item) {
            continue;
        }

        int tries = 0;
        expand(i, j, size, item, tries);

        if (size < item) {
            res++;
            //printf("..%d", res);
            for (const pair<int, int> item : removed) {
                //printf(" (i=%d, j=%d),", item.first, item.second);
                map[item.first][item.second] = -1;  // non toccarmi
                mask[item.first][item.second] = 0;
            }
            //printf(" (valore: %d, dim %d)\n", item, size);
        }

        if (size != item) {
            continue;
        }

        ////printf("%d, %d: %d\n", i, j, size);
    } /*
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int item = map[i][j];
            if (item != 0 && mask[i][j] == 0) {
                removed.clear();
                int size = 1;
                bool dir[4] = {1, 1, 1, 1};
                mask[i][j] = -item;
                get_size(i, j, size, dir);

                int tries = 0;
                expand(i, j, size, item, tries);
                if (size < item) {
                    //printf("Rado al suolo %d,%d (valore: %d, dim %d)\n", i, j, item, size);
                    for (const pair<int, int> item : removed) {
                        map[item.first][item.second] = 0;
                        mask[item.first][item.second] = 0;
                    }  //  //printf("Warning: i=%d, j=%d does not respect\n", i, j);
                }
                ////printf("%d, %d: %d\n", i, j, size);
                print();
            }
        }
    }*/
    return res;
}

void expand(int i, int j, int& size, int item, int& tries) {
    /* if (map[i - 1][j] == item ||
        map[i + 1][j] == item ||
        map[i][j + 1] == item ||
        map[i][j - 1] == item) {
        return;*/

    if ((i > 0 && map[i - 1][j] == item && !removed.count(make_pair(i - 1, j))) ||
        (i < N - 1 && map[i + 1][j] == item && !removed.count(make_pair(i + 1, j))) ||
        (j > 0 && map[i][j - 1] == item && !removed.count(make_pair(i, j - 1))) ||
        (j < M - 1 && map[i][j + 1] == item && !removed.count(make_pair(i, j + 1)))) {
        //printf("Found a conflict, should reset!\n");
        --size;
        return;
    }

    map[i][j] = item;
    mask[i][j] = item;
    removed.insert(make_pair(i, j));
    //printf("expand(DIR, i=%d, j=%d, size=%d, item=%d, tries=%d)\n", i, j, size, item, tries);

    array<int, 4> choices{UP, DOWN, LEFT, RIGHT};
    shuffle(choices.begin(), choices.end(), default_random_engine(chrono::system_clock::now().time_since_epoch().count()));

    for (int o = 0; o < 4; o++) {  // rendere randomico?
        int k = choices[o];
        if (tries >= 20000000 || size >= item) {
            break;
        }
        // for (int n = 0; n < i*kj; n++) //printf(" ");

        switch (k) {
            case UP: {
                if (i > 0 && map[i - 1][j] == 0) {
                    expand(i - 1, j, ++size, item, ++tries);
                } /*else if (i > 0 && map[i - 1][j] == map[i][j]) {
                    map[i][j] = 0;
                    break;
                }*/
                else {
                    ++tries;
                    continue;
                }
            }; break;
            case DOWN: {
                if (i < N - 1 && map[i + 1][j] == 0) {
                    expand(i + 1, j, ++size, item, ++tries);
                } /*else if (i > 0 && map[i + 1][j] == map[i][j]) {
                    map[i][j] = 0;
                    break;
                } */
                else {
                    ++tries;
                    continue;
                }
            }; break;
            case LEFT: {
                if (j > 0 && map[i][j - 1] == 0) {
                    expand(i, j - 1, ++size, item, ++tries);
                } /*else if (i > 0 && map[i][j - 1] == map[i][j]) {
                    map[i][j] = 0;
                    break;
                } */
                else {
                    ++tries;
                    continue;
                }
            }; break;
            case RIGHT: {
                if (j < M - 1 && map[i][j + 1] == 0) {
                    expand(i, j + 1, ++size, item, ++tries);
                } /*else if (i > 0 && map[i][j + 1] == map[i][j]) {
                    map[i][j] = 0;
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
        map[i][j] = 0;
        mask[i][j] = 0;
    }
*/
    //if (tries >= 200000) {
    //map[i][j] = 0;
    //mask[i][j] = -1;
    //}
}

void get_size(int i, int j, int& size, bool dir[]) {
    removed.insert(make_pair(i, j));
    //printf("get_size(i=%d, j=%d, size=%d)\n", i, j, size);
    for (int k = 1; k <= 4; k++) {
        if (dir[k - 1] == 0) {
            continue;
        }
        switch (k) {
            case UP: {
                if (i > 0 && map[i - 1][j] == map[i][j] && mask[i - 1][j] == 0) {
                    bool dir[4] = {1, 0, 1, 1};
                    mask[i - 1][j] = map[i][j];
                    get_size(i - 1, j, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case DOWN: {
                if (i < N - 1 && map[i + 1][j] == map[i][j] && mask[i + 1][j] == 0) {
                    bool dir[4] = {0, 1, 1, 1};
                    mask[i + 1][j] = map[i][j];
                    get_size(i + 1, j, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case LEFT: {
                if (j > 0 && map[i][j - 1] == map[i][j] && mask[i][j - 1] == 0) {
                    bool dir[4] = {1, 1, 1, 0};
                    mask[i][j - 1] = map[i][j];
                    get_size(i, j - 1, ++size, dir);
                } else {
                    continue;
                }
            }; break;
            case RIGHT: {
                if (j < M - 1 && map[i][j + 1] == map[i][j] && mask[i][j + 1] == 0) {
                    bool dir[4] = {1, 1, 0, 1};
                    mask[i][j + 1] = map[i][j];

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
            out << (mask[i][j] == -1 ? 0 : mask[i][j]) << "\t";
        }
        out << endl;
    }
    out << "***\n";
}