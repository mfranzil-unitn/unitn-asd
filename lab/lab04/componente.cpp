#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Nodo {
    vector<int> vic;
    // int index;
    // bool visitato;
};

vector<int>* scc(vector<Nodo*>& G, vector<Nodo*>& GT);
stack<int>* topSort(vector<Nodo*>& G);
vector<int>* cc(vector<Nodo*>& G, stack<int>* S);
void ccdfs(vector<Nodo*>& G, int counter, int u, vector<int>* id);
void tsdfs(vector<Nodo*>& G, int u, vector<bool>* visited, stack<int>* S);

int counter = 0;

int main() {
    int N, M;
    vector<Nodo*> G;
    vector<Nodo*> GT;

    ifstream in("input.txt");
    in >> N >> M;

    for (int i = 0; i < N; i++) {
        Nodo* gg = new Nodo();
        Nodo* gtg = new Nodo();
        // tmp->index = i;
        //tmp->visitato = false;
        G.push_back(gg);
        GT.push_back(gtg);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        // cout << from  << " " << to;
        G.at(from)->vic.push_back(to);
        GT.at(to)->vic.push_back(from);
    }
    ofstream out("output.txt");
    vector<int>* res = scc(G, GT);

    vector<int> componenti;
    componenti.resize(counter + 1);

    sort(res->begin(), res->end());

    while (!res->empty()) {
        int tmp = res->at(0);
        componenti.at(tmp)++;
        res->erase(res->begin(), res->begin() + 1);
    }

    sort(componenti.begin(), componenti.end());

    out << componenti.at(counter);

    return 0;
}

vector<int>* scc(vector<Nodo*>& G, vector<Nodo*>& GT) {
    stack<int>* S = topSort(G);
    return cc(GT, S);
}

vector<int>* cc(vector<Nodo*>& G, stack<int>* S) {
    vector<int>* id = new vector<int>();
    id->resize(G.size());
    for (int i = 0; i < id->size(); i++) {
        id->at(i) = 0;
    }
    while (!S->empty()) {
        int u = S->top();
        S->pop();
        if (id->at(u) == 0) {
            counter++;
            ccdfs(G, counter, u, id);
        }
    }
    return id;
}

void ccdfs(vector<Nodo*>& G, int counter, int u, vector<int>* id) {
    id->at(u) = counter;
    for (int i = 0; i < G.at(u)->vic.size(); i++) {
        if (id->at(G.at(u)->vic.at(i)) == 0) {
            ccdfs(G, counter, G.at(u)->vic.at(i), id);
        }
    }
}

stack<int>* topSort(vector<Nodo*>& G) {
    stack<int>* S = new stack<int>();
    vector<bool>* visited = new vector<bool>();
    visited->resize(G.size());

    for (int i = 0; i < visited->size(); i++) {
        visited->at(i) = false;
    }

    for (int i = 0; i < visited->size(); i++) {
        if (!visited->at(i)) {
            tsdfs(G, i, visited, S);
        }
    }
    return S;
}

void tsdfs(vector<Nodo*>& G, int u, vector<bool>* visited, stack<int>* S) {
    visited->at(u) = true;
    for (int i = 0; i < G.at(u)->vic.size(); i++) {
        if (!visited->at(G.at(u)->vic.at(i))) {
            tsdfs(G, G.at(u)->vic.at(i), visited, S);
        }
    }
    S->push(u);
}