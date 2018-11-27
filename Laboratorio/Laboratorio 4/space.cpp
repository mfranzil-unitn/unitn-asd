#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> vic;
    bool skip;
    int componente;
    // int index;
    // bool visitato;
};

void checkConn(vector<Nodo*>& G);
bool /*pair<bool, vector<int>*>*/ cc(vector<Nodo*>& G);
vector<int>* cc_id(vector<Nodo*>& G);
void ccdfs(vector<Nodo*>& G, int counter, int u, vector<int>* id);

int main() {
    int N, M, A, B;
    vector<Nodo*> G;

    ifstream in("input.txt");
    in >> N >> M;

    for (int i = 0; i < N; i++) {
        Nodo* nodo = new Nodo();
        // tmp->index = i;
        //tmp->visitato = false;
        nodo->skip = false;
        nodo->componente = -1;
        G.push_back(nodo);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        G.at(from)->vic.push_back(to);
        G.at(to)->vic.push_back(from);
    }

    checkConn(G);
    position(G);
}

void checkConn(vector<Nodo*>& G) {
    vector<bool> skippable;
    for (int i = 0; i < G.size(); i++) {
        G.at(i)->skip = true;

        /*pair<bool, vector<int>*>*/ bool result = cc(G);

        skippable.push_back(result);
        /*
        for(int j = 0; j < result.second->size(); j++) {
            cout << result.second->at(j) << " ";
        }
        cout << endl;*/

        G.at(i)->skip = false;
    }

    for (int i = 0; i < G.size(); i++) {
        if (!skippable.at(i)) {
            G.at(i)->skip = true;
        }
        //cout << skippable.at(i) << " ";
    }

    vector<int>* id = cc_id(G);

    for (int i = 0; i < id->size(); i++) {
        G.at(i)->componente = id->at(i);
        cout << id->at(i) << " ";
    }
}

vector<int>* cc_id(vector<Nodo*>& G) {
    vector<int>* id = new vector<int>();
    id->resize(G.size());
    int counter = 0;

    for (int i = 0; i < G.size(); i++) {
        id->at(i) = 0;
    }

    for (int i = 0; i < G.size(); i++) {
        if (!G.at(i)->skip && id->at(i) == 0) {
            counter++;

            ccdfs(G, counter, i, id);
        }
    }

    return id;
}

bool /*pair<bool, vector<int>*>*/ cc(vector<Nodo*>& G) {
    vector<int>* id = new vector<int>();
    id->resize(G.size());
    int counter = 0;
    int res = true;

    for (int i = 0; i < G.size(); i++) {
        id->at(i) = 0;
    }

    for (int i = 0; i < G.size(); i++) {
        if (!G.at(i)->skip && id->at(i) == 0) {
            counter++;

            if (counter > 1) {
                res = false;
            }

            ccdfs(G, counter, i, id);
        }
    }

    return /*make_pair(*/ res /*, id)*/;
}

void ccdfs(vector<Nodo*>& G, int counter, int u, vector<int>* id) {
    id->at(u) = counter;
    for (int i = 0; i < G.at(u)->vic.size(); i++) {
        if (!G.at(G.at(u)->vic.at(i))->skip && id->at(G.at(u)->vic.at(i)) == 0) {
            ccdfs(G, counter, G.at(u)->vic.at(i), id);
        }
    }
}