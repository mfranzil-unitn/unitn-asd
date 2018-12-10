#include <algorithm>
#include <cstdlib>
#include <ctime>
//#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Component {
    int value;
    pair<int, int> coord;
};

struct Soldier {
    pair<int, int> coord;
};

int solve();

int solvealtri(vector<int>& soluz);
void marca_colonne();
void minpath();
void inverti_primi_stelle();
void trova_minimi();
void trova_zeri(int& riga, int& colonna);

int manhattan(pair<int, int> soldier, pair<int, int> component);

#define INF INT32_MAX

ifstream in("input.txt");
ofstream out("output.txt");

int size_c, size_r;
int path_row_0;
int path_col_0;
int path_count;

int central_soldier = -1;

vector<Component*> components;
vector<Soldier*> soldiers;
pair<int, int> target;

vector<vector<int>> valori;  // matrice delle distanze (righe: componenti, colonne: soldati + centro)

vector<vector<int>> maschera;  // maschera per la selezione
vector<vector<int>> path;

vector<int> righe_marcate;
vector<int> colonne_marcate;

int C, S;

int main() {
    int start = clock();
    srand(time(0));
    in >> C >> S;
    for (int i = 0; i < C; i++) {
        int x, y;
        in >> x >> y;

        Component* tmp = new Component();
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

    if (S == 1) {
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

        vector<int> soluz;
        soluz.resize(C);
        out << solvealtri(soluz) << endl;
        for (int i = 0; i < C; i++) {
            if (soluz[i] >= S) {
                out << central_soldier << endl;
            } else {
                out << soluz[i] << endl;
            }
        }
    }

    cout << endl
         << (clock() - start) / (double)CLOCKS_PER_SEC;
}

int solvealtri(vector<int>& soluz) {
    int sum = 0;
    int massimo = INT32_MIN;
    size_c = S + C - 1;
    size_r = C;

    maschera.resize(size_r);
    valori.resize(size_r);  // espando valori per accomodare le righe delle componenti

    righe_marcate.resize(size_r);
    colonne_marcate.resize(size_c);

    vector<int> minimi_colonne;

    for (int j = 0; j < size_c; j++) {
        minimi_colonne.push_back(INF);
    }

    path.resize(2 * size_r);
    for (int k = 0; k < path.size(); k++) {
        path[k].resize(2);
    }

    for (int i = 0; i < size_r; i++) {
        valori[i].resize(size_c);
        maschera[i].resize(size_c);
        // minimi_righe.push_back(INF);  // setto il minimo a INF per far funzionare min() - servirà per il passo successivo

        for (int j = 0; j < size_c; j++) {
            int soldier_dist = manhattan(soldiers[j]->coord, components[i]->coord);  // manhattan calcola in automatico la distanza soldato-componente-centro
            valori[i][j] = soldier_dist;
            // prima componente poi soldato
            massimo = max(soldier_dist, massimo);
            // minimi_righe[i] = min(minimi_righe[i], soldier_dist);
        }
    }
    /*
    for (int i = 0; i < size_c; i++) {
        for (int j = 0; j < size_c; j++) {
            cout << valori[i][j] << " ";
        }
        cout << endl;
    }

    cout.flush();
*/

    //cout << size_r << "r " << size_c << endl;
    // ciclo per sottrarre il minimo a ogni riga
    /* for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            valori[i][j] -= minimi_righe[i];
        }
    }*/
    // ciclo per calcolare i minimi della colonna
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            minimi_colonne[j] = min(minimi_colonne[j], valori[i][j]);
        }
    }
    /*
    // ciclo per sottrarre il mimimo a ogni colonna
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
           valori[i][j] -= minimi_colonne[j];
        }
    }
*/
    // creazione della maschera degli zeri
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if (valori[i][j] == 0 && !righe_marcate[i] && !colonne_marcate[j]) {
                maschera[i][j] = 1;
                righe_marcate[i] = 1;
                colonne_marcate[j] = 1;
            }
        }
    }

    for (int i = 0; i < size_r; i++) {
        righe_marcate[i] = 0;
    }
    for (int i = 0; i < size_c; i++) {
        colonne_marcate[i] = 0;
    }

    marca_colonne();

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < size_c; j++) {
            if (maschera[i][j] == 1) {
                if (central_soldier == -1 && j < S) {
                    central_soldier = j;
                }
                sum += manhattan(soldiers[j]->coord, components[i]->coord) +
                       manhattan(target, components[i]->coord);
                soluz[i] = j;
            }
        }
    }

    return sum;
}

void marca_colonne() {
    cout << "3(";
    cout.flush();

    int colonne_m = 0;
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            //  cout << maschera[i][j] << " ";
            if (maschera[i][j] == 1) {
                colonne_marcate[j] = 1;
                colonne_m++;
            }
        }
    }
    //cout << colonne_m << ")";
    if (colonne_m == size_r) {
        return;
    } else {
        minpath();
    }
}

