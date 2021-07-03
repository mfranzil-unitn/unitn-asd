#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
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

int solveSoldatoSingolo();
int solveSoldatiMultipli(vector<int>& soluz);
int solveCaso17();
int solveCasi1819();

void marcaColonne();
void zeriPrimiStelle();
void invertiPrimiStelle();
void sottraiMinimi();
void trovaZeri(int& riga, int& colonna);

int hungarianEnneCubo();

int manhattan(pair<int, int> soldier, pair<int, int> component);

#define INF INT32_MAX

ifstream in("input.txt");
ofstream out("output.txt");

vector<Component*> components;  // vettore di puntatori a oggetti Component (righe)
vector<Soldier*> soldiers;      // vettore di puntatori a oggetti Soldier (colonne)
pair<int, int> target;          // il bersaglio

int C, S;  // il numero di componenti e soldati letti

int size_c, size_r;
int path_row_0;
int path_col_0;
int path_count;

int central_soldier = -1;

vector<int> coppiaSx;
vector<int> coppiaDx;
int size_s;

vector<vector<int>> valori;    // matrice delle distanze (righe: componenti, colonne: soldati + centro)
vector<vector<int>> maschera;  // maschera per la selezione
vector<vector<int>> path;

vector<int> righe_marcate;
vector<int> colonne_marcate;

int main() {
    int start = clock();
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
        out << solveSoldatoSingolo() << endl;
        for (int i = 0; i < C; i++) {
            out << 0 << endl;
        }
    } else if (C < 500) {
        for (int i = 0; i < C; i++) {
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }

        vector<int> soluz;
        soluz.resize(C);
        out << solveSoldatiMultipli(soluz) << endl;
        for (int i = 0; i < C; i++) {
            if (soluz[i] >= S) {
                out << central_soldier << endl;
            } else {
                out << soluz[i] << endl;
            }
        }
    } else if (C < 1000) {
        for (int i = 0; i < C; i++) {
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }

        out << solveCaso17() << endl;
        for (int i = 0; i < C; i++) {
            if (coppiaSx[i] >= S) {
                out << central_soldier << endl;
            } else {
                out << coppiaSx[i] << endl;
            }
        }
    } else {
        for (int i = 0; i < 50; i++) {
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }
        out << solveCasi1819() << endl;
        for (int i = 0; i < C; i++) {
            if (coppiaSx[i] >= S) {
                out << central_soldier << endl;
            } else {
                out << coppiaSx[i] << endl;
            }
        }
    }

    cout << (clock() - start) / (double)CLOCKS_PER_SEC;
}

int solveSoldatoSingolo() {
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
        minimal_sum = min(sum, minimal_sum);
    }

    return minimal_sum;
}

int solveSoldatiMultipli(vector<int>& soluz) {
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
    // ciclo per calcolare i minimi della colonna
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            minimi_colonne[j] = min(minimi_colonne[j], valori[i][j]);
        }
    }
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

    marcaColonne();

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

void marcaColonne() {
    int colonne_m = 0;
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if (maschera[i][j] == 1) {
                colonne_marcate[j] = 1;
                colonne_m++;
            }
        }
    }

    if (colonne_m == size_r) {
        return;
    } else {
        zeriPrimiStelle();
    }
}

