#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

struct nodo {
    vector<int> adj;
    bool visited;
    bool fired;
};

vector<nodo> G;
vector<int> s;
set<int> dimCicli;
vector<vector<int>> cicli;
set<vector<int>> nodupl;

int MCD(int a, int b);
int MCDdimCicli();               //Calcola i mcd tra tutte le dim dei cicli
void searchCycle(int u, int p);  //Individua le dimensioni dei cicli
int searchInStack(int v);        //Controlla se nodo è nello stack
void salvaCiclo(int pos);
void gliIntrovabili(vector<int> a, vector<int> b);
void mettiPokemon(int** posizionamentoPokemon, vector<int> ciclo, int mcd);

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N, M;
    in >> N >> M;
    int** posizionamentoPokemon = new int*[N];

    for (int i = 0; i < N; i++)
        posizionamentoPokemon[i] = new int[N];
    G.resize(N);

    for (int i = 0; i < M; i++) {
        int from, to;
        in >> from >> to;
        G[from].adj.push_back(to);

        G[to].adj.push_back(from);
        G[from].fired = false;
        G[to].fired = false;

        posizionamentoPokemon[from][to] = 0;
        posizionamentoPokemon[to][from] = 0;
    }

    for (int i = 0; i < N; i++)
        G[i].visited = false;

    for (int i = 0; i < N; i++)
        if (!G[i].visited) {
            s.clear();
            searchCycle(i, -1);
        }
    int mcd;

    for (int i = 0; i < cicli.size(); i++)
        for (int j = i + 1; j < cicli.size(); j++) {
            cicli[i].push_back(cicli[i].front());
            cicli[j].push_back(cicli[j].front());
            gliIntrovabili(cicli[i], cicli[j]);
            cicli[i].pop_back();
            cicli[j].pop_back();
        }

    mcd = MCDdimCicli();
    out << mcd << endl;

    //procedura per la stampa dei pokemon negli archi
    for (int i = 0; i < cicli.size(); i++) {
        cicli[i].push_back(cicli[i].front());
        mettiPokemon(posizionamentoPokemon, cicli[i], mcd);
        cicli[i].pop_back();
    }
    for (int i = 0; i < N; i++)
        for (int j : G[i].adj)
            if (i < j)
                out << posizionamentoPokemon[i][j] << endl;
    return 0;
}

void mettiPokemon(int** posizionamentoPokemon, vector<int> ciclo, int mcd) {
    int val = posizionamentoPokemon[ciclo[0]][ciclo[1]];  // vede da che punto deve partire con il posizionamento Pokemon
    for (int i = 0; i < ciclo.size() - 1; i++) {
        posizionamentoPokemon[ciclo[i]][ciclo[i + 1]] = val;  // lo faccio due volte perche non ho la certezza che i valori all'interno del ciclo siano nell'ordine giusto soprattutto l'ultimo
        posizionamentoPokemon[ciclo[i + 1]][ciclo[i]] = val;
        val = (val + 1) % mcd;
    }
}

int MCDdimCicli() {
    int mcd = *dimCicli.begin();
    for (set<int>::iterator i = dimCicli.begin(); i != dimCicli.end(); i++)
        mcd = MCD(mcd, *i);
    return mcd;
}

int MCD(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

//Da chiamare per ogni cc
void searchCycle(int u, int p) {
    int pos;
    s.push_back(u);
    G[u].visited = true;
    for (int v : G[u].adj)
        if (!G[v].fired)
            if (v != s.back()) {
                pos = searchInStack(v);
                if (pos != -1) {  //è nello stack
                    if (s.size() - pos > 2) {
                        dimCicli.insert(s.size() - pos);
                        salvaCiclo(pos);
                    }
                } else
                    searchCycle(v, u);
            }
    G[u].fired = true;
    s.pop_back();  //Eventualmente salvare il ciclo
}

int searchInStack(int v) {
    int count = 0;
    for (int i : s) {
        if (i == v)
            return count;
        count++;
    }
    return -1;
}

void salvaCiclo(int pos) {
    int cont = 0;
    vector<int> tmp;
    vector<int> tmp2;
    for (int i = pos; i < s.size(); i++) {
        tmp.push_back(s[i]);
        tmp2.push_back(s[i]);
    }
    sort(tmp2.begin(), tmp2.end());
    if (nodupl.find(tmp2) == nodupl.end()) {
        cicli.push_back(tmp);
        nodupl.insert(tmp2);
    }
}

void gliIntrovabili(vector<int> a, vector<int> b) {
    int count = 0;
    bool check = false;
    set<int> lati;

    for (int i = 0; i + 1 < a.size(); i++)
        for (int j = 0; j + 1 < b.size(); j++)
            if ((a[i] == b[j] && a[i + 1] == b[j + 1]) || (a[i + 1] == b[j] && a[i] == b[j + 1])) {
                count++;
                lati.insert(a[j]);
                lati.insert(b[i]);
                lati.insert(a[j + 1]);
                lati.insert(b[i + 1]);
                check = true;
            }
    if (check) {
        int tmp;
        if (2 * count == lati.size())
            tmp = a.size() + b.size() - 2 - (count);
        else
            tmp = a.size() + b.size() - 2 - (2 * (count));
        dimCicli.insert(tmp);
    }
}
