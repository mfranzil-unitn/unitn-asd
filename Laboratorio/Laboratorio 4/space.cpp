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

pair<vector<int>*, int> checkConn(vector<Nodo*>& G);
bool /*pair<bool, vector<int>*>*/ cc(vector<Nodo*>& G);
pair<vector<int>*, int> cc_id(vector<Nodo*>& G);
pair<int, vector<int>> position(vector<Nodo*>& G, pair<vector<int>*, int>);
void ccdfs(vector<Nodo*>& G, int counter, int u, vector<int>* id);

int main() {
    int N, M, n1;
    vector<Nodo*> G;

    ifstream in("input.txt");
    in >> N >> M;

    ofstream out("output.txt");

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

    pair<vector<int>*, int> paio = checkConn(G);
    pair<int, vector<int>> second_pair = position(G, paio);

    out << second_pair.first << endl;

    for (int i = 0; i < second_pair.second.size(); i++) {
        if (second_pair.second.at(i) != -1) {
            out << second_pair.second.at(i) << " ";
        }
    }
}

pair<int, vector<int>> position(vector<Nodo*>& G, pair<vector<int>*, int> pair) {
    vector<int>* id = pair.first;
    int counter = pair.second;

    // vector<bool> needs_vice;
    vector<set<int>> connections;
    vector<int> positions;
    connections.resize(counter + 1);
    positions.resize(counter + 1);
    //cout << endl
    //   << counter << endl;
    //needs_vice.resize(counter);

    for (int i = 0; i < G.size(); i++) {
        int expected_index = id->at(i);

        for (int j = 0; j < G.at(i)->vic.size(); j++) {
            int connecting_index = id->at(G.at(i)->vic.at(j));
            if (connecting_index == 0 && connecting_index != expected_index) {
                connections.at(expected_index).insert(G.at(i)->vic.at(j));
                positions.at(expected_index) = i;
            }
        }
    }

    int sec_counter = counter + 1;
    for (int i = 0; i < connections.size(); i++) {
        if (connections.at(i).size() != 1) {
            sec_counter--;
            positions.at(i) = -1;
        }
    }
    /*
    for (int i = 0; i < connections.size(); i++) {
        cout << i << ": ";
        for (int a : connections.at(i)) {
            cout << a << " ";
        }
        cout << " - suggested position: " << positions.at(i) << endl;
    }*/

    return make_pair(sec_counter, positions);
}

pair<vector<int>*, int> checkConn(vector<Nodo*>& G) {
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
        if (!skippable.at(i)) { // ottimizzare trasmettendo direttamente skippable
            G.at(i)->skip = true;
        }
        //cout << skippable.at(i) << " ";
    }

    pair<vector<int>*, int> pair = cc_id(G);
    vector<int>* id = pair.first;

    for (int i = 0; i < id->size(); i++) {
        G.at(i)->componente = id->at(i);
        //  cout << id->at(i) << " ";
    }

    return pair;
}

pair<vector<int>*, int> cc_id(vector<Nodo*>& G) {
    cout << " a";
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

    return make_pair(id, counter);
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