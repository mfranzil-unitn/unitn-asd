/*
 * Gruppo krikka.
 *
 * Nel tentare di risolvere il progetto abbiamo ottenuto progressivamente diversi algoritmi.
 * L'affetto provato per i suddetti algoritmi ci ha spinto a conservarli.
 * Motivo per il quale il codice risulta essere molto voluminoso.
 *
 * Nel caso il soldato sia solamente uno => Prendiamo la minore possibile tra le combinazioni delle somme. (BruteForce)
 * - Metodo: int soldatoCuoreSolitario()
 *
 * Nel caso le componenti siano < 500 =>
 * L'algoritmo dopo aver aggiunto C-1 soldati posizionati al target (passaggio svolto ancora nel main)
 * chiama una nostra implementazione dell'algoritmo ungherese.
 * Nel farlo abbiamo fatto riferimento a 2 paper:
 * 1. ("Algorithm for the Assignment and Transportation Problems", James Munkres, Journal of the Society For Industrial And Applied Mathematics, 1957)
 * 2. ("An Extension of the Munkres Algorithm for the Assignment Problem to Rectangular Matrices", Franqois Bourgeois and Jean-Claude Lassalle, CERN, Geneva, Switzerland)
 * Il secondo necessario per l'applicazione dell'algoritmo ungherese a matrici rettangolari.
 * - Metodo: int solveMonumentsMen()
 *
 * Nel caso in cui il numero di componenti sia compreso fra 500 e 1000 =>
 * L'algoritmo dopo aver aggiunto C-1 soldati posizionati al target (passaggio svolto ancora nel main) fa un padding della matrice delle distanze
 * così da renderla quadrata.
 * - Method: int solveMontySquad()
 * A questo punto chiamiamo il metodo call_LaszloBiro(). (Descritto successivamente)
 *
 * Nel caso in cui il numero di componenti sia > 1000 =>
 * L'algoritmo dopo aver aggiunto 30 (numero fissato, dedotto a tentativi) soldati posizionati al target (passaggio svolto ancora nel main)
 * fa un padding della matrice delle distanze così da renderla quadrata.
 * - Method: int solveApocalypseNow()
 * A questo punto chiamiamo il metodo call_LaszloBiro(). (Descritto successivamente)
 *
 * Precisazione riguardo al Padding: Dopo aver trovato il massimo fra le somme.
 *                                   Questo valore è assegnato alle righe definite, ci sentiamo di dire offensivamente,
 *                                   Dummy Rows.
 *
 * Dopo aver discusso a ricevimento riguardo come ottenere il punteggio massimo.
 * La dritta è stata di trovare un ottimizzazione per grafi bipariti e augmenting paths.
 *
 * Metodo call_LaszloBiro(): Min cost bipartite matching via shortest augmenting paths
 *                  - 1° (Doppio) Ciclo: Minimo righe
 *                  - 2° (Doppio) Ciclo: Minimo colonne (mentre sottrae minimo righe)
 *                  - Associa il primo zero
 *                  - Applica Dijsktra fino a che non si arriva ad avere il matching su tutte le componenti.
 *
 *   valori[i][j] = Matrice costi
 *   coppiaDx[i] = indice del nodo destro con il quale il nodo i fa coppia
 *   coppiaSx[j] = indice del nodo sinistro con il quale il nodo j fa coppia
 *
 *  Riferimenti:
 *  http://e-maxx.ru/algo/assignment_hungary
 *  https://github.com/t3nsor/codebook/blob/master/bipartite-mincost.cpp
 *
 */

#include <algorithm>
// #include <cmath>
// #include <cstdlib>
#include <ctime>  // (usato per debugging)
#include <fstream>
#include <iostream>  // (usato per debugging)
#include <vector>

using namespace std;

struct Component {
    int value;
    pair<int, int> coord;
};

struct Soldier {
    pair<int, int> coord;
};

int soldatoCuoreSolitario();
int solveMonumentsMen();
int solveMontySquad();
int solveApocalypseNow();

void marcaColonne();
void zeriPrimiStelle();
void invertiPrimiStelle();
void sottraiMinimi();
void trovaZeri(int& riga, int& colonna);

int call_LaszloBiro();

