#include "got.h"
#include <fstream>
#include <vector>

ifstream in("input.txt");
ofstream out("output.txt");

int N, M;
vector<vector<int>> map;
vector<int> castles;

void divide();
void print();

int main() {
    in >> N >> M;

    map.resize(N);
    castles.resize(N * M);

    for (int i = 0; i < N; i++) {
        map.at(i).resize(M);
        for (int j = 0; j < M; j++) {
            int tmp;

            in >> tmp;

            map.at(i).at(j) = tmp;

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
    for (int i = 0; i < M*N; i++) {
        printf("%d ", castles.at(i));
    }
}

void divide() {
    //for (int i = 0; i < )
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