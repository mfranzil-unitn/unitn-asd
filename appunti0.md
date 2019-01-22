# Appunti di Algoritmi e Strutture Dati

- [Appunti di Algoritmi e Strutture Dati](#appunti-di-algoritmi-e-strutture-dati)
  - [13/09/2018](#13092018)
    - [Sottovettore di somma massimale - `maxsum`](#sottovettore-di-somma-massimale---maxsum)
      - [Versione $O(n^3)$](#versione-on3)
      - [Versione $O(n^2)$](#versione-on2)
      - [Versione $O(n\ logn)$](#versione-on-logn)
      - [Versione $O(n)$](#versione-on)
  - [18/09/2018](#18092018)
    - [Problemi computazionali](#problemi-computazionali)
      - [Minimo - `min`](#minimo---min)
      - [Ricerca dicotomica - `lookup`](#ricerca-dicotomica---lookup)
    - [Valutazione degli algoritmi](#valutazione-degli-algoritmi)
      - [Ricerca binaria - `binarySearch`](#ricerca-binaria---binarysearch)
    - [Analisi di algoritmi](#analisi-di-algoritmi)
      - [Dimensione dell'input](#dimensione-dellinput)
      - [Analisi dei costi elementari](#analisi-dei-costi-elementari)
      - [Ordini di complessità](#ordini-di-complessit%C3%A0)
      - [Funzioni di costo](#funzioni-di-costo)
  - [20/09/2018](#20092018)
    - [Analisi di algoritmi (cont.)](#analisi-di-algoritmi-cont)
      - [Stima dei limiti asintotici](#stima-dei-limiti-asintotici)
    - [Complessità degli algoritmi e dei problemi](#complessit%C3%A0-degli-algoritmi-e-dei-problemi)
      - [Moltiplicazione divide-et-impera - `pdi`](#moltiplicazione-divide-et-impera---pdi)
      - [Moltiplicazione di Karatsuba - `karatsuba`](#moltiplicazione-di-karatsuba---karatsuba)
    - [Algoritmi di ordinamento](#algoritmi-di-ordinamento)
      - [Tipologie di analisi](#tipologie-di-analisi)
      - [Selection Sort - `selectionsort`](#selection-sort---selectionsort)
      - [Insertion Sort - `insertionsort`](#insertion-sort---insertionsort)
  - [25/09/2018](#25092018)
    - [Algoritmi di ordinamento (cont.)](#algoritmi-di-ordinamento-cont)
      - [Merge Sort - `mergesort`](#merge-sort---mergesort)
    - [Proprietà della notazione asintotica](#propriet%C3%A0-della-notazione-asintotica)
    - [Notazioni $o,\ \omega$](#notazioni-o-omega)
    - [Classificazione delle funzioni](#classificazione-delle-funzioni)
    - [Equazioni di ricorrenza](#equazioni-di-ricorrenza)
      - [Metodo dell'albero di ricorsione / per livelli](#metodo-dellalbero-di-ricorsione--per-livelli)
  - [27/09/2018](#27092018)
    - [Equazioni di ricorrenza (cont.)](#equazioni-di-ricorrenza-cont)
      - [Metodo dell'albero di ricorsione / per livelli (cont.)](#metodo-dellalbero-di-ricorsione--per-livelli-cont)
    - [Metodo di sostituzione / per tentativi](#metodo-di-sostituzione--per-tentativi)
      - [Esempio completo](#esempio-completo)
  - [02/10/2018](#02102018)
  - [04/10/2018](#04102018)
    - [Metodo dell'esperto / delle ricorrenze comuni](#metodo-dellesperto--delle-ricorrenze-comuni)
      - [Master Theorem - versione base](#master-theorem---versione-base)
      - [Master Theorem - Versione estesa](#master-theorem---versione-estesa)
      - [Master Theorem per ricorrenze lineari di ordine costante](#master-theorem-per-ricorrenze-lineari-di-ordine-costante)
    - [Strutture dati](#strutture-dati)
    - [Tipi di dato astratti](#tipi-di-dato-astratti)
      - [Sequenza](#sequenza)
      - [Insieme](#insieme)
      - [Dizionario](#dizionario)
      - [Alberi e grafi (introduzione)](#alberi-e-grafi-introduzione)
    - [Strutture dati elementari](#strutture-dati-elementari)
      - [Lista](#lista)
      - [Pile e code](#pile-e-code)
  - [09/10/2018](#09102018)
  - [11/10/2018](#11102018)
  - [16/10/2018](#16102018)
  - [18/10/2018](#18102018)
    - [Alberi](#alberi)
      - [Albero radicato](#albero-radicato)
      - [Alberi binari](#alberi-binari)
      - [Visite degli alberi binari - `dfs`, `printExp`, `count`](#visite-degli-alberi-binari---dfs-printexp-count)
      - [Alberi generici - `bfs`, `binarybfs`](#alberi-generici---bfs-binarybfs)
    - [Memorizzazione di un albero](#memorizzazione-di-un-albero)
      - [Memorizzazione con vettore dei figli](#memorizzazione-con-vettore-dei-figli)
      - [Memorizzazione basata su primo figlio, ultimo padre](#memorizzazione-basata-su-primo-figlio-ultimo-padre)
      - [Memorizzazione con vettore dei padri](#memorizzazione-con-vettore-dei-padri)
    - [Analisi ammortizzata](#analisi-ammortizzata)
      - [Contatore binario](#contatore-binario)
      - [Vettori dinamici](#vettori-dinamici)
  - [23/10/2018](#23102018)
  - [25/10/2018](#25102018)
    - [Alberi binari di ricerca](#alberi-binari-di-ricerca)
      - [Funzioni degli alberi binari di ricerca](#funzioni-degli-alberi-binari-di-ricerca)
      - [Costo computazionale degli alberi di ricerca](#costo-computazionale-degli-alberi-di-ricerca)
    - [Alberi binari di ricerca bilanciati](#alberi-binari-di-ricerca-bilanciati)
    - [Alberi Red-Black](#alberi-red-black)
      - [Rotazioni - `rotateLeft`](#rotazioni---rotateleft)
      - [Inserimento con condizioni negli alberi RB - `balanceInsert`](#inserimento-con-condizioni-negli-alberi-rb---balanceinsert)
  - [30/10/2018](#30102018)
  - [01/11/2018](#01112018)
  - [06/11/2018](#06112018)
  - [08/11/2018](#08112018)
    - [Grafi](#grafi)
    - [Implementazione dei grafi](#implementazione-dei-grafi)
    - [Visite dei grafi](#visite-dei-grafi)
    - [BFS - `bfs`](#bfs---bfs)
      - [Numero di Erdős - `erdős`](#numero-di-erd%C5%91s---erd%C5%91s)
    - [DFS - `dfs`](#dfs---dfs)
      - [Componenti connesse - `cc`](#componenti-connesse---cc)
  - [13/11/2018](#13112018)
    - [DFS (cont.)](#dfs-cont)
      - [Grafi con cicli - `hasCycle`](#grafi-con-cicli---hascycle)
      - [Ordinamento topologico - `topSort`](#ordinamento-topologico---topsort)
      - [Componenti fortemente connesse - `scc`, `transpose`](#componenti-fortemente-connesse---scc-transpose)
  - [15/11/2018](#15112018)
  - [20/11/2018](#20112018)
  - [22/11/2018](#22112018)
    - [Hashing](#hashing)
      - [Tabelle ad accesso diretto](#tabelle-ad-accesso-diretto)
      - [Funzione hash perfetta](#funzione-hash-perfetta)
      - [Funzione di estrazione](#funzione-di-estrazione)
      - [Funzione XOR](#funzione-xor)
      - [Metodo della divisione](#metodo-della-divisione)
      - [Metodo della moltiplicazione](#metodo-della-moltiplicazione)
    - [Gestione delle collisioni](#gestione-delle-collisioni)
      - [Liste di trabocco](#liste-di-trabocco)
      - [Indirizzamento aperto](#indirizzamento-aperto)
        - [Ispezione lineare](#ispezione-lineare)
        - [Ispezione quadratica](#ispezione-quadratica)
        - [Doppio hashing](#doppio-hashing)
      - [Complessità](#complessit%C3%A0)
  - [27/11/2018](#27112018)
  - [29/11/2018](#29112018)
  - [4/12/2018](#4122018)
  - [6/12/2018](#6122018)
    - [Risoluzione di problemi generali](#risoluzione-di-problemi-generali)
    - [Divide et impera](#divide-et-impera)
    - [Torre di Hanoi - `hanoi`](#torre-di-hanoi---hanoi)
    - [Quicksort - `quicksort`](#quicksort---quicksort)
    - [Moltiplicazione di matrici - `strassen`](#moltiplicazione-di-matrici---strassen)
    - [Gap](#gap)
  - [Insiemi e dizionari (cont.)](#insiemi-e-dizionari-cont)
  - [11/12/2018](#11122018)
  - [13/12/2018](#13122018)
  - [18/12/2018](#18122018)
    - [Bloom Filter](#bloom-filter)

## 13/09/2018

(....) aggiungere introduzione

### Sottovettore di somma massimale - `maxsum`

Esempio fornito all'inizio della lezione come esempio di ottimizzazione di un algoritmo.

#### Versione $O(n^3)$

```python
def _sum(a, i, j):
    return sum(a[i:j+1])

def maxsum3(a):
    max_so_far = 0
    for i in range(0, len(a)):
        for j in range(i, len(a)):
            max_so_far = max(_sum(a, i, j), max_so_far)
    return max_so_far
```

#### Versione $O(n^2)$

```python
def maxsum2(a):
    max_so_far = 0
    for i in range(0, len(a)):
        sum = 0
        for j in range(i, len(a)):
            sum += a[j]
            max_so_far = max(max_so_far, sum)
    return max_so_far
```

Vedi slide per versione con libreria `accumulate`.

#### Versione $O(n\ logn)$

```python
def maxsum_rec(A,i,j):
    if (i==j):
        return max(0, A[i])
    m = (i+j)//2
    maxLL = 0 # Maximal subvector on the left ending in m
    sum = 0
    for k in range(m, i-1,-1):
        sum = sum + A[k]
        maxLL = max(maxLL, sum);
    maxRR = 0 # Maximal subvector on the right starting in m+1
    sum = 0
    for k in range(m+1,j+1):
        sum = sum + A[k]
        maxRR = max(maxRR, sum);
    maxL = maxsum_rec(A, i, m) # Maximal subvector on the left
    maxR = maxsum_rec(A, m+1, j) # Maximal subvector on the right
    return max(maxL, maxR, maxLL + maxRR)

def maxsum3(A):
    return maxsum_rec(A,0,len(A)-1)
```

#### Versione $O(n)$

```Java
int maxsum4(int A[], int n) {
    int maxSoFar = 0;
    int maxHere = 0;
    for (int i = 0; i < n; i++) {
        maxHere = max(maxHere + A[i], 0);
        maxSoFar = max(maxSoFar, maxHere);
    }
    return maxSoFar;
}
```

Vedi slide per versione 4 con restituzione di coppia di indici.

## 18/09/2018

### Problemi computazionali

__Problema computazionale__: Rappresentato da una relazione matematica che associa gli elementi dei domini di input e output.

__Algoritmo__: Un procedimento effettivo che risolve il problema in un tempo finito.

Esempi di problemi computazionali possono essere il minimo e la ricerca. Esprimere tali problemi in italiano si rivela tuttavia impreciso e poco formale. Utilizzeremo una descrizione molto più formale con lo *pseudo-codice*.

Vedi slide per esempi sulla sintassi dello pseudo-codice. Seguono i due algoritmi visti a lezione scritti in pseudo-codice.

#### Minimo - `min`

```Java
int min (int[] s, int n)
```

```Coffee
int minSoFar = s[1]
for i = 2 to n do
    if s[i] < minSoFar then
        minSoFar = s[i]

return minSoFar
```

#### Ricerca dicotomica - `lookup`

```Java
int lookup(int[] S, int n, int v)
```

```Coffee
for i = 1 to n do
    if S[i] == v then
        return i
return 0
```

### Valutazione degli algoritmi

Gli algoritmi risolvono il problema in maniera efficiente (soluzioni ottime) e corretta (con descrizione matematica formale, quando possibile)?

Definiamo la __complessità di un algoritmo__:
> L'analisi delle risorse impiegate (tempo, spazio e banda) per risolverlo in funzione di tipo e dimensione dell'input.

Definiamo il tempo come il _numero di operazioni rilevanti_ al fine della soluzione (nel caso del minimo, numero di operazioni `<=`, oppure operazioni `==` per la ricerca).

#### Ricerca binaria - `binarySearch`

```Java
int binarySearch(int[] S, int v, int i, int j)
```

```Coffee
if i > j then
    return 0
else
    int m = floor((i + j)/2)
    if S[m] == v then
        return m
    else if S[m] < v then
        return binarySearch(S, v, m + 1, j)
    else
        return binarySearch(S, v, i, m - 1)
```

Utilizziamo i concetti di __invariante__, una condizione sempre vera in un punto del programma, __invariante di ciclo__ una condizione vera all'inizio di un ciclo, e __invariante di classe__, una condizione vera alla fine di un metodo di una classe. Il concetto di *invariante di ciclo* aiuta a dimostrare la correttezza di un algoritmo iterativo:

- Caso base `->` inizializzazione
- Passo induttivo `->` conservazione
- Conclusione

Altre proprietà degli algoritmi che sono secondarie in un corso di algoritmi sono semplicità, modularità.

### Analisi di algoritmi

#### Dimensione dell'input

Definiamo la dimensione dell'input con due criteri, il criterio di __costo logaritmico__ (il numero di bit per rappresentarlo) e di __costo uniforme__ (il numero di elementi). Definiamo allora il tempo come il numero di istruzioni elementari, come:

```javascript
a *= 2
Math.cos(d)
min(A, n)
```

In una rappresentazione astratta di un calcolatore, non abbiamo necessità di aggiungere dettagli sul processore ma dobbiamo nascondere i dettagli.

Considereremo la RAM come infinita, di dimensione costante e con costo d'accesso costante.

#### Analisi dei costi elementari

Nell'analisi di un algoritmo, non andremo a considerare i costi singoli delle istruzioni (ogni tipo di istruzione ha potenzialmente un tempo di esecuzione diverso, vedi slide), in quanto ininfluenti rispetto al numero di volte che le stesse vengono eseguite. Inoltre interessa molto di più l'analisi del caso pessimo rispetto al caso migliore.

Nei casi degli algoritmi ricorsivi, dobbiamo andare a contare anche un costo fisso di chiamata della funzione sullo stack. Alla fine si ottiene una funzione ricorsiva detta __relazione di ricorrenza__. Da essa si ottiene la forma chiusa che rappresenta la complessità dell'algoritmo in questione, applicando la funzione in maniera ricorsiva (vedi slide)

#### Ordini di complessità

<center>

|           |            |       |    Ordini    |       |       |       |
| :-------: | :--------: | :---: | :----------: | :---: | :---: | :---: |
| $\log(n)$ | $\sqrt{n}$ |  $n$  | $n\log(n)$ | $n^2$ | $n^3$ | $2^n$ |

</center>

#### Funzioni di costo

Utilizziamo il termine funzione di costo per una funzione $f: \mathbb{N}\Longrightarrow \mathbb{R}$

Sia ora $g(n)$ una funzione di costo.

__Limite asintotico superiore__:

Indichiamo con $O(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\exists c > 0, \exists m \ge 0 : f(n) \le c g(n), \forall n \ge m$$
ovvero è un limite asintotico superiore, e $f(n)$ cresce al più come $g(n)$.

__Limite asintotico inferiore__:

Indichiamo con $\Omega(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\exists c > 0, \exists m \ge 0 : f(n) \ge c g(n), \forall n \ge m$$
ovvero è un limite asintotico inferiore, e $f(n)$ cresce almeno quanto $g(n)$.

__Limite asintotico superiore e inferiore__:

Indichiamo con $\Theta(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\exists c > 0, \exists m \ge 0 :c_1 g(n) \le f(n) \le c_2 g(n), \forall n \ge m$$
ovvero, grazie al teorema dei Carabinieri, $f(n)$ cresce esattamente come $g(n)$.

## 20/09/2018

### Analisi di algoritmi (cont.)

#### Stima dei limiti asintotici

Per dimostrare $\Theta(n)$, dimostreremo sia la validità del limite inferiore sia del limite superiore tramite semplici disequazioni (vedi slide 22-23-24). Ai fini della dimostrazione non è importante ottenere una stima troppo precisa, ma semplicemente ottenere una stima asintotica inferiore e superiore sullo stesso ordine di grandezza.

### Complessità degli algoritmi e dei problemi

Riflettiamo ora sulla complessità dei problemi e degli algoritmi. E' possibile fare di meglio degli algoritmi umani (somma, moltiplicazione) usati tutti i giorni?

__Moltiplicazione dei numeri complessi__:
$$(a+bi)(c+di) \ = \ [ac-bd] + [ad+bc]i$$
> Output: ac - bd, ad + bc

Consideriamo un modello (simile a uno "umano", posto per esempio nel 1640, data di nascita della parola "computer") dove le moltiplicazioni costano `1` e le addizioni e sottrazioni `0.01`. Allora l'algoritmo visto sopra costa `4.02`. Si può fare di meglio (non considerando la moltiplicazione come somma ripetuta, che è ininfluente per input grandi)?

Consideriamo ora il principio messo in pratica da Gauss:

```Coffee
m2 = a * c
m3 = b * d
m1 = (a + b) * (c + d)
```

> Output m2 - m3, m1 - m2 - m3

Effettuare tre moltiplicazioni anzi che quattro può offrire un risparmio del 25% nel nostro modello.

Consideriamo ora l'algoritmo della somma elementare `sum`. Richiede di esaminare tutti i bit e ha un costo totale $cn$ (dove $cn \equiv$ costo per sommare e generare riporto). Si piò dimostrare per assurdo che NON esiste un metodo più efficiente (infatti tutti i bit vanno visitati almeno una volta).

> Il problema della somma di numeri binari ha complessità $\Theta(n)$.

Si ha che un problema ha complessità $O(f(n))$ se esiste almeno un algoritmo che lo risolve con complessità $O(f(n))$. Si ha che un problema ha complessità $\Omega(f(n))$ se tutti gli algoritmi che lo risolvono hanno al massimo complessità $\Omega(f(n))$.

Analogamente possiamo discutere della complessità della moltiplicazione. Si dimostra che la moltiplicazione ha complessità $O(n^2)$, perlomeno con l'algoritmo studiato alle elementari.

#### Moltiplicazione divide-et-impera - `pdi`

Usiamo la tecnica divide-et-impera per affrontare questo problema e *provare* a trovare un algoritmo che abbia complessità sotto $\Omega(n^2)$. Dividiamo i nostri numeri binari in due parti:

$$X = a 2^{n/2} + b\\
Y = c 2^{n/2} + d\\
XY = ac2^n + (ad + bc) 2 ^ {n/2} + bd$$

```Java
bool[] pdi(bool[] X, bool[]y, int n)
```

```Coffee
if n == 1 then
    return X[1] * Y[1]
else
    spezza X in (a, b), Y in (c, d)  # Divide
    return pdi(a, c, n/2) * 2^n + pdi(a, d, n/2) +  # Impera
           pdi(b, c, n/2) * 2^n + pdi(b, d, n/2)
```

Grazie alle moltiplicazioni per $2^n$ che vengono risolte in tempo lineare, così come le somme, otteniamo una funzione di ricorrenza (vedi slide 41) che viene ridotta nuovamente a una funzione di costo $O(n^2)$, rendendo di fatto inutile questa applicazione del divide et impera.

#### Moltiplicazione di Karatsuba - `karatsuba`

Usiamo lo stesso principio di Gauss visto in precedenza per ridurre il numero di moltiplicazioni richieste a tre, riducendo di fatto anche la complessità.

```Java
bool[] karatsuba(bool[] X, bool[] Y, int n)
```

```Coffee
if n == 1 then
    return X[1] * Y[1]
else
    spezza X in (a, b) e Y in (c, d)
    bool[] A1 = karatsuba(a, c, n/2)
    bool[] A3 = karatsuba(b, d, n/2)
    bool[] m = karatsuba(a + b, c + d, n/2)
    bool[] A2 = m - A1 - A3
    return A1 * 2^(n/2) + A2 * 2^(n/2) + A3
```

Questo algoritmo ha complessità $n^{1.58}$. Esistono comunque altri algoritmi (Toom-Cook, Fürer, che vengono usati, a causa dei fattori moltiplicativi, solo per numeri molto grandi) che hanno ulteriormente abbassato la complessità della moltiplicazione, e si suppone che la moltiplicazione ha un limite inferiore pari a $\Omega(n\log(n))$.

### Algoritmi di ordinamento

Valuteremo ora gli algoritmi di ordinamento in base a dimensione e tipologia dell'input. Conoscere il tipo dell'input porta a scelte diverse sull'algoritmo da usare.

#### Tipologie di analisi

- __Caso pessimo__: il tempo di esecuzione nel caso peggiore (ordinamento inverso); sarà il nostro limite superiore.
- __Caso medio__: difficile in aucuni casi, corrispondente a un input con distribuzione uniforme.
- __Caso ottimo__: utile se si hanno informazioni particolari

Il problema da risolvere è il seguente:
> Data una sequenza $A$ di n valori, ottenere una sequenza $B$ permutazione dell'input tale che $\forall b \in b, b_1 \le b_2 \le ... \le b_n$.

#### Selection Sort - `selectionsort`

```Java
selectionSort(T[] A, int n)
```

```Coffee
for i = 1 to n - 1 do
    int min = min(A, i, n)
    A[i] => A[min]
```

L'algoritmo ha una complessità pari a $\Theta(n^2)$.

#### Insertion Sort - `insertionsort`

```Java
insertionSort(T[] A, int n)
```

```Coffee
for i = 2 to n do
    T temp = A[i]
    int j = i
    while j > 1 and A[j - 1] > temp do
        A[j] = A[j - 1]
        j = j - 1
    A[j] = temp
```

Questo algoritmo costa in media e nel caso pessimo $O(n^2)$, ma nei casi migliori si avvicina a $O(n)$. Funziona molto bene per sequenze relativamente piccole.

## 25/09/2018

### Algoritmi di ordinamento (cont.)

#### Merge Sort - `mergesort`

Dato un vettore di $n$ interi, andiamo a usare la tecnica divide et impera per ordinare il vettore. Usiamo come appoggio il metodo `merge()` che dato in input un vettore di $n$ interi contenente due sottovettori di interi già ordinati, fornisce in output un vettore ordinato tramite un vettore di appoggio $B$.

> Nell'implementazione del programma, abbiamo un singolo vettore d'appoggio $B$ lungo $n$ che viene utilizzato durante tutta l'esecuzione del programma.

```Java
merge(int A[], int first, int last, int mid)
```

```Coffee
int i, j, k, h
i = first
j = mid + 1
k = first

while i <= mid and j <= last do
    if A[i] <= A[j] then
        B[k] = A[i]
        i = i + 1
    else
        B[k] = A[j]
        j = j + 1
    k = k + 1

j = last

for h = mid downto i do
    A[j] = A[h]
    j = j - 1

for j = first to k - 1 do
    A[j] = B[j]
```

`merge` ha un costo computazionale di $\Theta(n)$. Il resto dell'algoritmo si basa appunto sulla tecnica divide-et-impera ricorsiva; il caso base è dato da vettori di lunghezza 1.

```Java
mergeSort(int A[], int first, int last)
```

```Coffee
if first < last then
    int mid = floor((first + last)/2)
    mergeSort(A, first, mid)
    mergeSort(A, mid + 1, last)
    merge(A, first, last, mid)
```

Per l'analisi della complessità, l'labero di suddivisioni sarà alto $k = \log n$. L'equazione di ricorrenza si presenta simile agli altri algoritmi divide-et-impera:

$$T(n) = \left\{
\begin{array}{lc}
    c & n = 1 \\
    2T(n/2) + dn & n> 1
\end{array}\right.$$

### Proprietà della notazione asintotica

Torniamo ora sulle proprietà della notazione asintotica viste in precedenza. Definiamo __algoritmo ottimo__ un algoritmo $$\Theta(f(n))$ ovvero un algoritmo che si comporta allo stesso modo a prescindere dall'input.

**Costo delle epressioni polinomiali**:
> Data $f(n)$ funzione polinomiale, si dimostra che $f(n) = \Theta(n^k)$

**Dualità**:
> $$f(n) = O(g(n)) \Leftrightarrow g(n) = \Omega(f(n))$$

**Eliminazioni delle costanti**:
> Le costanti non sono considerate nella notazione asintotica e scritture come $f(n)$ e $af(n)$ sono equivalenti a $O(g(n))$.

**Sommatoria**:
> $$f_1(n) = O(g_1(n)),\ f_2(n) = O(g_2(n)) \\ \Rightarrow f_1(n) + f_2(n) = O(\max(g1(n), g2(n)))$$
> La stessa proprietà vale anche per $\Omega(n)$.

**Cicli annidati**:
> $$f_1(n) = O(g_1(n)),\ f_2(n) = O(g_2(n)) \\ \Rightarrow f_1(n) \cdot f_2(n) = O(g1(n) \cdot g2(n))$$
> La stessa proprietà vale anche per $\Omega(n)$.

**Simmetria**:
> $$f(n) = \Theta(g(n)) \Leftrightarrow g(n) = \Theta(f(n))$$

**Transitività**:
> $$f(n) = O(g(n)),\ g(n) = O(h(n)) \Leftrightarrow f(n) = O(h(n))$$

Vedi slide per ulteriori proprietà di logaritmi e esponenziali.

### Notazioni $o,\ \omega$

Sia $g(n)$ una funzione di costo; indichiamo con $o(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\forall c,\ \exists m : f(n) < cg(n), \forall n \ge m$$

Sia $g(n)$ una funzione di costo; indichiamo con $\omega(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\forall c,\ \exists m : f(n) > cg(n), \forall n \ge m$$

### Classificazione delle funzioni

Possiamo ora trarre un ordinamento delle principali espressioni viste fin'ora:
$$\forall r < s,\ h < k, \ a < b:$$
$$O(1) \subset O(\log^r n) \subset O(\log^s n) \subset O(n^h) \subset O(n^h \log^r n)\\ \subset O(n^h log^s n) \subset O(n^k) \subset O(a^n) \subset O(b^n)$$

### Equazioni di ricorrenza

Si ottengono calcolando la complessità di un algoritmo ricorsivo. L'obiettivo è ottenere una *forma chiusa* che rappresenti la complessità. Utilizzeremo le equazioni di ricorrenza anche per risolvere problemi.

__Problema__: Un bambino scende una scala composta da n scalini. Ad ogni passo, può decidere di fare 1, 2, 3, 4 scalini alla volta. Determinare in quanti modi diversi può scendere le scale.

Una possibile soluzione può essere una funzione ricorsiva che conta a ogni passo il numero di modi possibili, con due casi base, uno quando si hanno terminato gli scalini (con un modo possibile) e uno quando si "sfora" (con zero modi).

Distinguiamo ora tre metodi per le risolvere le ricorrenze.

#### Metodo dell'albero di ricorsione / per livelli

Si "srotola" la ricorrenza in un albero (o in una tabella), andando a ricavare un modello matematico che rispetti l'equazione data. Una volta arrivati al caso base, si valutano i costi delle chiamate comprimendoli in una sommatoria per poi usare passaggi algebrici (segue).

## 27/09/2018

### Equazioni di ricorrenza (cont.)

#### Metodo dell'albero di ricorsione / per livelli (cont.)

(cont.) Bisogna fare estrema attenzione ai fattori moltiplicativi associati alle chiamate ricorsive in quanto si ripercuotono su tutta la chiamata. All'arrivo del caso base ($T(1)$) si ottengono generalmente $\log (n) + 1$ elementi di cui l'ultima conterrà $T(1)$, e le altre si potranno condensare in una serie matematica.

Un metodo alternativo, usato per casi più complicati, è cercare di visualizzare graficamente l'albero delle chiamate oppure utilizzare una tabella; ad esempio per un'equazione di ricorrenze del tipo

$$T(n) = \left\{
\begin{array}{lc}
    1 & n \le 1 \\
    4T(n/2) + n^3 & n> 1
\end{array}\right.$$

abbiamo:

<center>

| Livello | Dim.  | Costo chiam. | # chiamate | Costo livello |
| ------- | ----- | ------------ | ---------- | ------------- |
| $0$     | $n$   | $n^3$        | 1          | $n^3$         |
| $1$     | $n/2$ | $(n/2)^3$    | $4$        | $4(n/2)^3$    |
| ...     | ...   | ...          | ...        | ...           |

</center>

Una volta scritta la tabella si può tornare alla forma in sommatoria ed eventualmente gestire la complessità tramite un limite superiore o inferiore. Per ottenere la sommatoria non si fa altro che sommare tutti i termini presenti nella colonna *costo livello*.

### Metodo di sostituzione / per tentativi

Si cercare di "indovinare" la complessità dell'algoritmo e si procede con una dimostrazione induttiva per verificare quanto detto.

> Reminder: Le equazioni del tioo $cT(\cdot \cdot \cdot) + n^{\alpha}$ sono sempre $\Omega(n^{\alpha})$

A volte le assunzioni, pur risultando valide, possono fallire sotto certi aspetti (ad esempio un termine di ordine inferiore che rende invalida una disequazione). In tali casi è opportuno effettuare una dimostrazione sottraendo il termine di ordine inferiore nell'ipotesi, ad esempio:
$$\exists c > 0, \exists m \ge 0 : T(n) \le cn, \forall n \ge m$$
Ipotesi possibili:
$$\forall k < n : T(k) \le ck \qquad\ \quad\text{fallisce}\\
  \forall k < n : T(k) \le ck - b \qquad \text{ funziona}$$

Altre volte, invece, si possono presentare problemi con il caso base $T(0)$ (ovvero che la dimostrazione fallisce, ad esempio per colpa di un logaritmo). Grazie all'arbitrarietà di $m$, possiamo andare a dimostrare i vari casi base ($T(1), T(2)...$) che dipendono ancora da $T(0)$ finché non si esauriscono. Si ottengono quindi diversi $c$ dalla quale poi si sceglie il maggiore.

Bisogna infine fare attenzione ad ipotizzare soluzioni troppo strette. Infatti, data un'equazione di ricorrenza,

> la sua complessità $\Omega(f(x))$ sarà sempre almeno pari alla componente non ricorsiva.

#### Esempio completo

$$S = \left\{
\begin{array}{lc}
    9T(\lfloor n/3\rfloor ) + n & n> 1 \\
    1 & n \le 1
\end{array}\right.$$

Proviamo con $T(n) = O(n^2)$.
$$\Leftarrow \exists c > 0, \exists m \ge 0 : T(n) \le cn^2, \forall n \ge m$$

**Ipotesi induttiva**: $\exists c > 0 : T(k) \le c(k^2 - k), \forall k < n$ (sottraiamo il termine di ordine 1 per far funzionare la dimostrazione).

**Passo induttivo**: Dimostriamo ora:
$$
T(n) = 9T(\lfloor n/3\rfloor) + n \\
\le 9c(\lfloor n/3\rfloor ^2 - \lfloor n/3 \rfloor) + n  \\
\le cn^2 - 3cn + n \\ \le cn^2 - cn \Leftrightarrow c \le \frac{1}{2} $$

**Passo base**:
$T(1)$ risulta falso, si prosegue fino a $T(5)$.

## 02/10/2018

Esercitazione svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 04/10/2018

### Metodo dell'esperto / delle ricorrenze comuni

#### Master Theorem - versione base

> Siano $a, b$ costanti $\in \mathbb{Z}$ tali che $a \ge 1, b \ge 2$, $c, \beta$ costanti $\in \mathbb{R}$ tali che $c \ge 0, \beta \ge 0$. Sia $T(n)$ una funzione di ricorrenza del tipo:

$$T(n) = \left\{
\begin{array}{lc}
    aT(n/b) + cn^{\beta} & n> 1 \\
    d & n \le 1
\end{array}\right.$$

> Allora, posto $\alpha = \log{a}/ \log{b} = \log_b{a}$,

$$T(n) = \left\{
\begin{array}{lc}
    \Theta (n^{\alpha}) & \alpha > \beta \\
    \Theta (n^{\alpha}\log{n}) & \alpha = \beta \\
    \Theta (n^{\beta}) & \alpha < \beta
\end{array}\right.$$

Assumiamo che $n$ sia una potenza intera di $b$ per semplificare i calcoli (ciò non influisce comunque sul risultato a meno di una costante moltiplicativa che ignoriamo nella notazione asintotica). Inoltre assumiamo che la dimensione dell'input sia pari a $n = b^k$. Vedi slide per lo srotolamento dell'albero di ricorrenza.

Si ottiene al termine dell'albero una formula del tipo:
$$T(n)\ = \ da^k + cb^{k\beta} \sum^{k-1}_{i = 0} \frac{a^i}{b^{i\beta}}$$

Tramite opportuni passaggi algebrici otteniamo che $a^k = n^\alpha, \ a = \beta^{\alpha}, \ q = b^{\alpha - \beta}$. Otteniamo:

$$T(n)\ = \ dn^{\alpha} + cb^{k\beta} \sum^{k-1}_{i = 0} q^i$$

Possiamo distinguere tre casi a seconda del valore di q. Vedi slide per dimostrazioni sui singoli casi.

#### Master Theorem - Versione estesa

Possiamo infine estendere il teorema precedente in questa maniera:

> Sia $a \ge 1, b > 1, f(n)$ asintoticamente positiva e sia:

$$T(n) = \left\{
\begin{array}{lc}
    aT(n/b) + f(n) & n> 1 \\
    d & n \le 1
\end{array}\right.$$

> Allora, sono dati tre casi:

| Caso | Condizione                                                                                                                                                |                                 | Risultato                     |
| ---- | --------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------- | ----------------------------- |
| (1)  | $\exists \epsilon > 0: f(n) = O(n^{\log_b{a - \epsilon}})$                                                                                                | $\qquad \Longrightarrow \qquad$ | $T(n) = \Theta(n^{log_b{a}})$ |
| (2)  | $f(n) = \Theta(n^{log_b{a}})$                                                                                                                             | $\qquad \Longrightarrow \qquad$ | $T(n) = \Theta(f(n) \log n)$  |
| (3)  | $\exists \epsilon > 0 : f(n) = \Omega(n^{log_b{a+\epsilon}})\\ \wedge \exists c : 0 < c < 1, \exists m > 0:\text{} \\ af(n/b) \le cf(n), \forall n \ge m$ | $\qquad \Longrightarrow \qquad$ | $T(n) = \Theta(f(n))$         |

#### Master Theorem per ricorrenze lineari di ordine costante

> Siano $a_1, a_2, ... a_h$ costanti intere non negative con $h$ costante positiva, $c$ e $\beta$ costanti reali tati che $c > 0, \beta \ge 0$, e sia $T(n)$ definita da:

$$T(n) = \left\{
\begin{array}{lc}
    \sum_{1\le i \le h} a_i T(n-i) + cn^{\beta} & n> m \\
    \Theta(1) & n \le m \le h
\end{array}\right.$$

> Posto $a = \sum_{1\le i \le h} a_i$ vale:
>
> (1) $T(n)$ è $\Theta(n^{\beta + 1})$, se $a = 1$,
>
> (2) $T(n)$ è $\Theta(a^n n^{\beta})$, se $a \ge 2$.

### Strutture dati

__Dato__: un valore che una variabile puà assumere

__Tipo di dato astratto__: Un modello matematico, dato da una collezione di valori e un insieme di operazioni ammesse su questi valori

__Strutture di dati__: Le strutture di dati sono collezioni di dati, caratterizzate da una specifica organizzazione. Sono divise in lineari / non lineari (con presenza di una sequenza); statiche / dinamiche (ovvero a seconda della variazione di dimensione e del contenuto) e infine omogenee / disomogenee (a seconda dei dati contenuti, se sono uguali o meno)

### Tipi di dato astratti

#### Sequenza

Una struttura dati dinamica e lineare rappresentante una sequenza ordinata di valori, dove un valore può comparire una o più volte. Nei linguaggi di programmazione può essere implementata tramite un *vettore* o tramite una *lista*.

Sono ammesse le seguenti operazioni:

- Aggiunta o rimozione di elementi in testa, coda o tramite indice
- Controllo se la sequenza è vuota o piena
- Accesso tramite indice oppure alla testa/coda

#### Insieme

Una struttura dati dinamica e *non* lineare che memorizza una collezione non ordinata di elementi che appaiono al massimo una volta.

Sono ammesse le seguenti operazioni:

- Operazioni di inserimento, cancellazione e verifica
- Ordinamento
- Operazioni insiemistiche di unione e intersezione, etc...
- Iteratori

#### Dizionario

Una struttura dati implementante una relazione $\mathbf{R}: D \rightarrow C$ detta associazione chiave-valore.

Sono ammesse le seguenti operazioni:

- Inserimento e rimozione di valori tramite chiave (con eventuale sovrascrittura)
- Accesso ai valori tramite chiave (o nil)

I concetti di sequenza, insieme e dizionario sono collegati e infatti nei vari linguaggi di programmazione si tende a confondere le varie implementazioni e i vari nomi. Bisogna tuttavia fare attenzione al tipo di struttura del linguaggio usata per implementare un certo TDA. Ad esempio, un dizionario implementato come HashMap avrà complessità $O(1)$ nella ricerca dicotomica e $O(n)$ nella ricerca del minimo, un dizionario implementato come albero avrà invece $O(\log n)$ per la ricerca e $O(1)$ per il minimo.

#### Alberi e grafi (introduzione)

Un __albero__ ordinato è dato da un insieme finito di elementi detti __nodi__. Uno di questi è designato come __radice__. I rimanenti sono detti __sottoalberi__ e possono essere partizionati.

Un __grafo__ è una struttura dati composta da un insieme di elementi detti __nodi__ e un insieme di coppie di nodi detti __archi__.

Tutte le operazioni ruotano intorno alla possibilità di effettuare visite.

### Strutture dati elementari

#### Lista

Una sequenza di nodi contenenti dati e 1-2 puntatori agli elementi successivi e precedenti. I dati non devono essere necessariamente contigui in memoria e ogni operazione ha costo $O(1)$. Le liste possono essere implementate in maniera monodirezionale (un singolo puntatore al successivo), bidirezionale (doppio puntatore, es. LinkedList), bidirezionale circolare (con puntatori tra ultimo e primo) e con sentinella (una cella vuota legata al primo elemento della lista).

#### Pile e code

Una __pila__ è una struttura dati dinamica e lineare la cui politica di cancellazione e inserimento elementi segue __LIFO__ (Last In, First Out).

Una __coda__ è simile alla __pila__ ma implementa invece la politica __FIFO__ (First In, First Out).

Entrambi i tipi di dato possono essere implementati tramite liste bidirezionali o vettori circolari.

## 09/10/2018

Lezione di Laboratorio svolta in Aula A101. Nessun nuovo argomento di teoria trattato. Riferire alle slide apposite.

## 11/10/2018

Lezione cancellata per pausa lauree.

## 16/10/2018

Esercitazione svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 18/10/2018

### Alberi

Come visto nella lezione precedente, un'albero è un grafo con $n - 1$ nodi e senza cicli. 

Possiamo trovare all'interno di ambiti informatici o meno tantissimi esempi di alberi; ad esempio, l'albero genealogico, così come la struttura di una pagina HTML può essere rappresentata con un albero. In questo corso ci concentreremo soprattutto sugli alberi radicati e binari.

#### Albero radicato

Un **albero radicato** è un particolare tipo di albero nella quale un certo nodo è designato come **radice**, ogni nodo ha esattamente un arco entrante (eccetto la radice), esiste un cammino unico tra un nodo e l'altro, e l'albero è connesso.

Definiamo come **profondità** la lunghezza del cammino dalla radice al nodo misurato in numero di archi; **livello** l'insieme di nodi alla stessa profondità; **altezza** la profondità massima.

#### Alberi binari

Un **albero binario** è un albero radicato in cui ogni nodo ha al massimo due figli, identificati come *sinistro* e *destro*. Vedi slide per implementazione della struttura dati

#### Visite degli alberi binari - `dfs`, `printExp`, `count`

Un albero binario può essere visitato *in profondità* (ovvero ricorsivamente sui sottoalberi) oppure *in ampiezza* (ovvero per livello).

Per la visità in profondità, si usa una *pila* per gestire le chiamate ricorsive.

```Java
dfs(Tree t)
```

```Coffee
if t != nil:
    # pre-order visit of t
    dfs(t.left())
    # in-order visit of t
    dfs(t.right())
    # post-order visit of t
```

La post-visita può essere applicata per il conteggio dei nodi di un dato albero.

```Java
count(Tree t)
```

```Coffee
if T == nil then
    return 0
else
    cl = count(T.left())
    cr = count(T.right())
return cl + cr + 1
```

L'in-visita può essere applicata per stampare espressioni matematiche. Un'espressione matematica puà essere infatti sintetizzata tramite un albero binario nella quale le foglie sono numeri e i padri sono operazioni. Il corso computazionale è generalmente $\Theta(n)$.

```Java
printExp(Tree t)
```

```Coffee
if T.left() == nil and T.right == nil then
    print(T.read())
else
    print("(")
    printExp(T.left())
    print(T.value())
    printExp(T.right())
    print(")")
```

#### Alberi generici - `bfs`, `binarybfs`

Un albero generico differisce dagli alberi binari in quanto può avere un numero arbitrario di figli. L'implementazione nel codice differisce per l'uso di iteratori per scorrere in tutti i sottoalberi, dato un certo nodo.

Vediamo ora la visita in ampiezza di un albero generico che è perfettamente applicabile anche a quelli binari. Si utilizza una coda per gestire i nodi da visitare.

```Java
bfs(Tree t)
```

```Coffee
Queue Q = Queue()
Q.enqueue(t)
while not Q.isEmpty() do
    Tree u = Q.dequeue()
    # visita per livelli dal nodo u
    u = u.leftmostChild()
    while u != nil do
        Q.enqueue(u)
        u = u.rightSibling()
```

Segue invece l'implementazione binaria.

```Java
binarybfs(Tree t)
```

```Coffee
Queue Q = Queue()
Q.enqueue(t)
while not Q.isEmpty() do
    Tree u = Q.dequeue()
    # visita per livelli dal nodo u
    if u.left() != nil then
        Q.enqueue(u.left())
    if u.right() != nil then
        Q.enqueue(u.right())
```

### Memorizzazione di un albero

#### Memorizzazione con vettore dei figli

In ogni nodo, è presente un puntatore al nodo padre e ai singoli figli. Generalmente viene usato quando si sa in anticipo quanti figli può avere un nodo, ma può comportare spazio sprecato.

#### Memorizzazione basata su primo figlio, ultimo padre

In questa implementazione ogni nodo contiene un puntatore al padre, un puntatore al nodo successivo sullo stesso livello e un puntatore al primo figlio (quello può a sinistra)

#### Memorizzazione con vettore dei padri

In questa implementazione si usa una matrice di N righe e 2 colonne, dove si inseriscono i dati a sinistra e l'indice della posizione del padre a destra.

### Analisi ammortizzata

Una tecnica di analisi di complessità che valuta il tempo nel caso pessimo di una sequenza di operazioni. Se le operazioni più costose sono poco frequenti vengono ammortizzate da quelle meno costose e più frequenti. Differisce sostanzialmente dal caso medio, che è probabilistico e considera le singole operazioni.

Distinguiamo tre metodi per l'analisi ammortizzata:

- **Metodo dell'aggregazione**: si calcola $T(n)$ nel caso pessimo per n operazioni e si divide per n.
- **Metodo dell'accantonamento**: si assegnano costi ammortizzati alle singole operazioni che possono essere maggiori o minori del loro effettivo costo
- **Metodo del potenziale**: lo stato del sistema viene descritto tramite una funzione di differenza di potenziale.

#### Contatore binario

Una struttura dati dotata di un'operazione singola, ovvero incrementare il numero contenuto in sè stesso. E' fatto da un vettore di booleani (0, 1) dove in A[0] abbiamo il meno significativo, A[n - 1] il più significativo.

Con il **metodo dell'aggregazione** consideriamo la peggior sequenza di operazioni e sommiamo le complessità individuali: otteniamo che l'algoritmo di incremento ha una complessità $O(nk)$ in quanto ogni chiamata ha complessità $O(k)$, dove k è definito come il numero di bit necessari a rappresentare n. Possiamo tuttavia notare che la stima di k modifiche ogni volta è poco corretta in quanto, dato l'elemento $i$, verrà modificato al massimo ogni $2^i$ incrementi. Otteniamo quindi che il costo totale è pari a $O(2n)$ e il costo ammortizzato è pari a $O(1)$.

Con il **metodo degli accantonamenti** assegniamo un costo ammortizzato che potrebbe cambiare da operazione a operazione. Eventuali costi extra sono chiamati *crediti* che vengono accumulati quando la differenza tra il costo effettivo e quello ammortizzato è positiva, e vengono "spesi" quando è negativa. Se riusciamo a dimostrare che il costo ammortizzato è migliore di quello effettivo, abbiamo ottenuto un limite superiore migliore per la struttura dati. La dimostrazione deve valere per tutte le sequenze e il credito accumulato alla fine della dimostrazione deve essere positivo. Abbiamo che il costo effettivo di `increment` è pari a $d$ dove $d < k$ è il numero di bit che cambiano valore, il costo ammortizzato sarà pari a 2, uno per ogni cambio di bit e uno anticipato per quando lo stesso bit sarà settato a 0.

Con il **metodo del potenziale** assegnamo alla struttura dati una funzione di potenziale $\Phi(D)$ che viene decrementata dalle operazioni costose e incrementata da quelle meno costose. Il costo ammortizzato sarà pari a

$$a_i = c_i + \Phi(D_i) - \Phi(D_{i-1})$$

dove $D_i$ è il potenziale associato all'i-esima operazione. Nel nostro caso $\Phi(D)$ sarà il numero di bit 1 presenti nel contatore, all'inizio 0. `increment` avrà come costo effettivo $1+t$, come variazione di potenziale $1-t$ e come costo ammortizzato la somma, ovvero $2$. Alla fine degli incrementi avremo $\Phi(D_n) \ge 0$.

#### Vettori dinamici

Data una sequenza implementata tramite vettore dinamico (nella quale l'inserimento è $O(n)$ e il push è $O(1)$), nei linguaggi si implementa la cosiddetta *espansione*, ovvero dato il fatto che non è noto a priori quanti elementi entreranno nella sequenza, una volta terminata la capacità allocata si alloca un nuovo vettore più grande, si copia il vecchio vettore sul nuovo e si rilascia il vecchio vettore.

In Java si ha l'opzione, una volta terminato lo spazio di un `vector`, di raddoppiare lo spazio disponibile (usato dalla 1.2) oppure di usare un incremento fisso (prima della 1.2).

Nel caso del raddoppio, possiamo definire il costo effettivo dell'aggiunta di un oggetto in fondo al vettore come $1$ nel caso normale oppure $i := 2^k + 1$ quando abbiamo sforato le dimensioni del vettore. Il costo effettivo di $n$ operazioni sarà pari a $O(3n - 1) = O(n)$, ma il costo ammortizzato sarà pari a $O(1)$.

Nel caso dell'incremento, avremo che il costo effettivo di $n$ operazioni sarà pari a $O(n^2)$, ma il costo ammortizzato sarà pari a $O(n)$.

## 23/10/2018

Esercitazione svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 25/10/2018

### Alberi binari di ricerca

Andiamo ora ad approfondire l'implementazione di un albero binario di ricerca tramite un dizionario. L'idea è quella di ottenere una struttura dati efficiente per la ricerca, sfruttando la ricerca con complessità $O(\log n)$ negli alberi.

In un albero binario di ricerca, avremo che le chiavi contenute nei nodi del sottoalbero sinistra di un qualsiasi nodo $u$ saranno più piccole di `u.key` e le chiavi contenute in quello di destra saranno maggiori. Le funzioni a nostre disposizione saranno le stesse degli alberi binari; andremo ora a implementare delle funzioni per inserire, visitare e rimuovere nodi nel nostro albero.

#### Funzioni degli alberi binari di ricerca

`lookupNode()` restituirà il nodo dell'albero T che contiene la chiave k, oppure nil.

```Java
Tree lookupNode(Tree T, Item k)
```

```Coffee
Tree u = T
while u != nil and u.key != k:
    if k < u.key then
        u = u.left # Sotto-albero di sinistra
    else
        u = u.right # Sotto-albero di destra
return u
```

`max()` e `min()` restituiranno rispettivamente il massimo e il minimo di un albero; questi saranno sempre e comunque il nodo in fondo a destra e rispettivamente a sinistra di qualsiasi albero binario di ricerca.

```Java
Tree min(Tree T)
```

```Coffee
Tree u = T
while u.left != nil do
    u = u.left
return u
```

```Java
Tree max(Tree T)
```

```Coffee
Tree u = T
while u.right != nil do
    u = u.right
return u
```

`successorNode()` e `predecessorNode()` ritroveranno rispettivamente il successore (ovvero il più piccolo nodo maggiore di un dato nodo u) e il predecessore (ovvero il più grande nodo minore di un dato nodo u). Per fare ciò, ad esempio, `successorNode()` va a cercare prima nei suoi figli destri e ne prende il minimo; se non ha figli destri, risalendo attraverso i padri, il predecessore è il primo avo $v$ tale per cui il nodo di partenza $u$ è nel suo sottoalbero sinistro.

```Java
Tree predecessorNode(Tree t)
```

```Coffee
if t == nil then
    return t
if t.left != nil then  # Caso 1
    return max(t.left)
else                   # Caso 2
    Tree p = t.parent
    while p != nil and t == p.left do
        t = p
        p = p.parent
    return p
```

```Java
Tree successorNode(Tree t)
```

```Coffee
if t == nil then
    return t
if t.right != nil then  # Caso 1
    return min(t.right)
else                    # Caso 2
    Tree p = t.parent
    while p != nil and t == p.right do
        t = p
        p = p.parent
    return p
```

`insertNode()` andrà a inserire un'associazione chiave valore nell'albero T; se la chiave è già presente, verrà sostituito il valore, altrimenti verrà inserita una nuova associazione. Alla fine il metodo va a restituire l'albero T inalterato oppure un nuovo albero T nel caso fosse stato appena creato (= è stato passato nil come parametro).

```Java
Tree insertNode(Tree T, Item k, Item v)
```

```Coffee
Tree p = nil # Padre
Tree u = T
while u != nil and u.key != k do # Cerca posizione inserimento
    p = u
    u = u.left if k < u.key else u.right
if u != nil and u.key == k then
    u.value = v # Chiave già presente
else
    Tree new = Tree(k, v) # Crea un nodo coppia chiave-valore
    link(p, new, k)
    if p == nil then
        T = n # Primo nodo ad essere inserito
return T
```

Mostro di seguito l'implementazione della funzione `link()` il cui compito è quello di registrare l'inserimento di un nuovo nodo aggiustando i relativi puntatori.

```Java
link(Tree p, Tree u, Item k)
```

```Coffee
if u != nil then
    u.parent = p # Registrazione padre
if p != nil then
    if k < p.key then
        p.left = u # Attaccato come figlio sinistro
    else p.right = u # Attaccato come figlio destro
```

Mostro infine il funzionamento di `removeNode()` che rimuove, data la chiave k, il corrispondente nodo dell'albero T, andando a restituire la (potenzialmente diversa) radice dell'albero.

Distinguiamo tre casi:

- **caso in cui il figlio è singolo**: si attacca l'unico figlio nella posizione dell'ex padre.
- **caso in cui non ci sono figli**: si elimina il nodo e basta.
- **caso in cui ci sono due figli**: si individua il successore del nodo da cancellare (che non avrà figlio sinistro per definizione). Si stacca il successore, ed eventuali figli destri del successore vengono attaccati al padre del successore stesso. Si copia quindi il successore sul nodo da cancellare.

```Java
Tree removeNode(Tree T, Item k)
```

```Coffee
Tree u = lookupNode(T, k)
if u != nil then
    if u.left == nil and u.right == nil then      # Caso 1
        if u.parent != nil then
            link(u.parent, nil, k)
        delete u
    else if u.left != nil and u.right != nil then # Caso 3
        Tree s = successorNode()
        u.key = s.key
        u.value = s.value
        k = s.key
        link(s.parent, u.right, k)
        delete s
    else if u.left != nil and u.right == nil then # Caso 2
        link(u.parent, u.left, k)
        if u.parent = nil then
            T = u.left
    else
        link(u.parent, u.right, k)
        if u.parent = nil then
            T = u.right
return T
```

#### Costo computazionale degli alberi di ricerca

Tutte le operazioni eseguite sono confinate a un cammino semplice da una radice a una foglie. Avremo quindi un tetto superiore agli algoritmi pare a $O(h)$, dove h è pari all'altezza dell'albero. Nel caso pessimo (un albero tutto a destra) avremo $O(n)$, nel caso ottimo (un albero perfettamente bilanciato) avremo $O(\log n)$.

### Alberi binari di ricerca bilanciati

Quale è l'altezza media di un ABR? Se gli inserimenti avvengono a caso l'altezza media è pari a $O(\log n)$. Se però teniamo in conto anche le cancellazioni la cosa diventa difficile. In realtà non ci si affida al caso e si adottano tecniche per mantenere l'albero bilanciato.

Usiamo tre tipi di bilanciamento (dati anche dal fattore di bilanciamento $\beta (v)$ ovvero la massima differenza tra i sottoalberi di v:

- ALbero AVL dove $\beta (v) \le 1 \forall v$
- B-Alberi dove $\beta (v) = 0 \forall v$, specializzata per strutture in memoria secondaria (ovvero lenta, spesso si usa nei database)
- Alberi 2-3 con fattore uguale ai B-ALberi che vengono bilanciati tramite divisione dei sottoalberi

### Alberi Red-Black

Andremo principalmente a utilizzare il metodo di rotazione per bilanciare gli alberi. Utilizzeremo gli **Alberi RB (Red-Black)**, dove ogni nodo è colorato o di rosso o di nero e le foglie sono nodi speciali **Nil**, ovvero dei nodi sentinella che puntano a un oggetto unico nil per risparmiare memoria (il loro scopo è quello di evitare di trattare diversamente i puntatori ai nodi dai puntatori nil nelle foglie). Un albero RB ha determinati vincoli da rispettare:

- La radice è nera
- Tutte le foglie sono nere
- Entrambi i figli di un nodo rosso sono neri
- Ogni cammino semplice da un nodo u ad una delle foglie contenute nel sottoalbero radicato in u hanno lo stesso numero di nodi neri

Definiamo come **altezza nera** di un nodo come il numero di nodi neri da un percorso alla radice. (vedi slide, scritta male). Abbiamo che l'altezza di un albero RB sarà *al più* il doppio dell'altezza nera.

Durante la modifica di un albero RB è possibile che le condizioni definite in precedenza risultino violate. Andiamo allora a vedere quali sono le possibili soluzioni a questo problema.

#### Rotazioni - `rotateLeft`

Qui segue l'esempio di una rotazione a sinistra.

```Java
Tree rotateLeft(Tree x)
```

```Coffee
Tree y = x.right
Tree p = x.parent
x.right = y.left # Il sottoalbero B diventa figlio destro di x
if y.left != nil then
    y.left.parent = x
y.left = x # x diventa figlio sinistro di y
x.parent = y
y.parent = p # y diventa figlio di p
if p != nil then
    if p.left = x then
        p.left = y
    else
        p.right = y
return y
```

#### Inserimento con condizioni negli alberi RB - `balanceInsert`

Per inserire un nodo senza rompere i vincoli in un albero RB, si colora inizialmente il nodo di rosso e poi, risalendo, si sceglie uno tra 7 casi diversi per sistemare eventuali vincoli violati. Innanzitutto nella `insertNode()` andremo a inserire la chiamata del nostro nuovo metodo subito dopo `link()`. Nel nostro `balanceInsert()` inseriremo un enorme ciclo `while` nella quale andremo a risalire l'albero una volta inserito il nodo, via via sistemando i nodi che non rispettano i vincoli. I 7 casi citati in precedenza sono:

1. Il nuovo nodo $t$ non ha padre; significa che si tratta del primo nodo o che siamo arrivati alla radice. Lo coloriamo di nero.
2. Il padre di $t$ è nero; allora no problem, lo inseriamo normalmente.
3. Abbiamo il caso in cui $t$ è rosso, così come il padre e lo zio (ovvero il fratello del padre). Risolviamo colorando padre e zio di nero e continuando per vedere se abbiamo violato vincoli sul nonno.
4. Abbiamo il caso in cui il padre è rosso e lo zio è nero, e t è figlio **destro** di $p$, $p$ figlio **sinistro** di $n$. Allora procediamo con una rotazione a **sinistra** a partire del nodo $p$, ottenendo che $t$ sarà ora il figlio di $n$. Una variante sul tema è quando si scambia sinistro e destro e viceversa.
5. Abbiamo il caso in cui il padre è rosso e lo zio è nero, e t è figlio **sinistro** di $p$, $p$ figlio **sinistro** di $n$. Allora procediamo con una rotazione a **destra** a partire del nodo $n$, ottenendo che $t$ sarà ora il figlio di $p$. Una variante sul tema è quando si scambia sinistro e destro e viceversa.

```Java
balanceInsert(Tree t)
```

```Coffee
t.color = RED
while t != nil do
    Tree p = t.parent # Padre
    Tree n = iif(p != nil, p.parent, nil) # Nonno
    Tree z = iif(n = nil, nil, iif(n.left = p, n.right, n.left)) # Zio
    if p = nil then # Caso (1)
        t.color = BLACK
        t = nil
    else if p.color = BLACK then # Caso (2)
        t = nil
    else if z.color = RED then # Caso (3)
        p.color = z.color = BLACK
        n.color = RED
        t = n
    else
        if (t = p.right) and (p = n.left) then # Caso (4.a)
            rotateLeft(p)
            t = p
        else if (t = p.left) and (p = n.right) then # Caso (4.b)
            rotateRight(p)
            t = p
        else
            if (t = p.left) and (p = n.left) then # Caso (5.a)
                rotateRight(n)
            else if (t = p.right) and (p = n.right) then # Caso (5.b)
                rotateLeft(n)
            p.color = BLACK
            n.color = RED
            t = nil
```

Questo algoritmo ha complessità totale $O(n \log n)$. Per quanto riguarda la cancellazione, potremmo andare a implementare `balanceDelete` per ripristinare la proprietà Red-Black in caso di cancellazione. In particolare:

- Se il nodo “cancellato” è rosso
    - Altezza nera invariata
    - Non sono stati creati nodi rossi consecutivi
    - La radice resta nera
- Se il nodo “cancellato” è nero
    - Possiamo violare il vincolo 1: la radice può essere un nodo rosso
    - Possiamo violare il vincolo 3: se il padre e uno dei figli del nodo cancellato erano rossi
    - Abbiamo violato il vincolo 4: altezza nera cambiata

Vedi file in /Codici per implementazione.

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

Un vertice $v$ è detto *adiacente* se $\exists v \in V : (u, v) \in E$. Il risultante arco è detto *incidente*.

Chiameremo il numero di nodi $n$ ed il numero di archi $m$. Vale $m \le \frac{n(n-1)}{2} = O(n^2)$ per grafi non orientati e $m \le n^2 -n = O(n^2)$ per grafi orientati. Definiremo da ora in poi la complessità in funzione sia di $n$ che di $m$.

Un grafo con un arco in tutte le coppie di nodi è detto **completo**. Un grafo con "pochi" o "tanti" archi è detto rispettivamente **sparso** (es. $m = O(n), m = O(n \log n)$) e **denso** (es. $m = \Theta(n^2)$).

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

```Coffee
Set S = Set()
S.insert(r)
int [] visited = new int[1...G.V]
visited[r] = true
while S.size() > 0 do
    Node u = S.remove()
    visited[u] = true
    for v in G.adj(u) do
        # { visita l’arco (u, v) }
        if not visited[v] then
            S.insert(v)
```

### BFS - `bfs`

L'obiettivo della visita in ampiezza è visita i nodi a distanza crescenti dalla sorgente. Per farlo genereremo un albero *BFS*.

```Java
bfs(Graph G, Node r)
```

```Coffee
Queue Q = Queue()
Q.enqueue(r)
boolean[] visited = new boolean[1...G.V]
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

#### Numero di Erdős - `erdős`

Il numero di Erdős rappresenta il cammino minimo in un grafo di persone che hanno scritto articoli scientifici. Erdös ha valore erdős = 0. I co-autori di Erdős hanno erdős $= 1$. Se X è co-autore di qualcuno con erdős = k e non è coautore con qualcuno con erdős $< k$, allora X ha erdős $= k + 1$. Le persone non raggiunte da questa definizione hanno erdős = $+ \infty$. Questa implementazione è molto simile ai numeri di Bacon.

Abbiamo quindi l'implementazione `bfs` adattata ai numeri di Erdős:

```Java
erdős(Graph G, Node r, int[] erdős, Node[] parent)
```

```Coffee
Queue Q = Queue()
Q.enqueue(r)
for u in G.V() - {r} do
    visited[u] = Inf
erdős[r] = 0
parent[r] = nil
while not Q.isEmpty() do
    Node u = Q.dequeue()
    for v in G.adj(u) do
        if erdős[v] == Inf then # Se il nodo v non è stato scoperto
        erdős[v] = erdős[u] + 1
        parent[v] = u
        Q.enqueue(v)
```

Durante la visita, andremo via via ad accumulare blocchi di nodi che hanno tutti distanza uguale dalla radice. Per generare il nostro albero BFS di copertura che conterrà tali nodi utilizziamo il vettore `parent`nell'algoritmo precedente. Per stampare il cammino minimo utilizziamo questa implementazione:

```Java
printPath(Node r, Node s, Node[] parent)
```

```Coffee
if r == s then
    print(s)
    return
if parent[s] == nil then
    return
printPath(r, parent[s], parent)
print(s)
```

La complessità di questo algoritmo è pari a $O(n + m)$, infatti ogni singolo nodo e ogni singolo arco viene analizzato una volta sola.

### DFS - `dfs`

La Depth-First Search viene spesso usata come subroutine di altri problemi. L'output sarà una *foresta* depth-first, un albero per ogni nodo visitato.

```Java
dfs(Graph G, Node u, boolean[] visited)
```

```Coffee
visited[u] = true
# { visita il nodo u (pre-order) }
for v in G.adj(u) do
    if not visited[v] then
        # { visita l’arco (u, v) }
        dfs(G, v, visited)
# { visita il nodo u (post-order) }
```

Questo algoritmo presenta un problema strutturale: la grandezza degli stack nei sistemi operativi è limitata e per alberi di grandi dimensioni è facilmente superabile. Per ovviare al problema spesso si usa la BFS invece della DFS, oppure rendendo l'algoritmo iterativo e adattandolo rendendo simile alla BFS (ovvero si permette l'inserimento multiplo dei nodi nella coda, fino a un numero pari al numero di archi entranti; inoltre si anticipa il controllo della visita all'estrazione e non all'inserimento). Vedi slide per implementazione.

#### Componenti connesse - `cc`

Molti algoritmi iniziano decomponendo il grafo nelle sue componenti connesse, applicando l'algoritmo e poi ricompongono assieme il grafo. Abbiamo sia le **componenti connesse** (su grafi non orientati) che le **componenti fortemente connesse** (su grafi orientati). Vediamo ora le componenti connesse semplici.

Un grafo non orientato G è connesso $\leftrightarrow$ ogni suo nodo è raggiungibile da qualsiasi altro nodo.

- Un grafo G' = (V', E') è una componente connessa di G $\leftrightarrow$ G' è un sottografo connesso e massimale di G
- G' è un sottografo di G (G' $\in$ G) $\leftrightarrow$ V' $\in$ V e E' $\in$ E
- G' è massimale, non esiste nessun altro sottografo G'' di G tale che G'' è connesso e più grande di G' (i.e. G' $\in$ G'' $\in$ G)

Per identificare le sue componenti connesse, verifichiamo alla fine della DFS se tutti i nodi sono marcati; altrimenti siamo in presenza di un grafo con più componenti connesse, e la visita deve ricominciare da capo da una componente non ancora visitata.

```Java
int[] cc(Graph G)
```

```Coffee
int [] id = new int[1...G.V]
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

```Coffee
id[u] = counter
for v in G.adj(u) do
    if id[v] == 0 then
        ccdfs(G, counter, v, id)
```

## 13/11/2018

### DFS (cont.)

Seguono tre ulteriori applicazioni della DFS.

#### Grafi con cicli - `hasCycle`

In un grafo non orientato, un ciclo C di lunghezza $k > 2$ è una sequenza di nodi $u_0, u_1...u_n$ tale che la sequenza è un cammino e il primo e l'ultimo nodo coincidono. Chiamiamo un grafo con almeno un ciclo **ciclico** e uno che non ne contiene **aciclico**.

```Java
boolean hasCycleRec(Graph G, Node u, Node p, boolean[] visited)
```

```Coffee
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
dfsschema(Graph G, Node u, int &time, int[] dt, int[] ft)
```

```Coffee
# { visita il nodo u (pre-order) }
time = time + 1
dt[u] = time
for u in G.adj(u) do
    # { visita l’arco (u, v) (qualsiasi) }
    if dt[v] == 0 then
        # { visita l’arco (u, v) (albero) }
        dfsschema(G, v, time, dt, ft)
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
boolean hasCycle(Graph G, Node u, int &time, int[ ] dt, int[ ] ft)
```

```Coffee
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

#### Ordinamento topologico - `topSort`

Dato un DAG G, un **ordinamento topologico** è un ordinamento lineare dei suoi nodi tale che se $(u, v) \in E$, allora $u$ è prima di $v$ nell'ordinamento. Con l'algoritmo `topSort` andiamo a generare un vettore contenente l'ordinamento topologico del

```Java
Stack topSort(Graph G)
```

```Coffee
Stack S = Stack()
boolean[] visited = boolean[1...G.size()]
for u in G.V() do
    visited[u] = false
    if not visited[u] then
        tsdfs(G, u, visited, S)
return S
```

```Java
tsdfs(Graph G, Node u, boolean[] visited, Stack S)
```

```Coffee
visited[u] = true
for v in G.adj(u) do
    if not visited[v] then
        tsdfs(G, v, visited, S)
S.push(u)
```

#### Componenti fortemente connesse - `scc`, `transpose`

- Un grafo orientato $G = (V, E)$ è fortemente connesso $\Leftrightarrow$ ogni suo nodo è raggiungibile da ogni altro suo nodo
- Un grafo $G_0 = (V_0, E_0)$ è una componente fortemente connessa di G $\Leftrightarrow$ G_0 è un sottografo connesso e massimale di G.

```Java
int[] scc(Graph G)
```

```Coffee
Stack S = topSort(G) # First visit
GT = transpose(G) # Graph transposal
return cc(GT, S)
```

Utilizzando l'ordinamento topologico su un grafo generale `topSort`, siamo sicuri che restituirà un ordinamento perfetto per tempo di fine. Infatti eventuali archi di un ciclo vengono listati in un ordine ininfluente, mentre gli archi non di un ciclo saranno ordinati.

Definiamo come **grafo trasposto** un grafo orientato i cui archi sono stati invertiti di direzione.

```Java
int[] transpose(Graph G)
```

```Coffee
Graph GT = Graph()
for u in G.V() do
    GT.insertNode(u)
for u in G.V() do
    for v in G.adj(u) do
        GT.insertEdge(v, u)
return GT
```

Per quanto riguarda la visita delle componenti connesse del grafo trasposto, invece di esaminare i nodi in ordine arbitrario, questa versione di `cc` li esamina nell’ordine LIFO memorizzato nello stack.

```Java
cc(Graph G, Stack S)
```

```Coffee
int [] id = new int[1...G.size()]
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

```Coffee
id[u] = counter
for v in G.adj(u) do
    if id[v] == 0 then
        ccdfs(G, counter, v, id)
```

L'algoritmo in totale avrà costo computazionale pari a $O(n + m)$.

## 15/11/2018

Esercitazione svolta in Aula B107. Nessun nuovo argomento di teoria trattato.

## 20/11/2018

Lezione di Laboratorio svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 22/11/2018

### Hashing

Vediamo ora le implementazioni di dizionari tramite le cosìddette **tabelle hash**, ovvero delle tabelle che preso in input una coppia $(\text{chiave}, \text{valore})$, utilizzando una funzione hash $h$ che mappa ogni chiave k a un intero e lo memorizza nella suddetta tabella.

L'insieme delle possibili chiavi è rappresentato dall'insieme universo $\mathbf{U}$. Definiamo quindi una funzione hash:

$$
h: \mathbf{U} \Rightarrow {0, 1, ..., m - 1}
$$

Quando due o più chiavi, diciamo che è avvenuta una *collisione*.

#### Tabelle ad accesso diretto

Caso particolare nella quale l'insieme $\mathbf{U}$ è già un sottoinsieme di $\mathbb{Z}^+$. In questi casi si sceglie la funzione hash identità e il valore $m$ di dimensione tabella pari a $u$.

#### Funzione hash perfetta

Una funzione hash h si dice perfetta se è iniettiva. Ciò può tuttavia risultare spesso impraticabile; le collisioni risultano quindi possibili, nostro compito sarà minimizzarle e rendere le funzioni hash il più uniformi sul nostro insieme.

Sia $P(k)$ la probabilità che una chiave $k$ sia inserita in tabella. Sia $Q(i)$ (dove $i := h(k)$) la probabilità che una chiave finisca nella cella $i$. Allora una funzione hash gode di *uniformità semplice* se $\forall i \in [0, ..., m-1]: Q(i) = 1/m$.

Nella realtà la distribuzione esatta non sarà mai completamente nota, andremo a utilizzare tecniche "euristiche" per sopperire al problema.

#### Funzione di estrazione

Poniamo $m := 2^p$ e $h(k) = int(b)$, dove b è un sottoinsieme di $p$ bit presi da $bin(k)$.

$int(), bin()$ sono due funzioni che trasformano rispettivamente un numero binario in intero e un carattere alfabetico in binario utilizzando la codifica ASCII.

Questo approccio genera diversi problemi: infatti, a seconda del sottoinsieme scelto, la probabilità di collisioni è estremamente alta.

#### Funzione XOR

Poniamo $m := 2^p$ e $h(k) = int(b)$, dove b è dato dalla somma modulo 2 bit a bit di $p$ bit di $bin(k)$

#### Metodo della divisione

Poniamo $m$ dispari, possibilimente primo, e $h(k) = int(k) \mod m$. $m$ deve essere possibilmente lontano da potenze di 2 e 10 e non può essere $2^p$ nè $2^p - 1$.

#### Metodo della moltiplicazione

Poniamo $m$ qualsiasi, possibilmente potenza di 2, $C \in \mathbb{R} : 0 < C < 1$, $i := int(k)$, $h(k) = \lfloor m(C \cdot i - \lfloorC \cdot i \rfloor)\rfloor$

In realtà si usano funzioni hash un po' più complicate come FNV Hash e City Hash.

### Gestione delle collisioni

Parliamo ora della gestione delle collisioni, ovvero dello spostamento delle chiavi nel caso il loro hash collida. La loro ricerca, una volta spostate, dovrebbe costare $O(1)$ nel caso medio ma può costare fino a $O(n)$.

#### Liste di trabocco

Idea: le chiavi con lo stesso valore hash vengono memorizzate in un vettore dinamico, e un puntatore alla testa del vettore viene aggiunto nella tabella hash. Avremo che nel caso pessimo l'inserimento sarà $\Omega(1)$ e la ricerca e la rimozione $\Omega(n)$.

Definiamo:

- Valore atteso della lunghezza della lista: pari a $\alpha = n/m$, dove $n$ è il numero totale di chiavi e $m$ la capacità della tabella hash. Se $m = O(n)$, avremo che tutte le operazioni saranno $O(1)$.
- Numero medio di accessi alla tabella per la ricerca di una chiave non presente nella tabella (ricerca con insuccesso): indicata con $I(\alpha)$. Avrà un costo atteso pari a $\Omega(1) + \alpha$.
- Numero medio di accessi alla tabella per la ricerca di una chiave presente nella tabella (ricerca con successo, che tocca in media metà delle chiavi nella lista): $S(\alpha)$. Avrà un costo atteso pari a $\Omega(1) + \alpha/2$.

#### Indirizzamento aperto

Questa alternativa memorizza tutte le chiavi nella tabella stessa. Ogni slot va quindi a contenere o una chiave o nil.

Chiamiamo *ispezione* l'esame di uno slot durante la ricerca. Chiamiamo *sequenza di ispezione* una permutazione degli indici corrispondente all'ordine in cui vengono esaminati gli slot, in maniera univoca.

La situazione ideale prende il nome di **hashing uniforme**, dove ogni chiave ha le stesse probabilità di avere come sequenza di ispezione una qualsiasi delle permutazioni degli m slot. Andiamo a vedere tre tecniche per avvicinarsi il più possibile all'hashing uniforme.

##### Ispezione lineare

Vale:

$$
H(k, i) = (H_1(k) + h \cdot i) \mod m
$$

Grazie all'operazione modulo, avremo massimo $m$ sequenze di ispezione distinte.

Con questo metodo andremo a ottenere la cosìddetta **agglomerazione primaria**, nella quale lunghe sottosequenze (che diventano sempre più lunque) della tabella vengono occupate, incrementando i tempi medi di inserimento e cancellazione.

##### Ispezione quadratica

Vale:

$$
H(k, i) = (H_1(k) + h \cdot i^2) \mod m
$$

A differenza della precedente, dopo l'inserimento del primo elemento le ispezioni successive hanno un offset quadratico e non lineare. La sequenza non sarà quindi una permutazione ma sarà sparsa nel vettore.

##### Doppio hashing

Vale:

$$
H(k, i) = (H_1(k) + i \cdot H_2(k)) \mod m
$$

Abbiamo due funzioni ausiliarie, $H_1$ che va a fornire la prima ispezione e $H_2$ l'offset delle successive ispezioni. Per garantire una permutazione completa, $H_2(k)$ deve essere coprimo con $m$.

In tutti i casi non possiamo cancellare una chave sostituendola con un nil, in quanto le sequenze di ispezione andrebbero distrutte. Andiamo quindi a utilizzare uno speciale valore $deleted$ per marcare uno slot vuoto dopo la cancellazione. Questi slot verranno trattati come pieni nella ricerca e vuoti nell'inserimento. Questo va tuttavia a impattare sul tempo di ricerca (modificando $\alpha$). Vedi slide per implementazione su codice.

#### Complessità

Abbiamo infine che le liste di trabocco sono le più efficienti dal punto di vista della complessità (crescono infatti linearmente). In generale per ovviare alla crescita della complessità con il passare del tempo, superata una soglia per $\alpha$ prefissata (generalmente tra 0.5 e 0.75) si alloca una tabella grande il doppio e si reinseriscono tutte le chiavi, dimezzando il fattore di carico e rimuovendo eventuali elementi deleted. La ristrutturazione avrà costo $O(m)$ ma costo ammortizzato costante.

## 27/11/2018

Lezione di Laboratorio svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 29/11/2018

Esercitazione svolta in Aula B107. Nessun nuovo argomento di teoria trattato.

## 4/12/2018

Lezione di Laboratorio svolta in Aula A101, con introduzione al progetto del semestre. Nessun nuovo argomento di teoria trattato.

## 6/12/2018

### Risoluzione di problemi generali

Dato un problema, non ci sono ricette generali per risolverlo in modo efficiente ma possiamo evidenziare:

- Classificazione del problema
- Caratteristiche della soluzione
- Tecniche del progetto
- Utilizzo delle strutture dati

Possiamo classificare i problemi in due categorie: i *problemi decisionali* (con risposta sì-no), i *problemi di ricerca* (con un certo sottoinsieme di soluzioni ammissibili), i *problemi di ottimizzazione* (con ricerca del costo minimo), e i *problemi di approssimazione* (per i problemi NP-completi).

E' inoltre fondamentale definire matematicamente il problema prima di decidere la procedura corretta per arrivare alla soluzione ottima. Vedremo nelle prossime lezioni svariate tecniche di progettazione di algoritmi che possono essere applicate a varie formulazioni di problemi.

### Divide et impera

E' una tecnica di programmazione che si divide in tre fasi:

- **Divide**: dividi il problema in sotto-problemi più piccoli
- **Impera**: risolvi ricorsivamente i sottoproblemi
- **Combina**: unisci le soluzioni ottenute

Esempio di algoritmo divide-et-impera (potenzialmente inutile con complessità $\Theta(n)$)

```Java
minrec(int[] A, int i, int j)
```

```Coffee
if i == j then
    return A[i]
else
    m = floor((i + j) / 2)
    return min(minrec(A, i, m), minrec(A, m + 1, j))
```

In generale, l'uso di algoritmi divide-et-impera è consigliato se e solo se migliorano la complessità rispetto alla corrispondente versione iterativa. Sono facilmente parallelizzabili e sfruttano in maniera ottimale la cache, andando ad accedere su aree contingue di memoria.

### Torre di Hanoi - `hanoi`

```Java
hanoi(int n, int src, int dest, int middle)
```

```Coffee
if n == 1 then
    print(src -> dest)
else
    hanoi(n - 1, src, middle, dest)
    print(src -> dest)
    hanoi(n - 1, middle, dest, src)
```

Questo algoritmo ha complessità $\Theta(2^n)$ ma si può dimostrare che è ottimo.

### Quicksort - `quicksort`

Quicksort è un algoritmo di ordinamento divide-et-impera. Nel caso medio ha complessità $O(n\log n)$, nel caso pessimo $O(n^2)$; tuttavia ha il vantaggio di avere fattori moltiplicativi minori rispetto a MergeSort e ha un basso impatto sulla memoria.

L'algoritmo prende in input un vettore di $n$ elementi e:

- Sceglie un *perno* $p$ appartenente al vettore e sposta tutti gli elementi più piccoli di $p$ a sinistra di $p$, tutti quelli più grandi a destra.
- Calcola l'indice j in modo che questa condizione venga rispettata e posiziona $p$ su data posizione
- Ordina ricorsivamente i due sottovettori a destra e a sinistra del perno.

```Java
int pivot(Item[] A, int start, int end)
```

```Coffee
Item p = A[start]
int j = start
for i in range(start + 1, end) do
    if A[i] < p then
        j = j + 1
        A[i] <=> A[j]
A[start] = A[j]
A[j] = p
return j
```

```Java
QuickSort(Item[] A, int start, int end)
```

```Coffee
int j = pivot(A, start, end)
QuickSort(A, start, j-1)
QuickSort(A, j, end)
```

Il costo di `pivot` è $\Theta(n)$, mentre `QuickSort` dal partizionamento:

- Se il vettore di dimensione n viene diviso in sottoproblemi di dimensione 0 e n - 1, generando una complessità pari a $\Theta(n^2)$ (ovvero quando sono circa tutti ordinati).
- Se il vettore viene invece diviso in due sottoproblemi pari a n / 2, la complessità sarà pari a $\Theta(n \log n)$.

Per analizzare il caso medio, bisognerebbe eseguire uno studio probabilistico per verificare il comportamento dell'algoritmo dato un certo input.

### Moltiplicazione di matrici - `strassen`

Date due matrici $A, B$ moltiplicabili riga per colonna (il nimero di righe della prima è pari al numero di colonne della seconda), calcoliamo $A \times B$.

Possiamo utilizzare un algoritmo banale $O(n^3)$, ma andremo ora a vedere un altro algoritmo divide-et-impera (`strassen`). Tramite alcuni accorgimenti e matrici intermedie (simili all'approccio usato da Karatsuba) otteniamo un'equazione di ricorrenza pari a $7T(n/2) + n^2$ che fornisce una complessità pari a $\Theta(n^{2.81})$.

### Gap

Dato un vettore $V$ con almeno due elementi, un **gap** è un indice i tale che $V[i - 1] < V[i]$.

Abbiamo che se $n \ge 2$ e $V[1] < V[n]$, $V$ contiene almeno un gap. Vedi slide per implementazione dell'algoritmo.

## Insiemi e dizionari (cont.)

- **Bitset**: struttura dati speciale, formata da un vettore di booleani, che viene usata come sottostruttura per i dizionari.
- **Albero bilanciato**: struttura vista in precedenza con accesso e ricerca pari a $O(n \log n)$ e iterazione pari a O(n).
- **Hash table**: struttura vista in precedenza con accesso pari a $O(1)$ e iterazione pari a $O(m)$.

Vedi slide per sintesi su metodi e costo delle varie implementazioni nei linguaggi.

## 11/12/2018

Lezione di laboratorio svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 13/12/2018

Esercitazione svolta in Aula B107. Nessun nuovo argomento di teoria trattato.

## 18/12/2018

### Bloom Filter

I **Bloom Filter** sono delle strutture dati dinamiche che combinano il basso uso di memoria dei bitset con l'algoritmo implementato dalle tabelle hash. Non permettono la cancellazione di oggetti una volta inseriti.

La struttura dati utilizzato è un vettore booleano di $m$ bit, inizializzati a $0$. Utilizziamo $k$ funzione hash del tipo:

$$
U \rightarrow [0, m-1]
$$

Per inserire un oggetto in un Bloom Filter, si applicano le $k$ funzioni hash all'oggetto da inserire, ottenendo $k$ valori numerici. Andiamo quindi a settare i corrispondenti bit nella tabella a $1$: ad esempio, se inserendo la stringa "ASD" e applicando due funzioni hash otteniamo i valori 45 e 13, andremo a settare $A[45], A[13]$ su true.

Il downside dei Bloom Filter è che quando andiamo a controllare l'appartenenza di un dato elemento al filtro, se restituisce $false$ è sicuramente non presente, se restituisce $true$ potrebbe essere presente oppure no, con una probabilità di falso positivo pari a:
$$
\epsilon = (1 - e^{-kn/m})^k
$$

I valori ottimali per $k$ e $m$ sono invece:

$$
k = \frac{m}{n} \ln{2}\qquad m = \frac{-n\ln{\epsilon}}{(\ln{2})^2}
$$