#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> vic;
    int index;
    bool visitato;
};

int count(vector<Nodo*> &G, Nodo* R);

int main() {
    int N, M, S;
    vector<Nodo*> G;

    ifstream in("input.txt");
    in >> N >> M >> S;

    for (int i = 0; i < N; i++) {
        Nodo* tmp = new Nodo();
        tmp->index = i;
        tmp->visitato = false;
        G.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        G.at(from)->vic.push_back(to);
    }

    ofstream out("output.txt");
    out << count(G, G.at(S));

    return 0;
}

int count(vector<Nodo*> &G, Nodo* R) {
    queue<Nodo*> Q;
    int count = 0;

    Q.push(R);
    G.at(R->index)->visitato = true;

    while (!Q.empty()) {
        Nodo* u = Q.front();
        Q.pop();
        u->visitato = true;
        count++;

        for (int i = 0; i < u->vic.size(); i++) {
            Nodo* v = G.at(u->vic.at(i));
            if (!v->visitato) {
                v->visitato = true;
                Q.push(v);
            }
        }
    }

    return count;
}