void minpath() {
    int colonna = -1;
    int riga = -1;
    bool finito = false;
    int next_six;

    while (!finito) {
        //  cout << "4";
        //cout.flush();
        //  cout << riga << " " << colonna << endl;

        trova_zeri(riga, colonna);

        if (riga == -1) {
            //  cout << "F";
            //   cout.flush();

            finito = true;
            next_six = true;
        } else {
            maschera[riga][colonna] = 2;

            // ha una stella?
            bool ha_stella = false;
            for (int j = 0; j < size_c; j++) {
                if (maschera[riga][j] == 1) {
                    ha_stella = true;
                }
            }

            if (ha_stella) {
                // trova le stelle

                colonna = -1;
                for (int j = 0; j < size_c; j++) {
                    if (maschera[riga][j] == 1) {
                        colonna = j;
                    }
                }

                righe_marcate[riga] = 1;
                colonne_marcate[colonna] = 0;
            } else {
                finito = true;
                next_six = false;
                path_row_0 = riga;
                path_col_0 = colonna;
            }
        }
    }

    if (next_six) {
        trova_minimi();
    } else {
        inverti_primi_stelle();
    }
}

void inverti_primi_stelle() {
    cout << "5";
    cout.flush();

    bool finito = false;
    int r = -1;
    int c = -1;

    path_count = 1;
    path[path_count - 1][0] = path_row_0;
    path[path_count - 1][1] = path_col_0;

    while (!finito) {
        // cout << "Quasi finito.. (" << path[path_count - 1][1] << ") ";
        //  cout.flush();

        // trova stelle colonna
        r = -1;
        for (int i = 0; i < size_r; i++) {
            if (maschera[i][path[path_count - 1][1]] == 1) {
                r = i;
            }
        }

        //   cout << "...esco da tSC...";
        if (r > -1) {
            //  cout << "...entro in r > -1...";

            path_count++;
            path[path_count - 1][0] = r;
            path[path_count - 1][1] = path[path_count - 2][1];
        } else {
            finito = true;
        }

        if (!finito) {
            //  cout << "...entro in !finito...";

            // trova primo riga
            for (int j = 0; j < size_c; j++) {
                if (maschera[path[path_count - 1][0]][j] == 2) {
                    c = j;
                }
            }

            path_count++;
            path[path_count - 1][0] = path[path_count - 2][0];
            path[path_count - 1][1] = c;
        }
        //  cout << endl;
    }

    // cammino aumentante
    for (int i = 0; i < path_count; i++) {
        if (maschera[path[i][0]][path[i][1]] == 1) {
            maschera[path[i][0]][path[i][1]] = 0;
        } else {
            maschera[path[i][0]][path[i][1]] = 1;
        }
    }

    for (int i = 0; i < size_r; i++) {
        righe_marcate[i] = 0;
    }
    for (int i = 0; i < size_c; i++) {
        colonne_marcate[i] = 0;
    }

    // cancella primi
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if (maschera[i][j] == 2) {
                maschera[i][j] = 0;
            }
        }
    }

    marca_colonne();
}

void trova_minimi() {
    cout << "6";
    cout.flush();
    int min = INF;

    // trova piccolo
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if (!righe_marcate[i] && !colonne_marcate[j] && min > valori[i][j]) {
                min = valori[i][j];
            }
        }
    }

    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if (righe_marcate[i]) {
                valori[i][j] += min;
            }
            if (!colonne_marcate[j]) {
                valori[i][j] -= min;
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
            if (valori[r][c] == 0 && !righe_marcate[r] && !colonne_marcate[c]) {
                riga = r;
                colonna = c;
                finito = true;
            }
            c += 1;
            if (c >= size_c || finito) {
                break;
            }
        }
        r += 1;
        if (r >= size_r) {
            finito = true;
        }
    }
}

int solve() {
    vector<int> center_dists;
    center_dists.resize(components.size());
    pair<int, int> shortest = make_pair(INF, INF);

    for (int i = 0; i < components.size(); i++) {
        int center_dist = manhattan(target, components[i]->coord);
        int soldier_dist = manhattan(soldiers[0]->coord, components[i]->coord);

        center_dists[i] = center_dist;
        components[i]->value = soldier_dist;
    }

    int minimal_sum = INF;
    for (int k = 0; k < components.size(); k++) {
        int sum = 0;
        for (int i = 0; i < components.size(); i++) {
            if (i != k) {
                sum += center_dists[i] + manhattan(target, components[i]->coord);
            } else {
                sum += components[i]->value + manhattan(target, components[i]->coord);
            }
        }
        // cout << sum << endl;
        minimal_sum = min(sum, minimal_sum);
    }

    return minimal_sum;
}

int manhattan(pair<int, int> soldier, pair<int, int> component) {
    return abs(soldier.first - component.first) + abs(soldier.second - component.second);
}