int manhattan(pair<int, int> soldier, pair<int, int> component);

#define INF INT32_MAX

ifstream in("input.txt");
ofstream out("output.txt");

vector<Component*> components;  // vettore di puntatori a oggetti Component (righe)
vector<Soldier*> soldiers;      // vettore di puntatori a oggetti Soldier (colonne)
pair<int, int> target;          // il bersaglio

int C, S;                  // il numero di componenti e soldati letti
int central_soldier = -1;  // il soldato preposto al recupero delle componenti partendo dal centro

int size_c, size_r;  // usati solo per le matrici rettangolari
int size_s;          // usati per matrici quadrate (size_s == size_c)

int path_row_0;  // punto di partenza dell'augmenting path
int path_col_0;
int path_count;  // numero di strade trovate per l'augmenting path

vector<int> coppiaSx;  // liste di accoppiamento per i nodi sinistri/destri (componenti/soldati) (solo algoritmo finale)
vector<int> coppiaDx;

vector<vector<int> > valori;    // matrice delle distanze (righe: componenti, colonne: soldati + centro)
vector<vector<int> > maschera;  // maschera per la selezione
vector<vector<int> > path;

vector<int> righe_marcate;    // vettori usati per barrare righe e colonne. Avrei voluto usare un set
vector<int> colonne_marcate;  // ma il tempo di esecuzione soffriva troppo

int main(int argc, char** argv) {
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
        out << soldatoCuoreSolitario() << endl;
        for (int i = 0; i < C; i++) {
            out << 0 << endl;
        }
    } else if (C < 500) {
        //Aggiunta di C-1 soldati fittizi posizionati al target.

        for (int i = 0; i < C - 1; i++) {
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }

        out << solveMonumentsMen() << endl;

        for (int i = 0; i < C; i++) {
            if (coppiaSx[i] >= S) {
                out << central_soldier << endl;
            } else {
                out << coppiaSx[i] << endl;
            }
        }
    } else if (C < 1000) {
        for (int i = 0; i < C - 1; i++) {
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }

        out << solveMontySquad() << endl;

        // stampa del rapporto
        for (int i = 0; i < C; i++) {
            if (coppiaSx[i] >= S) {
                out << central_soldier << endl;
            } else {
                out << coppiaSx[i] << endl;
            }
        }
    } else {
        //Per velocizzare i tempi di esecuzione, con brutalità e freddezza militare
        //si è scelto di fissare il numero di soldati fittizi posizionati al target a 30.

        for (int i = 0; i < 30; i++) {  //Questo 30 direbbe Lo Cigno, non è altro che: "Un accidenti della storia".
            Soldier* tmp = new Soldier();
            tmp->coord = target;
            soldiers.push_back(tmp);
        }

        out << solveApocalypseNow() << endl;

        // stampa del rapporto
        for (int i = 0; i < C; i++) {
            if (coppiaSx[i] >= S) {
                out << central_soldier << endl;
            } else {
                out << coppiaSx[i] << endl;
            }
        }
    }

    if (argc > 1 && argv[1][0] == 't')
        cout << (clock() - start) / (double)CLOCKS_PER_SEC;
}

