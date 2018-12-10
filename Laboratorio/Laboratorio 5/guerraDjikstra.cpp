#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <set>
#include <vector>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
using namespace std;

int C, S;

struct Componente {
    int x;
    int y;
    int id;
};

struct Target {  //Target => x,y e value associato (C+S)
    int x;
    int y;
    int id;
};

#define INF numeric_limits<int>::max()

typedef pair<int, int> int_int;
vector<Componente> soldiers;    //VETTORE DEI SOLDATI x,y e id
vector<Componente> components;  //VETTORE DELLE COMPONENTI
Target target;
set<int> vis_components;  //Id con componenti visitati
int last_c = -1;

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
    pair<int, int> shortestPath(int src, int last_calc_weight, int previous_dist);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, int w) {
    adj.at(u).push_back(make_pair(v, w));
    //cout << "Da " << u << " A " << v << " Con Peso: " << w << endl;
}

void Graph::updateEdge(int u) {
    adj.at(u).clear();
    //cout << "UPDATE "
    // << "di: " << u << endl;
}

pair<int, int> Graph::shortestPath(int src, int last_calc_weight, int previous_dist) {
    priority_queue<int_int, vector<int_int>, greater<int_int> > pq;
    vector<int> dist;
    dist.resize(V);
    for (int i = 0; i < V; i++) {
        dist.at(i) = INF;
    }
    pq.push(make_pair(src, 0));
    dist.at(src) = 0;
    int res = 0;
    int last_weight = 0;
    int d = INF;
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        list<pair<int, int> >::iterator i;
        for (i = adj.at(u).begin(); i != adj.at(u).end(); ++i) {
            int v = (*i).first;
            int weight;
            weight = (*i).second;
            ////cout << "V: " << v << endl;
            if (!vis_components.count(v)) {  //Se non è già stata consegnata
                if (dist.at(v) > dist.at(u) + weight) {
                    dist.at(v) = dist.at(u) + weight;
                    pq.push(make_pair(v, dist.at(v)));
                    if (v == target.id) {
                        //cout << "dist.at(" << v << "): " << dist.at(v) << " d: " << d << endl;
                        if (d == dist.at(v)) {  //Se già ero arrivato in d con questa distanza.
                            last_weight = weight;
                            if (d < previous_dist || (d == previous_dist && last_weight > last_calc_weight)) {
                                last_c = u;
                            }
                        } else {  //Altrimenti aggiorno distanza, peso e last componente.
                            //cout << "IN ELSE" << endl;
                            d = dist.at(v);
                            //cout << "d è diventata: " << d << endl;
                            last_weight = weight;
                            if (d < previous_dist || (d == previous_dist && last_weight > last_calc_weight)) {
                                last_c = u;
                            }
                        }
                    }
                }
            }
        }
    }

    res = d;
    ////cout << "RES " << res << endl;
    return make_pair(res, last_weight);
}

/*
 * Idea:
 * Prima iterazione fa Dijkstra e ritorna il path minimo con seconda parte di cammino (distanza componente-target) minima.
 * A questo punto aggiorno le adjlist del soldato utilizzato come se il soldato avesse x e y del target.
 * Riapplico lo stesso principio, tengo la somma. => Dovrei avere volta per volta il cammino minimo possibile, considerando anche i
 * soldati nella posizione Target.
 *
 * Tenere conto:
 *              last_cur => Aggiornare a dovere la componente già visitata, deve essere scelta dopo la visione di tutti i soldier
 *              weight => Tenere il percorso minore come ultimo pezzo, disponibile tra quelli dei soldier.
 *              
 *
 */

int main() {
    ifstream in("input.txt");
    in >> C >> S;
    int x, y;

    components.resize(C);
    soldiers.resize(S);

    for (int i = 0; i < C + S; i++) {
        in >> x >> y;
        if (i < C) {
            components[i].x = x;
            components[i].y = y;
            components[i].id = i;
        } else {
            soldiers[i - C].x = x;
            soldiers[i - C].y = y;
            soldiers[i - C].id = i;
        }
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

    int minimun;
    int last_id = -1;
    int dist;
    int index = -10;
    int sum = 0;
    pair<int, int> res;
    int this_last_weight;

    for (int j = 0; j < C; j++) {
        int last_weight = -1;
        minimun = INF;
        //cout << "Iterazione: " << j << endl;
        for (int i = 0; i < S; i++) {
            //cout << "SOLDIER: " << soldiers.at(i).id << endl;
            if (i == index && !vis_components.count(j)) {  //Se l'ho già visitata faccio a meno di riaggiungerla.
                if (target.x == soldiers.at(i).x && target.y == soldiers.at(i).y) {
                    //cout << "il SOLDATO: " << soldiers.at(i).id << " è arrivato a destinazione YOYOYOYO" << endl;
                }
                g.addEdge(soldiers.at(i).id, components.at(j).id, manhatthan(components.at(j).x, soldiers.at(i).x, components.at(j).y, soldiers.at(i).y));
            }
            res = g.shortestPath(soldiers.at(i).id, last_weight, minimun);
            dist = res.first;
            this_last_weight = res.second;
            minimun = min(minimun, dist);                             //Prendo il cammino minimo
            if (minimun == dist && this_last_weight > last_weight) {  //Devo controllare che sia la possibilità con peso minimo al secondo step.
                last_id = soldiers.at(i).id;                          //Se l'ho aggiornato salvo id
                last_weight = this_last_weight;
            }
        }
        //cout << "Componente: " << last_c << " Consegnata" << endl;
        vis_components.insert(last_c);
        index = last_id - C;              //Index di soldiers Sarà l'ultimo id del soldier - le C componenti
        soldiers.at(index).x = target.x;  //Aggiorno coordinate
        soldiers.at(index).y = target.y;
        g.updateEdge(soldiers.at(index).id);  //Ripulisco lista
        //cout << endl
        //       << "Minimum " << minimun << endl
        // << endl;
        sum += minimun;  //Aggiorno somma.
        if (sum < 0) {
            cout << "ERRORE" << endl;
            while (-2 < 0) {
            }
        }
    }

    //cout << "SUM " << sum << endl;
    return 0;
}
