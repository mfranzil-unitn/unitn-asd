#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> vic;
    int index;
    int dist;
};

int diametro(vector<Nodo*> &G);

int main() {
    int N, M;
    vector<Nodo*> G;

    ifstream in("input.txt");
    in >> N >> M;

    for (int i = 0; i < N; i++) {
        Nodo* tmp = new Nodo();
        tmp->index = i;
        tmp->dist = -1;
        G.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        G.at(from)->vic.push_back(to);
        G.at(to)->vic.push_back(from);
    }

    ofstream out("output.txt");
    out << diametro(G);

    return 0;
}

int diametro(vector<Nodo*> &G) {
    queue<Nodo*> Q;
    int diametro = 0;

    for (int i = 0; i < G.size(); i++) {
        Nodo* R = G.at(i);
        Q.push(R);
        

        for(int i = 0; i < G.size(); i++) {
            G.at(i)->dist = -1;
        }

        G.at(R->index)->dist = 0;

        while (!Q.empty()) {
            Nodo* u = Q.front();
            Q.pop();

            for (int i = 0; i < u->vic.size(); i++) {
                Nodo* v = G.at(u->vic.at(i));
                if (v->dist == -1) {
                    v->dist = u->dist + 1;
                    diametro = max(u->dist + 1, diametro);
                    Q.push(v);
                }
            }
        }
    }
    return diametro;
}