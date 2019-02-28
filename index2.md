<br><div style="text-align: center; font-size: 20px"><a href="index.html"><- Appunti del primo semestre</a></div><br>

# Appunti di Algoritmi e Strutture Dati

- [Appunti di Algoritmi e Strutture Dati](#appunti-di-algoritmi-e-strutture-dati)
  - [18/02/2019](#18022019)
    - [Programmazione dinamica](#programmazione-dinamica)
      - [Domino - Fibonacci](#domino---fibonacci)
      - [Teorema di sottostruttura ottima](#teorema-di-sottostruttura-ottima)
      - [Hateville](#hateville)
      - [Knapsack](#knapsack)
  - [20/02/2019](#20022019)
    - [Programmazione dinamica (parte 2)](#programmazione-dinamica-parte-2)
      - [Knapsack (continua)](#knapsack-continua)
      - [Sottosequenza comune massimale (LCS)](#sottosequenza-comune-massimale-lcs)
  - [25/02/2019](#25022019)
    - [Programmazione dinamica (parte 3)](#programmazione-dinamica-parte-3)
      - [String matching approssimato](#string-matching-approssimato)
      - [Prodotto di catena di matrici](#prodotto-di-catena-di-matrici)
      - [Insieme indipendente di intervalli pesati](#insieme-indipendente-di-intervalli-pesati)

## 18/02/2019

### Programmazione dinamica

Una tecnica di programmazione che consiste nella divisione di un problema in sotto-problemi più piccoli, che vengono risolti una volta sola. Se ricapitano i sotto-problemi, si avrà già la soluzione che era stata memorizzata in una tabella (con indirizzamento $O(1)$). Vi è una differenza con la tecnica _divide-et-impera_, dove i sotto-problemi non sono ripetuti e quindi non possono essere memorizzati.

Il termine ha un origine diversa da quanto possa apparire (_programming_ si riferisce all'ambito logistico, _dynamic_ era inteso in senso temporale nell'ambito della scelta della soluzione ottima per ciascun passo).

Per risolvere i problemi si inizia definendo la soluzione in maniera ricorsiva ($DP[n]$). Questa sarà la formula che verrà utilizzata dall'algoritmo per calcolare il risultato e inserirlo nella tabella DP. La soluzione verrà costruita in maniera bottom-up, partendo dai casi base.

#### Domino - Fibonacci

Il gioco del domino è basato su tessere di dimensione 2×1. Per scrivere un algoritmo efficiente che prenda in input un intero n e restituisca il
numero di possibili disposizioni di n tessere in un rettangolo 2×n, possiamo riferirci alla ricerca dei numeri di Fibonacci. Infatti per trovare il numero di posizioni, date $n$ tessere, andremo a contare quelle necessarie per $n - 1$ (tessera inserita in verticale) e $n - 2$ (tessera inserita in orizzontale).

Questo algoritmo, generalmente esponenziale, viene ridotto a complessità $\Theta(n)$ (in realtà $\Theta(n^2)$ per via del fatto che sono richiesti $n$ bit per memorizzare un numero di Fibonacci molto grande, anziché $\log{n}$) dal punto di vista temporale e $\Theta(1)$ dal punto di vista spaziale.

$$DP[n] = \left\{
\begin{array}{lc}
    1 & n \le 1 \\
    DP[n - 1] + DP[n - 2] & n> 1
\end{array}\right.$$

La soluzione richiesta sarà disponibile in $DP[n]$.

#### Teorema di sottostruttura ottima

Un problema possiede una sottostruttura ottima se è possibile costruire efficientemente una soluzione ottimale a partire dalle soluzioni ottimali dei suoi sottoproblemi. Questa proprietà va dimostrata per ogni algoritmo che viene risolto tramite programmazione dinamica.

#### Hateville

Hateville è un villaggio particolare, composto da n case, numerate da 1 a n lungo una singola strada, nella quale i vicini si odiano e non hanno intenzione di partecipare a raccolte fondi alla quale partecipano loro.

Il problema può essere risolto con programmazione dinamica: dato un vettore $D$ di donazioni, sia $DP[i]$ il valore della massima quantità di donazioni che possiamo ottenere dalle prime $i$ case di Hateville. Allora $DP[n]$ sarà pari a $max(DP[i − 1], DP[i − 2] + D[i])$, ovvero il massimo tra le donazioni ottenibili considerando le $i-1$ case oppure le $i-2$ case e contando il vicino $i$.

$$DP[i]] = \left\{
\begin{array}{lc}
    0 & i = 0 \\
    D[1] & i = 1 \\
    max(DP[i − 1], DP[i − 2] + D[i] )& i \ge 2
\end{array}\right.$$

#### Knapsack

Dato un insieme di oggetti, ognuno caratterizzato da un peso e un profitto, e uno "zaino" con un limite di capacità, individuiamo un sottoinsieme di oggetti il cui peso sia inferiore alla capacità dello zaino e il valore totale degli oggetti sia massimale.

I dati in input sono un vettore $w$ che dichiara i pesi degli oggetti e un vettore $p$ che ne dichiara i profitti. Abbiamo infine $C$, la capacità massima dello zaino.

Per risolvere il problema, utilizziamo una matrice $DP$ dove $DP[i][c]$ è il massimo profitto ottenibile dai primi $i$ oggetti con una capacità occupata pari a $c$. Considerando l'oggetto $i$, avremo che se non lo prendiamo la capacità non cambia, se lo prendiamo allora andremo a memorizzare il nuovo profitto, pari alla somma del profitto dell'oggetto preso più il profitto ottenibile da uno zaino con un oggetto in meno e il suo peso in meno. Per effettuare la decisione chiaramente prenderemo il massimo. La formula per $DP[i][c]$ sarà pari a $\max(DP[i−1][c −w[i]] + p[i], DP[i − 1][c])$ (tralasciando i casi base.)

$$DP[i] = \left\{
\begin{array}{lc}
    0 & i = 0 or c = 0  \\
    - \infty & c < 0 \\
    max(DP[i − 1][c −w[i]] + p[i], DP[i − 1][c]) & altrimenti
\end{array}\right.$$

## 20/02/2019

### Programmazione dinamica (parte 2)

#### Knapsack (continua)

Dato che bisogna riempire l'intera matrice, Knapsack ha complessità $O(nC)$; tuttavia risulta pseudo-polinomiale, in quanto $C$ non è la dimensione dell'input ma l'input stesso. Quindi la vera complessità dipende dai bit necessari per rappresentare $C$, quindi sarà $O(2^n)$. Possiamo utilizzare una versione nella quale si fa uso di _memoization_; infatti non tutti gli elementi sono sempre necessari alla soluzione del problema.

La tecnica di memoization amplia il concetto di tabella DP, mantenendo in memoria se un certo sottoproblema è stato già risolto o meno (ad esempio inizializzando le celle del vettore/matrice con -1). Facendo così, la complessità è ridotta al minimo tra $2^n$ e $nC$. Sempre con memoization è possibile usare tabelle hash migliorando di molto la complessità spaziale.

Esiste infine una variante dello zaino, dove è possibile inserire un dato oggetto infinite volte nello zaino, rimanendo comunque soggetti al limite di capacità. E' necessario modificare la formula in questo modo: $\max(DP[i][c −w[i]] + p[i], DP[i − 1][c])$. Si può inoltre tentare di ridurre lo spazio occupato riducendo $DP$ a un vettore lungo $C$, dove $DP[c]$ rappresenta il profitto massimo raggiungibile in uno zaino di capacità $c$. Vedi slide per codici. E' necessario notare che questo approccio rende difficile la ricostruzione della soluzione; per ovviare a ciò usiamo un vettore extra $pos$ che andrà a memorizzare la posizione $i$ in cui ho trovato il massimo.

#### Sottosequenza comune massimale (LCS)

Problema generale: date due sequenze di DNA, rappresentate come una stringa di lunghezza $n$ contenente solo caratteri $\in { A, C, G, T}$, troviamo quanto sono simili. Definiamo due sequenze simili se una è sottostringa dell'altra, oppure se è necessario il cambiamento di $j$ caratteri per trasformare l'una nell'altra.

P è una **sottosequenza** di T se è ottenibile da T rimuovendo $j$ elementi (equivalente a un sottoinsieme). Non è detto che gli elementi siano contigui, ma devono avere lo stesso ordine.

Una sottosequenza X è detta **comune** se è sottosequenza di due date sequenze. E' detta **massimale** se non esiste altra sottosequenza comunque più lunga di essa.

Utilizzando un approccio di "forza bruta", otterremmo una complessità almeno esponenziale per controllare tutte le singole sottosequenze: troppo! Sia allora $T(i)$ il _prefisso_ di una certa sottosequenza, ovvero i suoi primi $i$ caratteri. Il problema può essere affrontato a partire dalle sequenze iniziali, distinguendo due casi, dato $T(i), U(j)$:

- Se le ultime lettere sono uguali, allora le prendo per buone e considero $T(i - 1), U(j - 1)$
- Altrimenti, prendo la sottosequenza più lunga tra $T(i - 1), U(j)$ oppure $T(i), U(j - 1)$ (essenzialmente facendo due casi scartando alternativamente l'ultimo carattere)

Possiamo quindi andare ad applicare questa logica ad una matrice $DP[i][j]$, dove $i, j$ sono gli indici del prefisso delle due sequenze e $DP[n][m]$ è la LCS cercata. Questo algoritmo ha una complessità pari a $O(mn)$ in quanto la tabella va necessariamente riempita per intero.

## 25/02/2019

### Programmazione dinamica (parte 3)

#### String matching approssimato

Un’occorrenza k-approssimata di P in T, dove P e T sono stringhe dette _pattern_ e _testo_, con $m \le n$, è una copia di P in T in cui sono ammessi k "errori" (o differenze) tra caratteri di P e caratteri di T, ovvero sostituzioni, inserimenti o cancellazioni (fino a k volte) di caratteri.

Utilizziamo una matrice $DP[i][j]$ che rappresenta il minimo valore k tale per cui esiste un occorrenza k-approssimata di P(i) in T(j). Abbiamo quattro possibilità: avanzare su entrambi i caratteri (uguali o diversi che siano, commettendo 0 oppure 1 errori), avanzare sul pattern (inserimento) oppure avanzare sul testo (cancellazione). Una volta completata la tabella il risultato cercato sarà nell'ultima riga, e sarà corrispondente al valore minimo di quella riga.

#### Prodotto di catena di matrici

Andiamo ad affrontare il problema della _parentesizzazione_ ottima, ovvero nel posizionamento ottimo delle parentesi affinché il prodotto di una catena di matrici abbia il minor numero di moltiplicazioni scalari richieste per essere completata.

Per risolvere il problema della parentesizzazione, possiamo considerare $P(n)$ come il numero di parentesizzazioni per $n$ matrici, che può essere diviso in due sottoproblemi, la ricerca delle parentesizzazioni per $P(k)$ e $P(n-k)$ una volta fissato k. Il numero totale sarà pari alla sommatoria di tutte le combinazioni. Questo indice k è detto l'indice dell'ultimo prodotto.

Sia $DP[i][j]$ il minimo numero di moltiplicazioni scalari necessarie per calcolare il prodotto $A[i . . . j]$. Vale:

$$
DP[i][j] = DP[i][k] + DP[k + 1][j] + c_{i−1} \cdot c_{k} \cdot c_{j}
$$

$c_{i−1} \cdot c_{k} \cdot c_{j}$ è il costo per moltiplicare la matrice $Ai \cdot...\cdot Ak: c_{i−1}$ righe, $c_k$ colonne e la matrice $Ak \cdot...\cdot Aj: c_k$ righe, $c_j$ colonne.

Possiamo ipotizzare due versioni, una top-down (con complessità $O(n^n)$) e una bottom-up (vedi slide per codici)

Nella versione ricorsiva top-down, calcoliamo tutte le possibili combinazioni per ogni singola cella considerando tutti gli ultimi prodotti, aggiornando eventualmente il minimo. Chiaramente sarà richiesta una quantità almeno esponenziale di passi, rendendola inutile rispetto all'approccio a forza bruta.

La versione bottom-up, oltre alla matrice $DP$ che contiene il numero di moltiplicazioni, usiamo una matrice $last$ che useremo per ricostruire la soluzione, contenente il valore dell'ultimo prodotto che minimizza il costo.

Nell'algoritmo, usiamo un doppio ciclo $O(n^2)$ per riempire tutte le celle: ogni riempimento richiederà $n$, in quanto andremo a valutare tutte le combinazioni già salvate per i singoli ultimi prodotti. Otteniamo quindi una complessità pari a $O(n^3)$.

#### Insieme indipendente di intervalli pesati

Siano dati n intervalli distinti $[a_1, b_1[, ... , [a_n, b_n[$ della retta reale, aperti a destra, dove all’intervallo i è associato un profitto $w_i, 1 \le i \le n$. Dobbiamo trovare un insieme indipendente di peso massimo, ovvero un sottoinsieme di intervalli disgiunti tra loro tale che la somma dei loro profitti sia la più grande possibile.

Innanzitutto ordiniamo gli intervalli per estremi finali crescenti. Per ogni singolo intervallo, andremo a calcolare il suo _predecessore_, ovvero il massimo indice per cui inizia un segmento che finisce prima del segmento corrente.

$$DP[i] = \left\{
\begin{array}{lc}
    0 & i = 0 \\
    max(DP[i − 1], DP[pred[i]] + w_i) & i > 0
\end{array}\right.$$

Con questa formula possiamo andare a scrivere due algoritmi, uno $O(n^2)$ e uno $O(n \log(n))$ (vedi slide, scriverò il codice in seguito).

<br><div style="text-align: center; font-size: 20px"><a href="index.html"><- Appunti del primo semestre</a></div>