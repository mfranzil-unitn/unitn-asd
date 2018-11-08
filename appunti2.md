# Appunti di Algoritmi e Strutture Dati [20181025 -]

- [Appunti di Algoritmi e Strutture Dati [20181025 -]](#appunti-di-algoritmi-e-strutture-dati-20181025)
    - [30/10/2018](#30102018)
    - [01/11/2018](#01112018)
    - [06/11/2018](#06112018)
    - [08/11/2018](#08112018)
        - [Grafi](#grafi)
        - [Implementazione dei grafi](#implementazione-dei-grafi)
        - [Visite dei grafi](#visite-dei-grafi)
        - [BFS](#bfs)
            - [Numero di Erdos](#numero-di-erdos)
        - [DFS](#dfs)
            - [Componenti (fortemente) connesse](#componenti-fortemente-connesse)
## 30/10/2018

Lezione di Laboratorio svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 01/11/2018

Lezione annullata per festività nazionale.

## 06/11/2018

Lezione annullata per giornate di Dipartimento dedicate alle prove parziali.

## 08/11/2018

### Grafi

Un grafo è un insieme di nodi collegati da archi. Gli archi e i nodi possono essere etichettati e gli archi possono anche essere direzionati. Andremo ad esplorare problemi sia in grafi pesati che in grafi non pesati; inoltre, andremo ad affrontare altri problemi che possono essere riconducibili a problemi relativi ai grafi.

Chiamiamo **grafo orientato** una coppia $G = (V, E)$ dove V è un insieme di nodi ed è un insieme di coppie ordinate $(u, v)$ detti archi. Un **grafo non orientato** non avrà coppie ordinate nell'insieme degli archi.

Un vertice $v$ è detto *adiacente* se $\exists v : (u, v)$. Il risultante arco è detto *incidente*.

Chiameremo il numero di nodi $n$ ed il numero di archi $m$. Vale $m \le \frac{n(n-1)}{2} = O(n^2)$ per grafi non orientati e $m \le n^2 -n = O(n^2)$ per grafi orientati. Definiremo da ora in poi la complessità in funzione sia di $n$ che di $m$.

Un grafo con un arco in tutte le coppie di nodi è detto **completo**. Un grafo con "pochi" o "tanti" archi è detto rispettivamente **sparso** (es. $m = O(n), m = O(n \log n)$) e **denso** (es. $m = \theta(n^2)$).

Un albero **libero** è un grafo connesso con $m = n - 1$. Un albero **radicato** è un albero libero con una radice fissato. Un insieme di alberi è detto **foresta**.

Il **grado** di un nodo è il numero di archi incidenti su di esso.

Un **cammino** è una sequenza di nodi $u_0, u_1 ... u_n$ tale che ogni coppia ordinata del nodo appartiene all'insieme degli archi.

### Implementazione dei grafi

Nella versione generale, una classe grafo è una struttura dati dinamica che permette di aggiungere e rimuovere nodi e archi, ottenere un'insieme di tutti i nodi, il numero di nodi, un metodo che dato un nodo restituisce i nodi adiacenti. Nelle implementazioni utilizzeremo una specifica ridotta senza rimozione di archi e nodi, facendo uso di due diversi approcci:

- Matrici di adiacenza
- Liste di adiacenza

Una **matrice di adiacenza** è una matrice $n \times n$. In ogni singola posizione A[a][b] avremo 0 se esiste un dato arco oppure 1 se non esiste. Occupa spazio e tempo di iterazione $O(n^2)$ e l'accesso ai dati richiede $O(1)$.

Una **lista di adiacenza** è una lista di liste nella quale in ciascun elemento abbiamo come nodo iniziale ogni nodo presente nel grafo, alla quale sono collegati tutti i nodi adiacenti al dato nodo. Occupa spazio e tempo di iterazione $O(n + m)$ e l'accesso ai dati richiede $O(n)$.

Infine, possiamo assegnare in entrambi gli approcci un peso a ogni singolo nodo.

Assumeremo che l'implementazione sia basata su vettori di adiacenza statici o dinamici, contenenti interi (anziché node, per mantenere l'accesso costante all'informazione) e con operazioni di aggiunta con complessità costante. Assumeremo infine che il grafo sia statico una volta generato. Rimane comunque consigliabile l'implementazione delle matrici di adiacenza per grafi densi (mentre le liste di adiacenza rimangono ottimali per grafi sparsi.)

### Visite dei grafi

Abbiamo due possibilità per le visite dei grafi; entrambe prevedono comunque la visita una e una volta sola di ogni singolo nodo del grafo.

Una **visita in ampiezza**, data una radice, visita prima tutti i nodi di distanza 1, poi di distanza 2, etc. Viene usato per calcolare i cammini minimi.

Una **visita in profondità** visita, dato ogni nodo adiacente, ricorsivamente i vicini adiacenti, etc. Viene usato per verificare, ad esempio, le componenti connesse.

Segue un'implementazione standard dell'attraversamento del grafo.

```Java
graphTraversal(Graph G, Node r)
```

```Ruby
Set S = Set() # Insieme generico
S.insert(r) # Da specificare
# { marca il nodo r }
while S.size() > 0 do
    Node u = S.remove() # Da specificare
    # { visita il nodo u }
    for v in G.adj(u) do
    # { visita l’arco (u; v) }
    if v non è ancora stato marcato then
    # { marca il nodo v }
    S.insert(v) # Da specificare
```

### BFS 

L'obiettivo della visita in ampiezza è visita i nodi a distanza crescenti dalla sorgente. Per farlo genereremo un albero *BFS*.

```Java
bfs(Graph G, Node r)
```

```Ruby
Queue Q = Queue()
S.enqueue(r)
boolean[] visited = new boolean[1 . . . G.size()]
for u in G.V() - {r} do
    visited[u] = false
visited[r] = true
while not Q.isEmpty() do
    Node u = Q.dequeue()
    # { visita il nodo u }
    for v in G.adj(u) do
        # { visita l’arco (u, v) }
        if not visited[v] then
            visited[v] = true
            Q.enqueue(v)
```

#### Numero di Erdos

Il numero di Erdos rappresenta il cammino minimo in un grafo di persone che hanno scritto articoli scientifici. Erdös ha valore erdos = 0. I co-autori di Erdös hanno erdos $= 1$. Se X è co-autore di qualcuno con erdos = k e non è coautore con qualcuno con erdos $< k$, allora X ha erdos $= k + 1$. Le persone non raggiunte da questa definizione hanno erdos = $+ \inf$. Questa implementazione è molto simile ai numeri di Bacon.

Abbiamo quindi l'implementazione `bfs` adattata ai numeri di Erdos:

```Java
erdos(Graph G, Node r, int[] erdos, Node[] parent)
```

```Ruby
Queue Q = Queue()
Q.enqueue(r)
for u in G.V() - {r} do
    visited[u] = Inf
erdos[r] = 0
parent[r] = nil
while not Q.isEmpty() do
    Node u = Q.dequeue()
    for v in G.adj(u) do
        if erdos[v] == Inf then # Se il nodo v non è stato scoperto
        erdos[v] = erdos[u] + 1
        parent[v] = u
        Q.enqueue(v)
```

Durante la visita, andremo via via ad accumulare blocchi di nodi che hanno tutti distanza uguale dalla radice. Per generare il nostro albero BFS di copertura che conterrà tali nodi utilizziamo il vettore `parent`nell'algoritmo precedente. Per stampare il cammino minimo utilizziamo questa implementazione:

```Java
printPath(Node r, Node s, Node[] parent)
```

```Ruby
if r == s then
    print(s)
    return
if parent[s] == nil then
    raise ValueError
    return
printPath(r, parent[s], parent)
print(s)
```

La complessità di questo algoritmo è pari a $O(n + m)$, infatti ogni singolo nodo e ogni singolo arco viene analizzato una volta sola.

### DFS

La Depth-First Search viene spesso usata come subroutine di altri problemi. L'output sarà una *foresta* depth-first, un albero per ogni nodo visitato.

```Java
dfs(Graph G, Node u, boolean[] visited)
```

```Ruby
visited[u] = true
# { visita il nodo u (pre-order) }
foreach v in G.adj(u) do
    if not visited[v] then
        # { visita l’arco (u, v) }
        dfs(G, v, visited)
# { visita il nodo u (post-order) }
```

Questo algoritmo presenta un problema strutturale: la grandezza degli stack nei sistemi operativi è limitata e per alberi di grandi dimensioni è facilmente superabile. Per ovviare al problema spesso si usa la BFS invece della DFS, oppure rendendo l'algoritmo iterativo e adattandolo rendendo simile alla BFS (ovvero si permette l'inserimento multiplo dei nodi nella coda, fino a un numero pari al numero di archi entranti; inoltre si anticipa il controllo della visita all'estrazione e non all'inserimento). Vedi slide per implementazione.

#### Componenti (fortemente) connesse

Molti algoritmi iniziano decomponendo il grafo nelle sue componenti connesse, applicando l'algoritmo e poi ricompongono assieme il grafo. Abbiamo sia le **componenti connesse** che le **componenti fortemente connesse** (su grafi orientati)

Un grafo non orientato G è connesso $\leftrightarrow$ ogni suo nodo è raggiungibile da qualsiasi altro nodo.

- Un grafo G' = (V', E') è una componente connessa di G $\leftrightarrow$ G' è un sottografo connesso e massimale di G
- G' è un sottografo di G (G' $\in$ G) $\leftrightarrow$ V' $\in$ V e E' $\in$ E
- -G' è massimale, non esiste nessun altro sottografo G'' di G tale che G'' è connesso e più grande di G' (i.e. G' $\in$ G'' $\in$ G)

Per identificare le sue componenti connesse, verifichiamo alla fine della DFS se tutti i nodi sono marcati; altrimenti siamo in presenza di un grafo con più componenti connesse, e la visita deve ricominciare da capo da una componente non ancora visitata.

```Java
int[] cc(Graph G)
```

```Ruby
int[] id = new int[1 ...G.size()]
for u in G.V() do
    id[u] = 0
int counter = 0
for u in G.V() do
    if id[u] == 0 then
        counter = counter + 1
        ccdfs(G, counter, u, id)
return id
```

```Java
ccdfs(Graph G, int counter, Node u, int[] id)
```

```Ruby
id[u] = counter
for v in G.adj(u) do
    if id[v] == 0 then
        ccdfs(G, counter, v, id)
```