<!-- markdownlint-disable MD033 MD041 -->

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
  - [11/03/2019](#11032019)
    - [Code con priorità](#code-con-priorit%C3%A0)
    - [Heap](#heap)
    - [HeapSort](#heapsort)
      - [MaxHeapRestore](#maxheaprestore)
      - [HeapBuild](#heapbuild)
      - [Terminazione](#terminazione)
    - [Codice delle code con priorità](#codice-delle-code-con-priorit%C3%A0)
    - [Insiemi disgiunti](#insiemi-disgiunti)
      - [Tecniche euristiche](#tecniche-euristiche)
  - [25/03/2019](#25032019)
    - [Cammini minimi](#cammini-minimi)
      - [Teorema di Bellman](#teorema-di-bellman)
      - [Schema generico](#schema-generico)
      - [Dijkstra - `dijkstra`](#dijkstra---dijkstra)
      - [Bellman-Ford](#bellman-ford)
      - [Cammini minimi su DAG](#cammini-minimi-su-dag)
    - [Cammini minimi per multipla sorgente](#cammini-minimi-per-multipla-sorgente)
      - [Floyd-Warshall](#floyd-warshall)
  - [27/03/2019](#27032019)
    - [Algoritmi greedy (parte 1)](#algoritmi-greedy-parte-1)
      - [Insieme indipendente di intervalli](#insieme-indipendente-di-intervalli)
      - [Resto](#resto)
      - [Scheduling - Shortest Job First](#scheduling---shortest-job-first)
      - [Zaino frazionario](#zaino-frazionario)
      - [Compressione di Huffman](#compressione-di-huffman)
  - [01/04/2019](#01042019)
    - [Algoritmi greedy (parte 2)](#algoritmi-greedy-parte-2)
      - [ALbero di copertura di peso minimo](#albero-di-copertura-di-peso-minimo)
      - [Algoritmo di Kruskal](#algoritmo-di-kruskal)
      - [Algoritmo di Prim](#algoritmo-di-prim)

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

## 11/03/2019

### Code con priorità

Una __coda con priorità__ è una struttura dati speciale nella quale ogni elemento inserito ha una _priorità_, e i valori vengono estratti dal più alto o dal più basso valore di priorità.

Sono permessi l'inserimento e l'estrazione dell'elemento in cima alla coda, nonché la diminuzione della priorità di un oggetto in coda.

Esistono varie implementazioni delle code con priorità, e le più efficienti utilizzano gli alberi RB (con tutte le operazioni in $O(\log{n})$) e gli __heap__ (che sfruttano i vantaggi degli alberi con la memorizzazione efficiente di un vettore)

### Heap

Un __min-heap__ è una struttura dati speciale, composta da un _albero binario completo_ (dove tutti i nodi sono al limite accatastati a sinistra, evitando sbilanciamenti) nella quale ogni valore di ogni nodo è minore del valore dei figli.

Un albero heap non impone una relazione di _ordinamento totale_ bensì _parziale_: mantiene infatti le proprietà di riflessività, simmetria e antisimmetria.

Memorizziamo gli alberi heap in un __vettore heap__, dove $A[1]$ contiene la radice, il padre di un nodo $i$ occupa la posizione $\floor{i/2}$, e i suoi figli occupano le posizioni $2i, 2i + 1$.

Tutte le operazioni per i min-heap sono equivalentemente applicabili ai max-heap invertendo tutti i maggiori e minori.

### HeapSort

Questo algoritmo ordina in tempo $O(n \log{n})$ un vettore. Vediamo uno per uno i metodi necessari alla creazione dell'algoritmo.

#### MaxHeapRestore

Dato un vettore heap $A$ e un indice $i$ tale per cui i suoi sottoalberi figli destri e sinistri sono già maxheap, cerchiamo di ripristinare la proprietà max-heap nell'intero sottoalbero radicato in $i$.

A ogni iterazione della funzione, consideriamo il padre $i$ e i suoi due figli, ed effettuiamo uno scambio tale che il maggiore tra i tre vada nella posizione del padre. A questo punto uno dei due sottoalberi figli sono stati privati della proprietà, e andranno corretti in maniera ricorsiva.

#### HeapBuild

Sia $A$ un vettore da ordinare di dimensione $n$. Questa procedura attraversa in maniera inversa l'albero heap corrispondente al vettore, a partire dalle foglie, eseguendo `maxHeapRestore()` su ognuno di essi (per ogni posizione da $\floor{n/2}$ a $1$).

#### Terminazione

Per completare l'algoritmo, eseguo `heapBuild()` sul vettore ottenendo un heap (con complessità $O(n)$); rimuovo la radice dell'albero e la posiziono in fondo al vettore, scambiandola con l'ultimo. Eseguo `maxHeapRestore()` per ripristinare la proprietà di heap e continuo finché il vettore non è completamente ordinato.

### Codice delle code con priorità

Vedi slide per implementazione su codice delle code con priorità.

Tutte le operazioni che modificano gli heap sistemano la proprietà heap lungo un cammino radice-foglia (`deleteMin()`) oppure lungo un cammino nodo-radice (`insert()`, `decrease()`); poichè l’altezza è $\log{n}$, il costo di tali operazioni è $O(\log{n})$.

### Insiemi disgiunti

Consideriamo ora una collezione di __insiemi disgiunti__, ciascuno composto da un unico elemento. In un certo insieme consideriamo il _rappresentante_ (che nel caso unitario è pari all'unico elemento), un'invariante nel caso di ricerca e confronti tra insiemi, che è un qualsiasi elemento di un dato insieme.

La funzionalità principale è l'unione di due `MFS`, che causerà la scelta di un nuovo rappresentante dell'unione risultante, e la ricerca dell'insieme di appartenenza di un insieme.

Questa struttura dati può trovare uso all'interno di __componenti connesse__ di un grafo non orientato dinamico: si inizia con componenti connesse unitarie che vengono via via unite. Al termine dell'algoritmo i vari insiemi rappresentaranno le componenti connesse.

Ogni insieme viene rappresnetato da una lista concatenata: il primo oggetto della lista è il rappresentante, e ogni oggetto della lista possiede un puntatore al suddetto rappresentante (compreso il rappresentante stesso) e al successivo. L'operazione `find(x)` che cerca il rappresentante di un insieme che contiene `x` sarà quindi con complessità pari a $O(1)$, mentre l'operazione `merge(x, y)` richiederà lo spostamento di tutti i puntatori di y ottenendo un costo ammortizzato pari a $O(n)$.

Un'implementazione alternativa utilizza alberi non binari; ciò rende la complessità pari a $O(1)$ per l'unione e la ricerca del rappresentante, mentre la ricerca richiederà $O(n)$ (in quanto bisogna esplorare l'intero albero).

#### Tecniche euristiche

Come possiamo migliorare alcune operazioni sugli insiemi disgiunti?

Ad esempio, possiamo migliorare la velocità di `merge()` attaccando la lista più corta a quella più breve (è infatti indifferente il rappresentante finale!).

Alternativamente, nel caso degli alberi, possiamo migliorare `find()` cercando di mantenere l'altezza degli alberi bassa mantenendo informazioni sul rango (ovvero la quantità di figli) dell'albero e al momento dell'unione si attacca l'albero più basso a quello più alto.

Possiamo infine "appiattire" un certo albero attaccando sottoalberi di una certa lunghezza direttamente alla radice (aumentandone la larghezza).

Vedi slide per implementazione del codice degli `MFset`.

## 25/03/2019

### Cammini minimi

Dato un grafo orientato $G=(V, E)$ alla quale è associata una __funzione di peso__ $w : E \rightarrow \mathbb{R}$, troviamo un cammino da un nodo sorgente $s$ a ogni altro nodo $u \in V$ il cui costo sia minimo, ovvero $\le$ di ogni altro cammino tra $s$ e $u$. Alcune variazioni sono cammini minimi tra coppie di nodi arbitrarie, che richiedono l'uso della programmazione dinamica (per tutte le coppie) e comunque la soluzione del primo problema.

Particolare attenzione va data al concetto di peso: algoritmi diversi possono funzionare o meno a seconda che la funzione peso abbia codominio in $\mathbb{R}$ oppure solo in $\mathbb{R}^+$; (ad esempio peso negativo quando si ha una perdita di profitto).

Questo problema ha sottostruttura ottima, rappresentata dall'albero dei cammini minimi: un albero di copertura radicato in $s$ che contiene tutti i cammini minimi da $s$ agli altri nodi raggiungibili.

Una soluzione ammissibile può essere descritta da un albero di copertura $T$ radicato in $s$ e da un vettore di distanza $d$, i cui valori $d[u]$ rappresentano il costo del cammino da $s$ a $u$ in T.

Per rappresentare l'albero, utilizziamo la rappresentazione basata sul vettore dei padri.

#### Teorema di Bellman

Una soluzione ammissibile è anche ottima se e solo se per ogni arco $(u, v)$ selezionato per la soluzione, la distanza da $s$ a $v$ passando per $u$ è uguale al peso dell'arco $(u, v)$ sommato alla distanza da $s$ a $u$.

#### Schema generico

Possiamo ora rappresentare un algoritmo che fornisce una soluzione ottima, facendo uso di una struttura dati generica. Marchiamo 4 righe che andremo di volta in volta a modificare a seconda della struttura dati scelta.

```Java
(int[],int[]) shortestPath(Graph G, Node s)
```

```Coffee
int[] d = new int[1...G.size()] # d[u] è la distanza da s a u
int[] T = new int[1...G.size()] # T[u] è il padre di u nell’albero T
boolean[] b = new boolean[1...G.size()] # b[u] è true se u ∈ S

foreach u ∈ G.V()−{s} do
    T[u] = nil
    d[u] = +∞
    b[u] = false

T[s] = NULL
d[s] = 0
b[s] = true

DataStructure S = DataStructure() # Riga 1
S.add(s)

while not S.isEmpty() do
    int u = S.extract() # Riga 2
    b[u] = false
    for v in G.adj(u) do
        if d[u] + G.w(u,v) < d[v] then
            if not b[v] then
                S.add(v) # Riga 3
                b[v] = true
            else
                # Azione da svolgere nel caso v sia già presente in S; Riga 4
            T[v] = u
            d[v] = d[u] + G.w(u,v)

return (T,d)
```

#### Dijkstra - `dijkstra`

Nella versione originale, veniva utilizzato per la ricerca di un cammino minimo tra due nodi. Funziona solo con pesi positive, e essendo stato proposto prima dell'invenzione dello heap, utilizzava una semplice rappresentazione tramite vettore per la struttura dati.

In questa implementazione, si crea una coda a priorità basata su vettore, nella quale la posizione $i$-esima rappresenta la priorità del nodo $i$-esimo. Di volta in volta si va a cercare il minimo e lo si estrae (cancellandolo): per ogni oggetto, non presente o meno nella struttura dati, si aggiorna la priorità con l'equazione di Bellman.

```Coffee
PriorityQueue Q = PriorityQueue() # Riga 1
u = Q.deleteMin() # Riga 2
Q.insert(v, d[u] + G.w(u, v)) # Riga 3
Q.decrease(v, d[u] + G.w(u, v)) # Riga 4
```

La complessità totale dell'algoritmo è $O(n^2)$ a causa dell'inefficiente ricerca del minimo nella rappresentazione con vettore.

Questa versione, ipotizzata nel 1959, è stata poi upgradata nel 1977 da Johnson facendo uso dell'heap binario introdotto pochi anni prima: grazie all'accesso logaritmico, la complessità scende a $O(m\log{n})$; grazie all'heap di Fibonacci nel 1987 viene ulteriormente modificata arrivando a $O(m + n\log{n})$.

#### Bellman-Ford

Questo algoritmo è computazionalmente più pesante di Dijkstra, ma funziona anche con pesi negativi.

```Coffee
Queue Q = Queue() # Riga 1
u = Q.dequeue() # Riga 2
Q.enqueue(v) # Riga 3
# Sezione non necessaria; Riga 4
```

La complessità è pari a $O(nm)$.

#### Cammini minimi su DAG

Nel caso in cui si ha a che fare con un _DAG_, è possibile rilassare il grafo tramite `topSort` e inserendolo tutto in una volta in una pila. Il resto dell'algoritmo è analogo a una semplice BFS e ha complessità $O(n + m)$.

### Cammini minimi per multipla sorgente

| Input                       | Complessità                | Approccio                                           |
| --------------------------- | -------------------------- | --------------------------------------------------- |
| Pesi positivi, grafo denso  | $O(n\cdot n^2)$            | Applicazione ripetuta dell’algoritmo di Dijkstra   |
| Pesi positivi, grafo sparso | $O(n·(m\log{n}))$          | Applicazione ripetuta dell’algoritmo di Johnson    |
| Pesi negativi               | $O(n\cdot n \cdot m)$      | Applicazione ripetuta di Bellman-Ford, sconsigliata |
| Pesi negativi, grafo denso  | $O(n^3)$                   | Algoritmo di Floyd e Warshall                       |
| Pesi negativi, grafo sparso | $O(n\cdot m\cdot \log{n})$ | Algoritmo di Johnson per sorgente multipla          |

#### Floyd-Warshall

Sia $k \in [0 ... n]$. Diciamo che un cammino $p_k^{xy}$ è un cammino minimo k-vincolato fra $x$ e $y$ se esso ha il costo minimo fra tutti i cammini fra $x$ e $y$ che non passano per nessun vertice in $v_k+1,...,v_n$ ($x$ e $y$ sono esclusi dal vincolo).

Questo concetto può essere sintetizzato con la seguente formula ricorsiva: Denotando con $d^k[x][y]$ il costo totale del cammino minimo k-vincolato fra x e y, se esiste, varrà che $d^k[x][y]$ sarà pari al peso tra x e y se $k = 0$ (caso base), altrimenti al $\min{(d^{k-1}[x][y], d^{k-1}[x][k] + d^{k-1}[k][y])}$

```Java
(int[][],int[][]) floydWarshall(Graph G)
```

```Coffee
int[][] d = new int[1...n][1...n]
int[][] T = new int[1...n][1...n]

for u, v in G.V() do
    d[u][v] = +∞
    T[u][v] = nil

for u in G.V() do
    for v in G.adj(u) do
        d[u][v] = G.w(u,v)
        T[u][v] = u

for k = 1 to G.size() do
    for u in G.V() do
        for v in G.V() do
            if d[u][k] + d[k][v] < d[u][v] then
                d[u][v] = d[u][k] + d[k][v]
                T[u][v] = T[k][v]
return d
```

## 27/03/2019

### Algoritmi greedy (parte 1)

Nell'ambito dei problemi di ottimizzazione, quando andiamo a effettuare una sequenza di decisioni la tecnica greedy preferisce selezionare l'ottimo locale piuttosto che valutare tutte le decisioni possibili. Bisogna tuttavia dimostrare che applicando questa tecnica si ottiene l'ottimo globale, oltre a dimostrare che il problema gode di sottostruttura ottima (_"fatta tale scelta, resta un sottoproblema con la stessa struttura del problema principale"_).

In generale, è possibile agire in due modi: trovare una forma ricorsiva del problema e scrivere una soluzione con programmazione dinamica, poi procedere con un miglioramento della soluzione passando a una scelta greedy; oppure, procedere direttamente con greedy:

- Evidenziare i "passi di decisione"; trasformare il problema di ottimizzazione in un problema di "scelte" successive
- Evidenziare una possibile scelta ingorda; dimostrare che tale scelta rispetto il "principio della scelta ingorda"
- Evidenziare la sottostruttura ottima; dimostrare che la soluzione ottima del problema "residuo" dopo la scelta ingorda può essere unito a tale scelta
- Scrittura codice: top-down, anche in maniera iterativa

#### Insieme indipendente di intervalli

Riprendiamo il problema visto in programmazione dinamica ([vedi qui](#insieme-indipendente-di-intervalli-pesati)).

Iniziamo con programmazione dinamica: troviamo una forma ricorsiva del problema e scriviamo una versione iterativa. Scopriamo tuttavia presto che questo approccio non è ideale, in quanto si ottiene un algoritmo $O(n^3)$, ancora peggio di quanto visto prima.

Proviamo allora ad applicare la tecnica greedy. Dato $S[i, j]$ sottoproblema non vuoto, troviamo un intervallo $m$ tale che abbia il minor tempo di fine. Avremo che il sottoproblema $S[i, m]$ sarà vuoto e $m$ sarà contenuto in qualche soluzione ottima.

```Java
Set independentSet(int[] a, int[] b)
```

```Coffee
# { ordina a e b in modo che b[1] <= b[2] <= ... <= b[n] }
Set S = Set()
S.insert(1)
int last = 1 # Ultimo intervallo inserito
for i = 2 to n do
    if a[i] ≥ b[last] then
        # Controllo indipendenza
        S.insert(i)
        last = i
return S
```

#### Resto

Dato un insieme di "tagli" di monete e un intero, rappresentante il resto da dare, trovare il più piccolo numero di monete necessarie a fornire il resto. Assumiamo di avere infinite monete per ogni taglio.

Un approccio greedy potrebbe essere selezionare la moneta j più grande tale per cui $t[j] \le R$, e poi risolvere il problema $S(R−t[j])$. E' necessario tuttavia dimostrare che non tutti i tagli di monete sono adatti a questo tipo di soluzione.

```Java
void resto(int[] t, int n, int R, int[] x)
```

```Coffee
{ Ordina le monete in modo decrescente }
for i = 1 to n do
    x[i] = floor(R/t[i])
    R = R− x[i] * t[i]
```

#### Scheduling - Shortest Job First

Vediamo ora l'implementazione dell'algoritmo di scheduling __Shortest Job First__, che permette di ottenere un tempo di completamento medio ottimo rispetto a qualunque altro algoritmo.

Esiste una soluzione ottima A in cui il job con minor tempo di ﬁne m si trova in prima posizione ($A[1] = m$).

Sia A una soluzione ottima di un problema con n job, in cui il job con minor tempo di ﬁne m si trova in prima posizione. La permutazione dei seguenti $n−1$ job in A è una soluzione ottima al sottoproblema in cui il job $m$ non viene considerato.

#### Zaino frazionario

Consideriamo il problema dello zaino; ora è possibile prelevare parzialmente degli oggetti (con $f: 0 < f < 1$).

Possiamo ipotizzare true approcci greedy:

- Riempire per profitto decrescente (eventualmente frazionando l'ultimo oggetto)
- Riempire per peso crescente
- Riempire per profitto specifico $\frac{p_i}{w_i}$

Il terzo approccio risulta vincente. Andando infatti ad ordinare gli oggetti per profitto specifico possiamo infine adottare un algoritmo simile a quello del resto, che restituirà un vettore $x$ rappresentante le frazioni degli oggetti che andremo a prendere.

#### Compressione di Huffman

Affrontiamo il problema della codifica dei dati in maniera efficiente: dobbiamo risparmiare bit e rendere il trasferimento veloce. Quale è il numero minimo di bit per rappresentare un testo, opportunamente compresso.

Utilizziamo una funzione di codifica $f : f(c) = x$ dove $c$ è un carattere e $x$ una rappresentazione binaria.

Sia un _codice a prefisso_ un codice output di una funzione di codice che non è mai prefisso di nessun'altro output della stessa funzione. Il funzionamento è analogo all'allocazione classful degli indirizzi IP.

Per la decodifica utilizziamo un _albero binario di decodifica_ contenente caratteri dell'alfabeto sulle foglie e dei tag $<0, 1>$ sui figli: 0 a sinistra, 1 a destra. Ogni volta che si legge un bit si compie una decisione sull'albero fino ad arrivare a una foglia.

Per completare, ci serve un file F composto da caratteri nell’alfabeto $\Sigma$. Avremo che se dT(c) è la profondità della foglia che rappresenta c nell'albero, allora la dimensione della codifica sarà pari alla somma del prodotto delle profondità per le frequenze $f[c]$ di ogni carattere $c$.

L'algoritmo consiste nel comporre un vettore contenente i caratteri $c$ e la loro frequenza relativa $f$. Si prelevano i due caratteri con frequenza minore e si compone un albero avente come figli destri e sinistri i due caratteri e lo si reinserisce nel vettore.

```Java
Tree huffman(int[] c, int[] f, int n)
```

```Coffee
PriorityQueue Q = MinPriorityQueue()
for i = 1 to n do
    Q.insert(f[i], Tree(f[i],c[i]))

for i = 1 to n−1 do
    z1 = Q.deleteMin()
    z2 = Q.deleteMin()
    z = Tree(z1.f + z2.f,nil)
    z.left = z1
    z.right = z2
    Q.insert(z.f,z)

return Q.deleteMin()
```

## 01/04/2019

### Algoritmi greedy (parte 2)

#### ALbero di copertura di peso minimo

Dato un grafo pesato, determiniamo come connettere tutti i nodi con un albero di copertura il cui peso degli archi sia minimo.

Sia $G$ un grafo non orientato e connesso, $w$ una funzione di peso per gli archi. Dobbiamo trovare l'albero di copertura di peso minimo, ovvero dove $w(T) = \sum_{[u, v] \in E_T} w(u, v)$. L'idea è partire con un sottinsieme $A$ di archi, che a ogni iterazione viene aumentato a patto che rimanga sempre sottoinsieme di qualche albero di copertura minimo.

Definiamo _arco sicuro_ un arco $[u, v]$ che se unito al sottoinsieme $A$ non ne modifica la proprietà definita in precedenza.

Definiamo __taglio__ di un grafo orientato è una divisione dei suoi nodi in due sottoinsiemi disgiunti tale per cui $S, V - S$ è una partizione dei nodi. Un arco attraversa il taglio se dati $u, v, u \in S$ e $v \in V - s$, e verrà detto _leggero nel taglio_ se il suo peso è minimo tra i pesi degli archi che attraversano un taglio. Avremo che se un arco che attraversa il taglio è leggero, e il taglio rispetta il sottoinsieme $A$, allora è un arco sicuro.

#### Algoritmo di Kruskal

Partiamo da una foresta composta da alberi unitari. A ogni passo, individuiamo un arco leggero che connette due alberi nella foresta e lo aggiungiamo all'insieme degli archi che compongono il nostro minimum spanning tree. Per questa implementazione utilizziamo un merge-find set.

```Java
Set kruskal(Edge[] A, int n, int m)
```

```Coffee
Set T = Set()
Mfset M = Mfset(n)
# { ordina A[1,...,m] in modo che A[1].weight ≤···≤ A[m].weight }
int count = 0
int i = 1
# Termina quando l’albero ha n−1 archi o non ci sono più archi
while count < n − 1 and i ≤ m do
    if M.find(A[i].u) != M.find(A[i].v) then
        M.merge(A[i].u, A[i].v)
        T.insert(A[i])
        count = count + 1
    i = i + 1
return T
```

La complessità è $O(m \log{n})$.

#### Algoritmo di Prim

Prim funziona in maniera totalmente opposta. Parte da un vertice arbitrario $r$$ e a ogni passo aggiunge un arco leggero che connette l'albero $A$ a un vertice non presente nell'albero. Per l'intera durata dell'algoritmo viene mantenuto un singolo albero.

Utilizziamo una coda con priorità che registra i vertici non ancora nell'albero, con priorità pari al peso minimo di un arco che connette tale vertice a qualunque vertice nell'albero (oppure $+\infty$ se non esiste). Ogni nodo mantiene un puntatore al padre tramite il vettore dei padri.

```Java
prim(Graph G, Node r, int[ ] p)
```

```Coffee
PriorityQueue Q = MinPriorityQueue()
PriorityItem[ ] pos = new PriorityItem[1 . . . G.n]
foreach u ∈ G.V() − {r} do
    pos[u] = Q.insert(u, +∞)

pos[r] = Q.insert(r, 0)
p[r] = 0

while not Q.isEmpty() do
    Node u = Q.deleteMin()
    pos[u] = nil
    for v ∈ G.adj(u) do
        if pos[v] != nil and w(u, v) < pos[v].priority then
            Q.decrease(pos[v], w(u, v))
            p[v] = u
```

La complessità è pari a $O(m \log{n})$.

<br><div style="text-align: center; font-size: 20px"><a href="index.html"><- Appunti del primo semestre</a></div>