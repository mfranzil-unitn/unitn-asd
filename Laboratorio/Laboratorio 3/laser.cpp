#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Arco {
    int to, tPerc, primaAcc, tAcc, tSpeg;
    Arco(int t, int p, int a, int c, int s)
        : to(t), tPerc(p), primaAcc(a), tAcc(c), tSpeg(s) {
    }

    int partenza(int t) {
        if (t < primaAcc) {
            return primaAcc;
        }

        int ciclo = tAcc + tSpeg;
        int pos = (t - primaAcc) % ciclo;

        if (tAcc - pos >= tPerc) {
            return t;
        } else {
            return t - pos + ciclo;
        }
    }
};

struct Nodo {
    vector<Arco*> vic;
    int index;
    int dist;
    int prev;
    bool visitato;
};

int laser();
int partenza(int from, int to, int t);

map<int, map<int, vector<int>>> dati;
vector<Nodo*> G;

int main() {
    int N, M;

    ifstream in("input.txt");
    in >> N >> M;

    for (int i = 0; i < N; i++) {
        Nodo* tmp = new Nodo();
        tmp->visitato = false;
        tmp->dist = -1;
        tmp->prev = -1;
        G.push_back(tmp);
    }

   // clock_t begin = clock();
    for (int i = 0; i < M; i++) {
        int from, to, tPerc, primaAcc, tAcc, tSpeg;
        in >> from >> to >> tPerc >> primaAcc >> tAcc >> tSpeg;

        if (tAcc >= tPerc) {
            Arco* fr = new Arco(to, tPerc, primaAcc, tAcc, tSpeg);
            Arco* t = new Arco(from, tPerc, primaAcc, tAcc, tSpeg);
            
            G.at(from)->vic.push_back(fr);
            G.at(to)->vic.push_back(t);
        }
    }

    ofstream out("output.txt");
    int res = laser();

    //clock_t end = clock();
    //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    //cout << elapsed_secs;

    out << res << endl;

    if (res != -1) {
        Nodo* tmp = G.at(N - 1);
        vector<int> cammino;

        cammino.push_back(N - 1);
        while (tmp->prev != -1) {
            cammino.push_back(tmp->prev);
            tmp = G.at(tmp->prev);
        }

        for (int i = cammino.size() - 1; i >= 0; i--) {
            out << cammino.at(i) << endl;
        }
    }
    return 0;
}

int laser() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push(make_pair(0, 0));
    G.at(0)->dist = 0;

    while (!Q.empty()) {
        auto tmp = Q.top();
        Q.pop();

        int index = tmp.second;

        if (!G.at(index)->visitato) {
            G.at(index)->visitato = true;
            Nodo* u = G.at(index);

            for (int i = 0; i < u->vic.size(); i++) {
                Arco* l = u->vic.at(i);
                Nodo* v = G.at(l->to);
                int dist = l->partenza(u->dist) + l->tPerc;

                if (v->dist == -1 || dist < v->dist) {
                    v->dist = dist;
                    v->prev = index;
                    Q.push(make_pair(dist, l->to));
                }
            }
        }
    }

    return G.at(G.size() - 1)->dist;
}