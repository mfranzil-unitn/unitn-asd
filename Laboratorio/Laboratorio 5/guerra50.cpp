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
void marca_colonne();
void minpath();
void inverti_primi_stelle();
void trova_minimi_2();
void trova_zeri(int& riga, int& colonna);
bool ha_stella(int riga);
void trova_stelle_riga(int riga, int& col);

void trova_stelle_colonna(int c, int& r);
void trova_primo_riga(int r, int& c);
void cammino_aumentante();
void cancella_primi();

void trova_piccolo(int& min);

#define INF INT32_MAX

ifstream in("input.txt");
ofstream out("output.txt");

int size_s;
int path_row_0;
int path_col_0;
int path_count;

int central_soldier = -1;

vector<Component*> components;
vector<Soldier*> soldiers;
pair<int, int> target;

vector<vector<int>> valori;  // matrice delle distanze (righe: componenti, colonne: soldati + centro)
vector<int> minimi_righe;    // valore minimo di ogni riga
vector<int> minimi_colonne;  // valore minimo di ogni colonna

vector<vector<int>> maschera;  // maschera per la selezione
vector<vector<int>> path;

set<int> chosen;  // soldati già assegnati

set<int> righe_marcate;
set<int> colonne_marcate;

int C, S;

int main() {
    srand(time(0));
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
        for (int i = 0; i < C; i++) {
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }

        out << solvealtri() << endl;
        for (int i = 0; i < C; i++) {
            if (components.at(i)->soldier >= S) {
                out << central_soldier << endl;
            } else {
                out << components.at(i)->soldier << endl;
            }
        }
    }
}

int solvealtri() {
    int sum = 0;
    int massimo = INT32_MIN;

    maschera.resize(soldiers.size() - 1);
    valori.resize(soldiers.size() - 1);  // espando valori per accomodare le righe delle componenti

    path.resize(2 * soldiers.size());
    for (int k = 0; k < path.size(); k++) {
        path.at(k).resize(2);
    }

    for (int i = 0; i < components.size(); i++) {
        valori.at(i).resize(soldiers.size() - 1);
        maschera.at(i).resize(soldiers.size() - 1);
        minimi_righe.push_back(INF);  // setto il minimo a INF per far funzionare min() - servirà per il passo successivo

        for (int j = 0; j < soldiers.size() - 1; j++) {
            int soldier_dist = manhattan(soldiers.at(j)->coord, components.at(i)->coord);  // manhattan calcola in automatico la distanza soldato-componente-centro
            valori.at(i).at(j) = soldier_dist;
            // prima componente poi soldato
            massimo = max(soldier_dist, massimo);
            minimi_righe.at(i) = min(minimi_righe.at(i), soldier_dist);
        }
    }
    // dummy row
    for (int i = components.size(); i < soldiers.size() - 1; i++) {
        valori.at(i).resize(soldiers.size());
        maschera.at(i).resize(soldiers.size());
        minimi_righe.push_back(massimo);

        for (int j = 0; j < soldiers.size(); j++) {
            valori.at(i).at(j) = massimo;
        }
    }

    size_s = valori.size();
    /*
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            cout << valori.at(i).at(j) << " ";
        }
        cout << endl;
    }

    cout.flush();
*/
    // ciclo per sottrarre il minimo a ogni riga
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            valori.at(i).at(j) -= minimi_righe.at(i);
        }
    }

    for (int i = 0; i < size_s; i++) {
        minimi_colonne.push_back(INF);
    }/*
    // ciclo per calcolare i minimi della colonna
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            minimi_colonne.at(j) = min(minimi_colonne.at(j), valori.at(i).at(j));
        }
    }

    // ciclo per sottrarre il mimimo a ogni colonna
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            valori.at(i).at(j) -= minimi_colonne.at(j);
        }
    }*/

    // creazione della maschera degli zeri
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            if (valori.at(i).at(j) == 0 && !righe_marcate.count(i) && !colonne_marcate.count(j)) {
                maschera.at(i).at(j) = 1;
                righe_marcate.insert(i);
                colonne_marcate.insert(j);
            }
        }
    }

    righe_marcate.clear();
    colonne_marcate.clear();
    /*
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            cout << maschera.at(i).at(j) << " ";
        }
        cout << endl;
    }*/

//    cout.flush();

    marca_colonne();

    for (int i = 0; i < components.size(); i++) {
        for (int j = 0; j < size_s; j++) {
            if (maschera.at(i).at(j) == 1) {
                if (central_soldier == -1 && j < S) {
                    central_soldier = j;
                }
                int part = manhattan(soldiers.at(j)->coord, components.at(i)->coord);
                sum += part;
                components.at(i)->value = part;
                components.at(i)->soldier = j;
            }
        }
    }

    return sum;
}

