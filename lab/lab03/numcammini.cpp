#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> vic;
    int index;
    int path;
    int dist;
};

pair<int, int> numcammini(vector<Nodo*>& G, Nodo* S1, Nodo* T1);

int main() {
    int N, M, S, T;
    vector<Nodo*> G;

    ifstream in("input.txt");
    in >> N >> M >> S >> T;

    for (int i = 0; i < N; i++) {
        Nodo* tmp = new Nodo();
        tmp->index = i;
        tmp->dist = -1;
        tmp->path = 0;
        G.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        G.at(from)->vic.push_back(to);
    }

    ofstream out("output.txt");
    pair<int, int> output = numcammini(G, G.at(S), G.at(T));
    out << output.first << " " << output.second;

    return 0;
}

pair<int, int> numcammini(vector<Nodo*>& G, Nodo* S1, Nodo* T1) {
    queue<Nodo*> Q;
    int cammini = 0;
    Q.push(S1);

    G.at(S1->index)->dist = 0;
    G.at(S1->index)->path = 1;

    while (!Q.empty()) {
        Nodo* u = Q.front();
        Q.pop();

        for (int i = 0; i < u->vic.size(); i++) {
            Nodo* v = G.at(u->vic.at(i));

            if (v->dist == -1) {
                v->dist = u->dist + 1;
                Q.push(v);
            }
            
            // Che sia già stato visitato o meno, significa che c'è
            // un modo in più per raggiungerlo
            if (v->dist == u->dist + 1) {
                v->path = v->path + u->path;
            }
        }
    }
    return make_pair(T1->dist, G.at(T1->index)->path);
}