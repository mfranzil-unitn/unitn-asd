#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <vector>

using namespace std;

int C, S;
struct Soldato {
    int x;  //Posizione in un dato momento
    int y;
    int id;  //Value del nodo, concettualmente.
};

struct Componente {
    bool visited;  //Se ho o meno visitato la componente (consegnata)
    int x;
    int y;
    int id;
};

struct Target {  //Target => x,y e value associato (C+S)
    int x;
    int y;
    int id;
};

using namespace std;
#define INF numeric_limits<int>::max()

typedef pair<int, int> int_int;
vector<Soldato> soldiers;       //VETTORE DEI SOLDATI x,y e id
vector<Componente> components;  //VETTORE DELLE COMPONENTI
Target target;

int manhatthan(int x, int x1, int y, int y1) {  //Calcolo distanze
    return abs(x - x1) + abs(y - y1);
}

class Graph {
    int V;
    vector<list<pair<int, int> > > adj;

   public:
    Graph(int V);  // Constructor

    void addEdge(int u, int v, int w);
    void updateEdge(int u);  //Ripulisce lista adiacenza del nodo dato.
    int shortestPath(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj.at(u).push_back(make_pair(v, w));
    //adj.at(v).push_back(make_pair(u, w));
}

void Graph::updateEdge(int u) {
    adj.at(u).clear();
    //adj.at(v).push_back(make_pair(u, w));
}

//pair<int,int> Graph::shortestPath(int src)
int Graph::shortestPath(int src) {
    priority_queue<int_int, vector<int_int>, greater<int_int> > pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist.at(src) = 0;
    //pair<int,int> res;
    int res;
    int last_c;
    int last_weight = 0;
    int d = -1;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        list<pair<int, int> >::iterator i;
        for (i = adj.at(u).begin(); i != adj.at(u).end(); ++i) {
            int v = (*i).first;
            int weight;
            weight = (*i).second;
            if (!components.at(v).visited && (v < C)) {  //Se già non ho messo a posto la compomente. (v < C) altrimenti non è una componente.
                if (dist.at(v) > dist.at(u) + weight) {
                    dist.at(v) = dist.at(u) + weight;
                    pq.push(make_pair(dist.at(v), v));
                    if (v == target.id) {
                        if (d == dist.at(v)) {           //Se già ero arrivato in d con questa distanza.
                            if (last_weight < weight) {  //Dijsktra che controlla che l'ultimo peso del cammino minimo scelto sia il più alto possibile
                                last_weight = weight;
                                last_c = u;
                            }
                        } else {  //Altrimenti aggiorno distanza, peso e last componente.
                            d = dist.at(v);
                            last_weight = weight;
                            last_c = u;
                        }
                        cout << "Distanza: " << d << endl;
                        res = d;
                    }
                }
            }
        }
        components.at(last_c).visited = true;  //Componente è stata visitata.
    }

    return res;
}

/*
 * Idea:
 * Prima iterazione fa Dijkstra e ritorna il path minimo con seconda parte di cammino (distanza componente-target) minima.
 * A questo punto aggiorno le adjlist del soldato utilizzato come se il soldato avesse x e y del target.
 * Riapplico lo stesso principio, tengo la somma. => Dovrei avere volta per volta il cammino minimo possibile, considerando anche i
 * soldati nella posizione Target.
 * Dimmi tu... Se riesci a trovare l'errore
 */

int main() {
    ifstream in("input.txt");
    in >> C >> S;
    int x, y;

    components.resize(C);
    soldiers.resize(S);

    for (int i = 0; i < C; i++) {
        in >> x >> y;
        components.at(i).x = x;
        components.at(i).y = y;
        components.at(i).id = i;
        components.at(i).visited = false;
    }
    for (int i = 0; i < S; i++) {
        soldiers.at(i - C).x = x;
        soldiers.at(i - C).y = y;
        soldiers.at(i - C).id = i;
    }

    in >> target.x >> target.y;
    target.id = C + S;

    Graph g = Graph(C + S + 1);
    for (int i = 0; i < components.size(); i++) {
        for (int j = 0; j < soldiers.size(); j++) {
            g.addEdge(soldiers.at(j).id, components.at(i).id, manhatthan(components.at(i).x, soldiers.at(j).x, components.at(i).y, soldiers.at(j).y));
        }
        g.addEdge(components.at(i).id, target.id, manhatthan(components.at(i).x, target.x, components.at(i).y, target.y));
    }

    int minimun = INF;
    int last_id = -1;
    int dist;
    int index = -10;
    int component;
    int sum = 0;
    //pair<int,int> res;
    int res;
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < S; i++) {
            if (i == index) {
                g.addEdge(soldiers.at(i).id, components.at(j).id, manhatthan(components.at(j).x, soldiers.at(i).x, components.at(j).y, soldiers.at(i).y));
                //Se = ad index ha lista di adiacenza vuota => Aggiungo lati.
            }
            res = (g.shortestPath(soldiers.at(i).id));
            dist = res;
            //component = res.second;
            minimun = min(minimun, dist);  //Prendo il cammino minimo
            if (minimun == dist) {
                last_id = soldiers.at(i).id;  //Se l'ho aggiornato salvo id
            }
        }
        index = last_id - C;              //Index di soldiers Sarà l'ultimo id del soldier - le C componenti
        soldiers.at(index).x = target.x;  //Aggiorno coordinate
        soldiers.at(index).y = target.y;
        g.updateEdge(soldiers.at(index).id);  //Ripulisco lista
        sum += minimun;                       //Aggiorno somma.
    }

    cout << sum;
    return 0;
}
