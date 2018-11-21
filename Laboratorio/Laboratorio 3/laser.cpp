#include <fstream>
#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> vic;
    int index;
    int dist;
    int prev;
};

int laser(vector<Nodo*>& G, map<int, map<int, vector<int>>> data);
int partenza(vector<Nodo*>& G, int from, int to, int t, map<int, map<int, vector<int>>> data);

int public_N;

int main() {
    int N, M;
    vector<Nodo*> G;

    ifstream in("input.txt");
    in >> N >> M;

    public_N = N;

    map<int, map<int, vector<int>>> data;

    for (int i = 0; i < N; i++) {
        Nodo* tmp = new Nodo();
        tmp->index = i;
        tmp->dist = -1;
        tmp->prev = -1;
        G.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        int from, to, tPerc, primaAcc, tAcc, tSpeg;
        in >> from >> to >> tPerc >> primaAcc >> tAcc >> tSpeg;

        if (tAcc <= tPerc) {
            G.at(from)->vic.push_back(to);
            G.at(to)->vic.push_back(from);

            data[from][to] = {tPerc, primaAcc, tAcc, tSpeg};
            data[to][from] = {tPerc, primaAcc, tAcc, tSpeg};
        }
    }

    ofstream out("output.txt");
    out << laser(G, data);

    return 0;
}

int laser(vector<Nodo*>& G, map<int, map<int, vector<int>>> data) {
    queue<Nodo*> Q;

    Q.push(0);
    G.at(0)->dist = 0;

    while (!Q.empty()) {
        Nodo* u = Q.front();
        Q.pop();

        cout << u->vic.at(0);
        /*for (int i = 0; i < u->vic.size(); i++) {
            Nodo* v = G.at(u->vic.at(i));

            if (v->dist == -1) {
                v->dist = partenza(G, u->index, v->index, u->dist, data) + data[u->index][v->index][0];
                Q.push(v);
            }
        }*/
    }

    return G.at(G.size() - 1)->dist;
}

int partenza(vector<Nodo*>& G, int from, int to, int t, map<int, map<int, vector<int>>> data) {
    if (t < data[from][to][1]) {
        return data[from][to][1];
    }

    int ciclo = data[from][to][2] + data[from][to][3];
    int pos = (t - data[from][to][1]) % ciclo;
    if (data[from][to][2] - pos >= data[from][to][0]) {
        return t;
    } else {
        return t - pos + ciclo;
    }
}