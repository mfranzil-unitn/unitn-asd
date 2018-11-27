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
    // int index;
    // bool visitato;
};

struct NodoCustom {
    vector<int> vic;
    int dist;
    int path;
};

vector<NodoCustom*> grafoComponenti(vector<Nodo*>& G, vector<int>* index);
int numcammini(vector<NodoCustom*>& grafoComponenti, int S1, int T1);
vector<int>* scc(vector<Nodo*>& G, vector<Nodo*>& GT);
stack<int>* topSort(vector<Nodo*>& G);
vector<int>* cc(vector<Nodo*>& G, stack<int>* S);
void ccdfs(vector<Nodo*>& G, int counter, int u, vector<int>* id);
void tsdfs(vector<Nodo*>& G, int u, vector<bool>* visited, stack<int>* S);

int counter = 0;

int main() {
    int N, M, A, B;
    vector<Nodo*> G;
    vector<Nodo*> GT;

    ifstream in("input.txt");
    in >> N >> M >> A >> B;

    for (int i = 0; i < N; i++) {
        Nodo* nodo = new Nodo();
        Nodo* nodoTrasposto = new Nodo();
        // tmp->index = i;
        //tmp->visitato = false;
        G.push_back(nodo);
        GT.push_back(nodoTrasposto);
    }

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        // cout << from  << " " << to;
        G.at(from)->vic.push_back(to);
        GT.at(to)->vic.push_back(from);
    }
    ofstream out("output.txt");
    vector<int>* index = scc(G, GT);
    vector<NodoCustom*> grafoC = grafoComponenti(G, index);

    int A_new = index->at(A) - 1;
    int B_new = index->at(B) - 1;

    int cammini = numcammini(grafoC, A_new, B_new);

    out << cammini;
 //   cout << cammini << endl;
    /* for (int i = 0; i < index->size(); i++) {
        cout << index->at(i) << " ";
    }*/

    return 0;
}

vector<NodoCustom*> grafoComponenti(vector<Nodo*>& G, vector<int>* index) {
    vector<NodoCustom*> grafoC;

    for (int i = 0; i < counter; i++) {
        NodoCustom* tmp = new NodoCustom();
        tmp->dist = -1;
        tmp->path = 0;
        grafoC.push_back(tmp);
    }
    /*
    for(int i = 0; i < index->size(); i++) {
        cout << index->at(i) - 1 << " ";
    }
*/
    for (int i = 0; i < G.size(); i++) {
        int expected_index = index->at(i) - 1;  // indice del prossimo grafo

        for (int j = 0; j < G.at(i)->vic.size(); j++) {
            //  cout << expected_index << " " << index->at(G.at(i)->vic.at(j)) - 1;

            if (index->at(G.at(i)->vic.at(j)) - 1 != expected_index) {  //indice del vertice di arrivo
                grafoC.at(expected_index)->vic.push_back(index->at(G.at(i)->vic.at(j)) - 1);
                // grafoC.at()->vic.push_back(expected_index);
            }
        }
        // cout << endl;
    }

    vector<int>::iterator it;

    for (int i = 0; i < grafoC.size(); i++) {
    //    cout << i << ": ";
        //for (int j = 0; j < grafoC.at(i)->vic.size(); j++) {
        for (it = grafoC.at(i)->vic.begin(); it != grafoC.at(i)->vic.end(); it++) {
            cout << *it << " ";
        }
       // cout << endl;
    }

    cout << endl;

    return grafoC;
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

int numcammini(vector<NodoCustom*>& grafoComponenti, int start, int end) {
    //queue<int> Q;
    //   Q.push(start);

    //grafoComponenti.at(start)->dist = 0;
    grafoComponenti.at(start)->path = 1;

    for (int i = 0; i < grafoComponenti.size(); i++) {
        NodoCustom* u = grafoComponenti.at(i);
        for (int j = 0; j < u->vic.size(); j++) {
            grafoComponenti.at(u->vic.at(j))->path += u->path;
          //  cout << i << ": " << u->vic.at(j) << " " << grafoComponenti.at(u->vic.at(j))->path << endl;
        }
    }

    /* while (!Q.empty()) {
        int front = Q.front();
        NodoCustom* u = grafoComponenti.at(front);
        Q.pop();

        for (int i = 0; i < u->vic.size(); i++) {
            NodoCustom* v = grafoComponenti.at(u->vic.at(i));
            //u->vic.erase(it);
            Q.push(u->vic.at(i));
            v->path += u->path;

            //if (v->dist == -1) {
            //v->dist = 0;
            //   v->dist = u->dist + 1;
            // }

            // Che sia già stato visitato o meno, significa che c'è
            // un modo in più per raggiungerlo
            //if (v->dist == u->dist + 1) {
            //cout << v->path << "\n";

            //}
        }
    }*/

    return grafoComponenti.at(end)->path;
}