void marca_colonne() {
  //  cout << "Entering 3" << size_s << endl;
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
          //  cout << maschera.at(i).at(j) << " ";
            if (maschera.at(i).at(j) == 1) {
                colonne_marcate.insert(j);
            }
        }
        //cout << endl;
    }

   // cout << colonne_marcate.size() << endl;
  //  cout.flush();

    if (colonne_marcate.size() >= size_s || righe_marcate.size() >= size_s) {
        return;
    } else {
        minpath();
    }
}

void minpath() {
   // cout << "Entering 4" << endl;
    int colonna = -1;
    int riga = -1;
    bool finito = false;
    int next_mode;

    while (!finito) {
      //  cout << riga << " " << colonna << endl;

        trova_zeri(riga, colonna);

        if (riga == -1) {
            finito = true;
            next_mode = 6;
        } else {
            maschera.at(riga).at(colonna) = 2;
            if (ha_stella(riga)) {
                trova_stelle_riga(riga, colonna);
                righe_marcate.insert(riga);
                colonne_marcate.erase(colonna);
            } else {
                finito = true;
                next_mode = 5;
                path_row_0 = riga;
                path_col_0 = colonna;
            }
        }
    }

    switch (next_mode) {
        case 5:
            inverti_primi_stelle();
            break;
        case 6:
            trova_minimi_2();
            break;
    }
}

void inverti_primi_stelle() {
  //  cout << "Entering 5" << endl;

    bool finito = false;
    int r = -1;
    int c = -1;

    path_count = 1;
    path.at(path_count - 1).at(0) = path_row_0;
    path.at(path_count - 1).at(1) = path_col_0;

    while (!finito) {
       // cout << "Quasi finito.. (" << path.at(path_count - 1).at(1) << ") ";
      //  cout.flush();
        trova_stelle_colonna(path.at(path_count - 1).at(1), r);
     //   cout << "...esco da tSC...";
        if (r > -1) {
          //  cout << "...entro in r > -1...";

            path_count++;
            path.at(path_count - 1).at(0) = r;
            path.at(path_count - 1).at(1) = path.at(path_count - 2).at(1);
        } else {
            finito = true;
        }

        if (!finito) {
          //  cout << "...entro in !finito...";
            trova_primo_riga(path.at(path_count - 1).at(0), c);
            path_count++;
            path.at(path_count - 1).at(0) = path.at(path_count - 2).at(0);
            path.at(path_count - 1).at(1) = c;
        }
      //  cout << endl;
    }
    cammino_aumentante();
    righe_marcate.clear();
    colonne_marcate.clear();
    cancella_primi();
    marca_colonne();
}

void trova_stelle_colonna(int c, int& r) {
    r = -1;
    for (int i = 0; i < size_s; i++) {
        if (maschera.at(i).at(c) == 1) {
            r = i;
        }
    }
}

void trova_primo_riga(int r, int& c) {
    for (int j = 0; j < size_s; j++) {
        if (maschera.at(r).at(j) == 2) {
            c = j;
        }
    }
}

void cammino_aumentante() {
    for (int i = 0; i < path_count; i++) {
        if (maschera.at(path.at(i).at(0)).at(path.at(i).at(1)) == 1) {
            maschera.at(path.at(i).at(0)).at(path.at(i).at(1)) = 0;
        } else {
            maschera.at(path.at(i).at(0)).at(path.at(i).at(1)) = 1;
        }
    }
}

void cancella_primi() {
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            if (maschera.at(i).at(j) == 2) {
                maschera.at(i).at(j) = 0;
            }
        }
    }
}

void trova_piccolo(int& min) {
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            if (!righe_marcate.count(i) && !colonne_marcate.count(j) && min > valori.at(i).at(j)) {
                min = valori.at(i).at(j);
            }
        }
    }
}

void trova_minimi_2() {
   // cout << "Entering 6" << endl;
    int min = INF;
    trova_piccolo(min);

    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            if (righe_marcate.count(i)) {
                valori.at(i).at(j) += min;
            }
            if (!colonne_marcate.count(j)) {
                valori.at(i).at(j) -= min;
            }
        }
    }
    minpath();
}

void trova_zeri(int& riga, int& colonna) {
    int r = 0;
    int c;
    bool finito = false;
    riga = -1;
    colonna = -1;

    while (!finito) {
        c = 0;
        while (true) {
            if (valori.at(r).at(c) == 0 && !righe_marcate.count(r) && !colonne_marcate.count(c)) {
                riga = r;
                colonna = c;
                finito = true;
            }
            c += 1;
            if (c >= size_s || finito) {
                break;
            }
        }
        r += 1;
        if (r >= size_s) {
            finito = true;
        }
    }
}

bool ha_stella(int riga) {
    bool res = false;
    for (int j = 0; j < size_s; j++) {
        if (maschera.at(riga).at(j) == 1) {
            res = true;
        }
    }
    return res;
}

void trova_stelle_riga(int riga, int& col) {
    col = -1;
    for (int j = 0; j < size_s; j++) {
        if (maschera.at(riga).at(j) == 1) {
            col = j;
        }
    }
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
    return abs(soldier.first - component.first) + abs(soldier.second - component.second) + abs(target.first - component.first) + abs(target.second - component.second);
}