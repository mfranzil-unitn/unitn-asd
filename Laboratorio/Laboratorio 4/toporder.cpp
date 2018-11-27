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

stack<int>* topSort(vector<Nodo*>& G);
void tsdfs(vector<Nodo*>& G, int u, vector<bool>* visited, stack<int>* S);

int main() {
    int N, M;
    vector<Nodo*> G;
    vector<Nodo*> GT;

    ifstream in("input.txt");
    in >> N >> M;

    for (int i = 0; i < N; i++) {
        Nodo* tmp = new Nodo();
        // tmp->index = i;
        //tmp->visitato = false;
        G.push_back(tmp);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        // cout << from  << " " << to;
        G.at(from)->vic.push_back(to);
    }

    ofstream out("output.txt");
    stack<int>* res = topSort(G);

    for(int i = 0; !res->empty(); i++) {
        out << res->top() << " ";
        res->pop();
    }

    return 0;
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