int soldatoCuoreSolitario() {
    //Quando sei l'unico soldato mandato in una missione suicida.
    // La "BruteForce" non è una scelta, è un obbligo.

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

int solveMonumentsMen() {
    // Quasi 500 preziosissime opere d'arte andavano recuperate.
    // Tutta la fiducia del generale fu riposta in George Clooney.
    // Il buon GC, lo chiamiamo così, per l'occassione si improvvisò anche regista dell'operazione (e del film).

    int sum = 0;
    size_c = S + C - 1;
    size_r = C;

    // Funzione della maschera: ha la stessa dimensione size_r*size_c, ha 0 in tutti i valori inizalmente.
    // viene settata a 1 quando uno zero viene stellato (aka scelto per la combinazione) o primato (aka compete con
    // uno zero stellato nella stessa riga, ma non è stato scelto)
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
        valori[i].resize(size_c);    //Resize delle righe di valori.
        maschera[i].resize(size_c);  //Resize della maschera.

        for (int j = 0; j < size_c; j++) {
            int soldier_dist = manhattan(soldiers[j]->coord, components[i]->coord);
            valori[i][j] = soldier_dist;
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

    fill(righe_marcate.begin(), righe_marcate.end(), 0);
    fill(colonne_marcate.begin(), colonne_marcate.end(), 0);

    // L'algoritmo effettivo parte da qui
    marcaColonne();

    // Tecnicamente coppiaSx viene usato solo nell'implementazione Dijkstra per i casi > 1000,
    // ma abbiamo deciso di riciclarlo per evitare di scrivere troppe dichiarazioni globali
    coppiaSx.resize(C);

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < size_c; j++) {
            if (maschera[i][j] == 1) {
                // Assegno, se non è già stato fatto, il soldato centrale in modo da
                // poterlo stampare nel rapporto
                if (central_soldier == -1 && j < S) {
                    central_soldier = j;
                }
                sum += manhattan(soldiers[j]->coord, components[i]->coord) +
                       manhattan(target, components[i]->coord);
                coppiaSx[i] = j;
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
    bool sottraiMinimiMode;

    while (!finito) {
        trovaZeri(riga, colonna);
        if (riga == -1) {
            finito = true;
            sottraiMinimiMode = true;
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
                sottraiMinimiMode = false;
                path_row_0 = riga;
                path_col_0 = colonna;
            }
        }
    }

    if (sottraiMinimiMode) {
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

    // svuoto i vettori delle righe marchiate
    fill(righe_marcate.begin(), righe_marcate.end(), 0);
    fill(colonne_marcate.begin(), colonne_marcate.end(), 0);

    // cancello eventuali zeri primi (2) rimasti nella maschera
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

    // trova l'elemento più piccolo delle righe e colonne non marchiate
    for (int i = 0; i < size_r; i++) {
        for (int j = 0; j < size_c; j++) {
            if (!righe_marcate[i] && !colonne_marcate[j] && min > valori[i][j]) {
                min = valori[i][j];
            }
        }
    }

    // sottraggo suddetto valore alle righe marchiate e alle colonne non marchiate
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

int solveMontySquad() {
    // C < 1000. La squadra Monty non ha paura. La squadra Monty non conosce fatica.
    // Meno di 1000 componenti sono uno scherzo, ma abbiamo comunque chiesto l'aiuto di
    // Lorenzo Ghiro, ehm no!.. di Laszlo Biro.

    int massimo = INT32_MIN;
    size_s = C + S - 1;

    valori.resize(size_s);  // espando valori per accomodare le righe delle componenti

    for (int i = 0; i < C; i++) {
        valori[i].resize(size_s);

        for (int j = 0; j < size_s; j++) {
            int soldier_dist = manhattan(soldiers[j]->coord, components[i]->coord);
            massimo = max(soldier_dist, massimo);  // tengo conto del massimo per inserirlo nelle dummy row
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

    return call_LaszloBiro();
}

int solveApocalypseNow() {
    //"Andavo nel posto peggiore del mondo, e ancora non lo sapevo, per settimane e centinaia di miglia su per un fiume
    // che serpeggiava attraverso la guerra come un cavo elettrico con il terminale inserito direttamente dentro Kurtz…"
    // Testimonianza di uno dei soldati... dopo aver letto C.
    // Anche in questo caso ricorriamo all'aiuto di Lorenzo Ghiro, No... maledizione! Di Laszlo Biro

    int massimo = INT32_MIN;
    size_s = C + 30;

    valori.resize(size_s);  // espando valori per accomodare le righe delle componenti

    for (int i = 0; i < C; i++) {
        valori[i].resize(size_s);

        for (int j = 0; j < size_s; j++) {
            int soldier_dist = manhattan(soldiers[j]->coord, components[i]->coord);
            massimo = max(soldier_dist, massimo);  // tengo conto del massimo per inserirlo nelle dummy row
            valori[i][j] = soldier_dist;
        }
    }

    // Dummy Row (per rendere la matrice quadrata, altrimenti non funziona neanche a piangere)
    for (int i = C; i < size_s; i++) {
        valori[i].resize(size_s);

        for (int j = 0; j < size_s; j++) {
            valori[i][j] = massimo;
        }
    }

    return call_LaszloBiro();
}

int call_LaszloBiro() {
    // László József Bíró, ispanizzato in Ladislao José Biro (Budapest, 29 Settembre 1899 – Buenos Aires, 24 Ottobre 1985),
    // è stato un giornalista e inventore UNGHERESE naturalizzato argentino,
    // famoso per aver ideato la penna a sfera che porta il suo nome.
    // Quello che molti non sanno è che egli fu, prima della rottura definitiva avvenuta nel Novembre del 1980,
    // uno dei più fidati consiglieri del gen. Montresor.
    // In sua assenza... Lorenzo Ghiro ha preso il suo posto.
    // Si suppone che uno dei fattori di questa scelta sia la somiglianza, evidente, tra i nomi dei 2.

    vector<int> u(size_s);
    vector<int> v(size_s);

    //Minimo righe
    for (int i = 0; i < size_s; i++) {
        u[i] = valori[i][0];
        for (int j = 1; j < size_s; j++) {
            u[i] = min(u[i], valori[i][j]);
        }
    }

    //Minimo colonne mentre sottrae minimo righe
    for (int j = 0; j < size_s; j++) {
        v[j] = valori[0][j] - u[0];
        for (int i = 1; i < size_s; i++) {
            v[j] = min(v[j], valori[i][j] - u[i]);
        }
    }

    //Inizializzazione vettori
    coppiaSx = vector<int>(size_s, -1);
    coppiaDx = vector<int>(size_s, -1);

    //contatore dei partner
    int associati = 0;
    for (int i = 0; i < size_s; i++) {
        for (int j = 0; j < size_s; j++) {
            if (coppiaDx[j] == -1 && valori[i][j] - u[i] - v[j] == 0) {
                coppiaSx[i] = j;
                coppiaDx[j] = i;
                associati++;
                break;
            }
        }
    }

    //Dichiarazione delle strutture necessarie per l'algoritmo di Dijkstra
    vector<int> dist(size_s);
    vector<int> prev(size_s);
    vector<int> visit(size_s);

    // ripete l'esecuzione di Dijkstra finché non finiscono tutti i nodi (size_s)
    while (associati < size_s) {
        // trova il primo nodo sinistro non associato
        int s = 0;
        while (coppiaSx[s] != -1) {
            s++;
        }

        // inizializza Dijkstra
        fill(prev.begin(), prev.end(), -1);
        fill(visit.begin(), visit.end(), 0);

        for (int k = 0; k < size_s; k++) {
            dist[k] = valori[s][k] - u[s] - v[k];
        }

        int j = 0;
        while (true) {
            // Trova il più vicino
            j = -1;
            for (int k = 0; k < size_s; k++) {
                if (!visit[k] && (j == -1 || dist[k] < dist[j])) {
                    j = k;
                }
            }
            visit[j] = 1;

            // Condizione di uscita
            if (coppiaDx[j] == -1) {
                break;
            }
            int i = coppiaDx[j];
            for (int k = 0; k < size_s; k++) {
                if (!visit[k]) {
                    int new_dist = dist[j] + valori[i][k] - u[i] - v[k];
                    if (dist[k] > new_dist) {
                        dist[k] = new_dist;
                        prev[k] = j;
                    }
                }
            }
        }
        // Aggiornamento delle variabili
        for (int k = 0; k < size_s; k++) {
            if (k != j && visit[k]) {
                int i = coppiaDx[k];
                v[k] += dist[k] - dist[j];
                u[i] -= dist[k] - dist[j];
            }
        }

        u[s] += dist[j];

        // augmenting path (scorro il vettore dei precedenti per riassociare tutti gli zeri)
        while (prev[j] >= 0) {
            int d = prev[j];
            coppiaDx[j] = coppiaDx[d];
            coppiaSx[coppiaDx[j]] = j;
            j = d;
        }

        coppiaDx[j] = s;  // passaggio finale della parte precedente
        coppiaSx[s] = j;
        associati++;  // aumento il numero di zeri trovati
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

// Questo metodo si limita a calcolare la distanza soldato-componente, ma può accettare
// anche target come primo parametro, andando a calcolare la distanza target-componente.
int manhattan(pair<int, int> soldier, pair<int, int> component) {
    return abs(soldier.first - component.first) + abs(soldier.second - component.second);
}