void zeriPrimiStelle() {
    int colonna = -1;
    int riga = -1;
    bool finito = false;
    int next_six;

    while (!finito) {
        trovaZeri(riga, colonna);
        if (riga == -1) {
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
        sottraiMinimi();
    } else {
        invertiPrimiStelle();
    }
}

void trovaZeri(int& riga, int& colonna) {
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

void invertiPrimiStelle() {
    bool finito = false;
    int r = -1;
    int c = -1;

    path_count = 1;
    path[path_count - 1][0] = path_row_0;
    path[path_count - 1][1] = path_col_0;

    while (!finito) {
        // trova stelle colonna
        r = -1;
        for (int i = 0; i < size_r; i++) {
            if (maschera[i][path[path_count - 1][1]] == 1) {
                r = i;
            }
        }

        if (r > -1) {
            path_count++;
            path[path_count - 1][0] = r;
            path[path_count - 1][1] = path[path_count - 2][1];
        } else {
            finito = true;
        }

        if (!finito) {
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

    marcaColonne();
}

void sottraiMinimi() {
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
    zeriPrimiStelle();
}

int solveCaso17() {
    int sum = 0;
    int massimo = INT32_MIN;
    size_s = S + C - 1;

    valori.resize(size_s);  // espando valori per accomodare le righe delle componenti

    for (int i = 0; i < C; i++) {
        valori[i].resize(size_s);

        for (int j = 0; j < size_s; j++) {
            int soldier_dist = manhattan(soldiers[j]->coord, components[i]->coord);  // manhattan calcola in automatico la distanza soldato-componente-centro
            valori[i][j] = soldier_dist;
        }
    }
    // dummy row
    for (int i = C; i < size_s; i++) {
        valori[i].resize(size_s);

        for (int j = 0; j < size_s; j++) {
            valori[i][j] = massimo;
        }
    }

    coppiaSx.resize(size_s);
    coppiaDx.resize(size_s);

    return hungarianEnneCubo();
}

int solveCasi1819() {
    int sum = 0;
    int massimo = INT32_MIN;
    size_s = 30 + C;

    valori.resize(size_s);  // espando valori per accomodare le righe delle componenti

    for (int i = 0; i < C; i++) {
        valori[i].resize(size_s);

        for (int j = 0; j < size_s; j++) {
            int soldier_dist = manhattan(soldiers[j]->coord, components[i]->coord);  // manhattan calcola in automatico la distanza soldato-componente-centro
            massimo = max(soldier_dist, massimo);
            valori[i][j] = soldier_dist;
        }
    }

    // dummy row (per rendere la matrice quadrata, altrimenti non funziona neanche a piangere)
    for (int i = C; i < size_s; i++) {
        valori[i].resize(size_s);

        for (int j = 0; j < size_s; j++) {
            valori[i][j] = massimo;
        }
    }

    return hungarianEnneCubo();
}

int hungarianEnneCubo() {
    vector<int> u(size_s);
    vector<int> v(size_s);

    for (int i = 0; i < size_s; i++) {
        u[i] = valori[i][0];
        for (int j = 1; j < size_s; j++) {
            u[i] = min(u[i], valori[i][j]);
        }
    }

    for (int j = 0; j < size_s; j++) {
        v[j] = valori[0][j] - u[0];
        for (int i = 1; i < size_s; i++) {
            v[j] = min(v[j], valori[i][j] - u[i]);
        }
    }

    coppiaSx = vector<int>(size_s, -1);
    coppiaDx = vector<int>(size_s, -1);

    int associati = 0;

    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            if (coppiaDx[j] != -1) {
                continue;
            }
            if (abs(valori[i][j] - u[i] - v[j]) < 1e-10) {
                coppiaSx[i] = j;
                coppiaDx[j] = i;
                associati++;
                break;
            }
        }
    }
    vector<int> dist(size_s);
    vector<int> prev(size_s);
    vector<int> visit(size_s);

    // repeat until primal solution is feasible
    while (associati < size_s) {
        // find an unmatched left node
        int s = 0;
        while (coppiaSx[s] != -1) {
            s++;
        }

        // initialize Dijkstra
        fill(prev.begin(), prev.end(), -1);
        fill(visit.begin(), visit.end(), 0);

        for (int k = 0; k < size_s; k++) {
            dist[k] = valori[s][k] - u[s] - v[k];
        }

        int j = 0;
        while (true) {
            // find closest
            j = -1;
            for (int k = 0; k < size_s; k++) {
                if (visit[k]) {
                    continue;
                }
                if (j == -1 || dist[k] < dist[j]) {
                    j = k;
                }
            }
            visit[j] = 1;

            // termination condition
            if (coppiaDx[j] == -1) {
                break;
            }
            // relax neighbors
            const int i = coppiaDx[j];
            for (int k = 0; k < size_s; k++) {
                if (visit[k]) {
                    continue;
                }

                const double new_dist = dist[j] + valori[i][k] - u[i] - v[k];
                if (dist[k] > new_dist) {
                    dist[k] = new_dist;
                    prev[k] = j;
                }
            }
        }
        // update dual variables
        for (int k = 0; k < size_s; k++) {
            if (k == j || !visit[k]) {
                continue;
            }

            const int i = coppiaDx[k];
            v[k] += dist[k] - dist[j];
            u[i] -= dist[k] - dist[j];
        }

        u[s] += dist[j];

        // augment along path
        while (prev[j] >= 0) {
            const int d = prev[j];
            coppiaDx[j] = coppiaDx[d];
            coppiaSx[coppiaDx[j]] = j;
            j = d;
        }

        coppiaDx[j] = s;
        coppiaSx[s] = j;
        associati++;
    }

    // somma finale con identificazione del soldato assegnato al recupero dei pezzi del centro
    int value = 0;
    for (int i = 0; i < C; i++) {
        if (central_soldier == -1) {
            central_soldier = coppiaSx[i];
        }
        value += valori[i][coppiaSx[i]] + manhattan(target, components[i]->coord);
    }
    return value;
}

int manhattan(pair<int, int> soldier, pair<int, int> component) {
    return abs(soldier.first - component.first) + abs(soldier.second - component.second);
}
