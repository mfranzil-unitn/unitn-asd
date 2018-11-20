#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Arco {
    int destNode;
    int tPerc;
    int primaAcc;
    int tAcc;
    int tSpeg;
};

struct Nodo {
    vector<Arco*> vic;
    int index;
};

int laser(vector<Nodo*>& G);

int main() {
    int N, M;
    vector<Nodo*> G;

    ifstream in("input.txt");
    in >> N >> M;

    for (int i = 0; i < N; i++) {
        Nodo* tmp = new Nodo();
        tmp->index = i;
        G.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        int from, to, tPerc, primaAcc, tAcc, tSpeg;
        in >> from >> to >> tPerc >> primaAcc >> tAcc >> tSpeg;

        if (tAcc <= tPerc) {
            Arco* aFrom = new Arco();
            Arco* aTo = new Arco();

            aFrom->destNode = to;
            aTo->destNode = from;

            aFrom->tPerc = aTo->tPerc = tPerc;
            aFrom->primaAcc = aTo->primaAcc = primaAcc;
            aFrom->tAcc = aTo->tAcc = tAcc;
            aFrom->tSpeg = aTo->tSpeg = tSpeg;

            G.at(from)->vic.push_back(aFrom);
            G.at(to)->vic.push_back(aTo);
        }
    }

    ofstream out("output.txt");
    out << laser(G);

    return 0;
}

int laser(vector<Nodo*>& G) {
    queue<Nodo*> Q;
    int count = 0;

    Q.push(0);
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
}

int partenza(int t) {
    if (t < inizio) {
        return inizio;
    }
    int ciclo = vivo + morto;
    int pos = (t - inizio) % ciclo;
    6 7 if (vivo - pos >= peso) { return t; }
    11 { 12 return t - pos + ciclo; }
}