# Appunti di Algoritmi e Strutture Dati

- [Appunti di Algoritmi e Strutture Dati](#appunti-di-algoritmi-e-strutture-dati)
  - [18/02/2019](#18022019)
    - [Programmazione dinamica](#programmazione-dinamica)
      - [Domino - Fibonacci](#domino---fibonacci)
      - [Teorema di sottostruttura ottima](#teorema-di-sottostruttura-ottima)
      - [Hateville](#hateville)
      - [Knapsack](#knapsack)
  - [20/02/2019](#20022019)
    - [Programmazione dinamica (continua)](#programmazione-dinamica-continua)
      - [Knapsack (continua)](#knapsack-continua)
      - [Sottosequenza comune massimale (LCS)](#sottosequenza-comune-massimale-lcs)

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


$$DP[i]] = \left\{
\begin{array}{lc}
    0 & i = 0 or c = 0  \\
    - \infty & c < 0 \\
    max(DP[i − 1][c −w[i]] + p[i], DP[i − 1][c]) & altrimenti
\end{array}\right.$$

## 20/02/2019

### Programmazione dinamica (continua)

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
