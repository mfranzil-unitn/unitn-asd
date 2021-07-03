#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct Component {
    int soldier;
    int index;
    int value;
    pair<int, int> coord;
};

struct Soldier {
    pair<int, int> coord;
};

int solve();
int solvealtri();
int manhattan(pair<int, int> soldier, pair<int, int> component);

vector<Component*> components;
vector<Soldier*> soldiers;
pair<int, int> target;

#define INF INT32_MAX

ifstream in("input.txt");
ofstream out("output.txt");

int main() {
    srand(time(0));
    int C, S;
    in >> C >> S;

    for (int i = 0; i < C; i++) {
        int x, y;
        in >> x >> y;

        Component* tmp = new Component();
        tmp->soldier = INT32_MAX;
        tmp->value = INT32_MAX;
        tmp->index = i;
        tmp->coord = make_pair(x, y);
        components.push_back(tmp);
    }

    for (int i = 0; i < S; i++) {
        int x, y;
        in >> x >> y;

        Soldier* tmp = new Soldier();
        tmp->coord = make_pair(x, y);
        soldiers.push_back(tmp);
    }

    in >> target.first >> target.second;

    if (soldiers.size() == 1) {
        out << solve() << endl;
        for (int i = 0; i < C; i++) {
            out << 0 << endl;
        }
    } else {
        for (int i = 0; i < C - 1; i++) {
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }

        out << solvealtri() << endl;
        for (int i = 0; i < C; i++) {
            if (components.at(i)->soldier >= S) {
                out << 0 << endl;
            } else {
                out << components.at(i)->soldier << endl;
            }
        }
    }
}

