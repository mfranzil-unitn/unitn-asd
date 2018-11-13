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
    - [13/11/2018](#13112018)
        - [Grafi con cicli](#grafi-con-cicli)
        - [Ordinamento topologico](#ordinamento-topologico)
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

## 13/11/2018

### Grafi con cicli

In un grafo non orientato, un ciclo C di lunghezza $k > 2$ è una sequenza di nodi $u_0, u_1...u_n$ tale che la sequenza è un cammino e il primo e l'ultimo nodo coincidono. Chiamiamo un grafo con almeno un ciclo **ciclico** e uno che non ne contiene **aciclico**.

```Java
boolean hasCycleRec(Graph G, Node u, Node p, boolean[] visited)
```

```Ruby
visited[u] = true
for u in G.adj(u) - {p} do
    if visited[v] then
        return true
    else if hasCycleRec(G, v, u, visited) then
        return true
return false
```

Un grafo orientato aciclico è detto **DAG (directed acyclic graph)**. Per trovare eventuali cicli in grafi orientati, utilizziamo l'albero di copertura DFS. All'interno del nostro albero di copertura distinguiamo, dato un arco $(u, v)$:

- **archi in avanti** - se $u$ è un antenato di $v$
- **archi all'indietro** - se $u$ è un discendente di $v$
- **archi di attraversamento** - altrimenti

```Java
void dfs-schema(Graph G, Node u, int &time, int[] dt, int[] ft)
```

```Ruby
# { visita il nodo u (pre-order) }
time = time + 1
dt[u] = time
for u in G.adj(u) do
    # { visita l’arco (u, v) (qualsiasi) }
    if dt[v] == 0 then
        # { visita l’arco (u, v) (albero) }
        dfs-schema(G, v, time, dt, ft)
    else if dt[u] > dt[v] and ft[v] == 0 then
        # { visita l’arco (u, v) (indietro) }
    else if dt[u] < dt[v] and ft[v] 6= 0 then
        # { visita l’arco (u, v) (avanti) }
    else
        # { visita l’arco (u, v) (attraversamento) }
# { visita il nodo u (post-order) }
time = time + 1
ft[u] = time
```

Questo algoritmo va a classificare gli archi: infatti, costruito l'albero di copertura, ogni sottoalbero dell'albero avrà un intervallo [dt, ft] contenuto o uguale all'antenato. Vale il seguente teorema:

> Data una visita DFS di un grafo G = (V,E), per ogni coppia di nodi u, v in V, solo una delle condizioni seguenti è vera:
> Gli intervalli [dt[u], ft[u]] e [dt[v], ft[v]] sono non-sovrapposti `->` u, v non sono discendenti l’uno dell’altro nella foresta DF
> L’intervallo [dt[u], ft[u]] è contenuto in [dt[v], ft[v]] `->` u è un discendente di v in un albero DF
> L’intervallo [dt[v], ft[v]] è contenuto in [dt[u], ft[u]] `->` v è un discendente di u in un albero DF

Vale anche il seguente teorema:

> Un grafo orientato è aciclico $\Leftrightarrow$ non esistono archi all’indietro nel grafo.

Vedi slide per dimostrazione. Ciò riduce di molto l'implementazione precedente: basta infatti trovare un arco all'indietro per troncare l'algoritmo e restituire true, ovvero che il grafo è ciclico. Se non viene individuato nessun'arco, ritornerà false.

```Java
boolean hasCycle(Graph G, Node u, int &time, int[ ] dt, int[ ] ft)3
```

```Ruby
time = time + 1
dt[u] = time
foreach v in G.adj(u) do
    if dt[v] == 0 then
        if hasCycle(G, v, time, dt, ft) then
            return true
    else if dt[u] > dt[v] and ft[v] == 0 then
        return true
time = time + 1
ft[u] = time
return false
```

### Ordinamento topologico

Dato un DAG G, un **ordinamento topologico** è un ordinamento lineare dei suoi nodi tale che se $(u, v) \in E$, allora $u$ è prima di $v$ nell'ordinamento.

```Java
Stack topSort(Graph G)
```

```Ruby
Stack S = Stack()
boolean[] visited = boolean[1...G.size()]
for u in G.V() do
    visited[u] = false
    if not visited[u] then
        ts-dfs(G, u, visited, S)
return S
```

```Java
ts-dfs(Graph G, Node u, boolean[] visited, Stack S)
```

```Ruby
visited[u] = true
for v in G.adj(u) do
    if not visited[v] then
        ts-dfs(G, v, visited, S)
S.push(u)
```

### Componenti fortemente connesse

- Un grafo orientato $G = (V, E)$ è fortemente connesso $\Leftrightarrow$ ogni suo nodo è raggiungibile da ogni altro suo nodo
- Un grafo $G_0 = (V_0, E_0)$ è una componente fortemente connessa di G $\Leftrightarrow$ G0 è un sottografo connesso e massimale di G.

```Java
int[] scc(Graph G)
```

```Ruby
Stack S = topSort(G) # First visit
GT = transpose(G) # Graph transposal
return cc(GT, S)
```

Utilizzando l'ordinamento topologico su un grafo generale `topSort`, siamo sicuri che restituirà un ordinamento perfetto per tempo di fine. Infatti eventuali archi di un ciclo vengono listati in un ordine ininfluente, mentre gli archi non di un ciclo saranno ordinati.

Definiamo come **grafo trasposto** un grafo orientato i cui archi sono stati invertiti di direzione.

```Java
int[] transpose(Graph G)
```

```Ruby
Graph GT = Graph()
for u in G.V() do
    GT.insertNode(u)
for u in G.V() do
    for v in G.adj(u) do
        GT.insertEdge(v, u)
return GT
```

Per quanto riguarda la visita delle componenti connesse del grafo trasposto, invece di esaminare i nodi in ordine arbitrario, questa versione di cc() li esamina nell’ordine LIFO memorizzato nello stack.

```Java
cc(Graph G, Stack S)
```

```Ruby
int[] id = new int[1...G.size()]
for u in G.V() do
    id[u] = 0
int counter = 0
while not S.isEmpty() do
    u = S.pop()
    if id[u] == 0 then
        counter = counter + 1
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

L'algoritmo in totale avrà costo computazionale pari a $O(n + m)$.