int solvealtri() {
    vector<vector<int>> valori;  // matrice delle distanze (righe: componenti, colonne: soldati + centro)
    vector<int> minimi_righe;    // valore minimo di ogni riga
    vector<int> minimi_colonne;  // valore minimo di ogni colonna

    valori.resize(components.size());  // espando valori per accomodare le righe delle componenti

    for (int i = 0; i < components.size(); i++) {
        valori.at(i).resize(soldiers.size());
        minimi_righe.push_back(INF);  // setto il minimo a INF per far funzionare min() - servirà per il passo successivo

        for (int j = 0; j < soldiers.size(); j++) {
            int soldier_dist = manhattan(soldiers.at(j)->coord, components.at(i)->coord);  // manhattan calcola in automatico la distanza soldato-componente-centro
            valori.at(i).at(j) = soldier_dist;                                             // prima componente poi soldato
            minimi_righe.at(i) = min(minimi_righe.at(i), soldier_dist);
        }
    }

    // ciclo per sottrarre il minimo a ogni riga
    for (int i = 0; i < valori.size(); i++) {
        for (int j = 0; j < valori.at(i).size(); j++) {
            valori.at(i).at(j) -= minimi_righe.at(i);
        }
    }

    for (int i = 0; i < valori.at(0).size(); i++) {
        minimi_colonne.push_back(INF);
    }
    // ciclo per calcolare i minimi della colonna
    for (int i = 0; i < valori.size(); i++) {
        for (int j = 0; j < valori.at(0).size(); j++) {
            minimi_colonne.at(j) = min(minimi_colonne.at(j), valori.at(i).at(j));
        }
    }

    // ciclo per sottrarre il mimimo a ogni colonna
    for (int i = 0; i < valori.size(); i++) {
        for (int j = 0; j < valori.at(0).size(); j++) {
            valori.at(i).at(j) -= minimi_colonne.at(j);
        }
    }

    // Assegnamento
    set<int> chosen;  // soldati già assegnati
    int matched = 0;

    for (int i = 0; i < valori.size(); i++) {
        for (int j = 0; j < valori.at(i).size(); j++) {
            if (!chosen.count(j) && valori.at(i).at(j) == 0) {
                matched++;
                components.at(i)->value = manhattan(soldiers.at(j)->coord, components.at(i)->coord);
                chosen.insert(j);
                components.at(i)->soldier = j;
                break;
            }
        }
    }

    set<int> righe_marcate;
    set<int> colonne_marcate;

    set<pair<int, int>> to_be_subtracted;
    set<pair<int, int>> to_be_added;

    while (true) {
        to_be_added.clear();
        to_be_subtracted.clear();

        righe_marcate.clear();
        colonne_marcate.clear();

      //  cout << "Righe da barrare: ";
        for (int i = 0; i < valori.size(); i++) {
            if (components.at(i)->value == INF) {
                righe_marcate.insert(i);
            } else {
               // cout << i << " ";
            }
        }
      //  cout << endl;

        if (0 == righe_marcate.size()) {
            break;
        }

        //cout << "Match: " << matched << " " << (valori.size() - righe_marcate.size()) << endl;

        bool more = true;
        while (more) {
            more = false;
           // cout << "Colonne marcate: ";
            for (int i : righe_marcate) {
                for (int j = 0; j < valori.at(i).size(); j++) {
                    if (!colonne_marcate.count(j) && valori.at(i).at(j) == 0) {
                        more = true;
                        colonne_marcate.insert(j);
                      //  cout << j << " ";
                    }
                }
            }
           // cout << endl;

         //   cout << "Righe marcate: ";
            for (int i = 0; i < valori.size(); i++) {
                for (int j : colonne_marcate) {
                    if (!righe_marcate.count(i) && components.at(i)->soldier == j) {
                        more = true;
                        righe_marcate.insert(i);
                        //cout << i << " ";
                        break;
                    }
                }
            }
         //   cout << endl;
        }

//        cout << "Finished with crossings "
           //  << (colonne_marcate.size() + (valori.size() - righe_marcate.size()))
             //<< "/" << valori.size() << endl;

        for (int i = 0; i < valori.size(); i++) {
            for (int j = 0; j < valori.at(i).size(); j++) {
                if (!colonne_marcate.count(j) && righe_marcate.count(i)) {  // celle non barrate
                    to_be_subtracted.insert(make_pair(i, j));
                } else if (colonne_marcate.count(j) && !righe_marcate.count(i)) {  // celle barrate due volte
                    to_be_added.insert(make_pair(i, j));
                }
            }
        }

        int mini = INF;
        for (pair<int, int> paio : to_be_subtracted) {
            mini = min(mini, valori.at(paio.first).at(paio.second));
            //if (valori.at(paio.first).at(paio.second) == 0)
            //  cout << paio.first << " " << paio.second << ":" << valori.at(paio.first).at(paio.second) << endl;
        }
       // cout << "Mini: " << mini << endl;
        assert(mini != 0);

        //  cout << mini << endl;

        for (pair<int, int> paio : to_be_subtracted) {
            valori.at(paio.first).at(paio.second) -= mini;
        }

        for (pair<int, int> paio : to_be_added) {
            valori.at(paio.first).at(paio.second) += mini;
        }

        matched = 0;
        chosen.clear();
        for (int i = 0; i < valori.size(); i++) {
            components.at(i)->value = INF;
            for (int j = 0; j < valori.at(i).size(); j++) {
                if (!chosen.count(j) && valori.at(i).at(j) == 0) {
                    matched++;
                    components.at(i)->value = manhattan(soldiers.at(j)->coord, components.at(i)->coord);
                    chosen.insert(j);
                    components.at(i)->soldier = j;
                    break;
                }
            }
        }
    }

    assert((colonne_marcate.size() + (valori.size() - righe_marcate.size())) == valori.size());

    chosen.clear();
    for (int i = 0; i < valori.size(); i++) {
        components.at(i)->value = INF;
        for (int j = 0; j < valori.at(i).size(); j++) {
            if (!chosen.count(j) && valori.at(i).at(j) == 0) {
                components.at(i)->value = manhattan(soldiers.at(j)->coord, components.at(i)->coord);
                chosen.insert(j);
                //  cout << " Inserting " << i << "  " << j << " " << components.at(i)->value << endl;
                components.at(i)->soldier = j;
                break;
            }
        }
        // cout << (components.at(i)->value == INF ? "Shout INF" : " ");
    }

    int sum = 0;

    for (int i = 0; i < components.size(); i++) {
        // cout << sum << " ";
        sum += components.at(i)->value;
    }

    return sum;
}

int solve() {
    vector<int> center_dists;
    center_dists.resize(components.size());
    pair<int, int> shortest = make_pair(INF, INF);

    for (int i = 0; i < components.size(); i++) {
        int center_dist = manhattan(target, components.at(i)->coord);
        int soldier_dist = manhattan(soldiers.at(0)->coord, components.at(i)->coord);

        center_dists.at(i) = center_dist;
        components.at(i)->value = soldier_dist;
    }

    int minimal_sum = INF;
    for (int k = 0; k < components.size(); k++) {
        int sum = 0;
        for (int i = 0; i < components.size(); i++) {
            if (i != k) {
                sum += center_dists.at(i);
            } else {
                sum += components.at(i)->value;
            }
        }
        // cout << sum << endl;
        minimal_sum = min(sum, minimal_sum);
    }

    return minimal_sum;
}

int manhattan(pair<int, int> soldier, pair<int, int> component) {
    return abs(soldier.first - component.first) + abs(soldier.second - component.second) +
           abs(component.first - target.first) + abs(component.second - target.second);
}