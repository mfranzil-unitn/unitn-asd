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

```c++
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

----

## 18/09/2018

### Problemi computazionali

__Problema computazionale__:
> Rappresentato da una relazione matematica che associa gli elementi dei domini di input e output.

__Algoritmo__:
> Un procedimento effettivo che risolve il problema in un tempo finito.

Esempi di problemi computazionali possono essere il minimo e la ricerca. Esprimere tali problemi in italiano si rivela tuttavia impreciso e poco formale. Utilizzeremo una descrizione molto più formale con lo *pseudo-codice*.

Vedi slide per esempi sulla sintassi dello pseudo-codice. Seguono i due algoritmi visti a lezione scritti in pseudo-codice.

#### Minimo - `min`

```c++
int min (int[] s, int n)
```

```Coffee
for i <- 1 to n do
    boolean isMin <- true
    for j <- 1 to n do
        if i != j and S[j] < S[i] then
            isMin <- false

    if isMin then
        return S[i]
```

#### Ricerca dicotomica - `lookup`

```c++
int lookup(int[] S, int n, int v)
```

```Coffee
for i <- 1 to n do
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

```c++
int binarySearch(int[] S, int v, int i, int j)
```

```Coffee
if i > j then
    return 0
else
    int m <- floor((i + j)/2)
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

| Alcuni tipi di ordini di complessità |
| :----------------------------------: |
| $\log(n)$                            |
| $\sqrt{n}$                           |
| $n$                                  |
| $n\ \log(n)$                         |
| $n^2$                                |
| $n^3$                                |
| $2^n$                                |

#### Funzioni di costo

Utilizziamo il termine funzione di costo per una funzione $f: \mathbb{N}\Longrightarrow \mathbb{R}$

Sia ora g(n) una funzione di costo.

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

----

## 20/09/2018

### Analisi di algoritmi (cont.)

#### Stima dei limiti asintotici

Per dimostrare $\Theta(n)$, dimostreremo sia la validità del limite inferiore sia del limite superiore tramite semplici disequazioni (vedi slide 22-23-24). Ai fini della dimostrazione non è importante ottenere una stima troppo precisa, ma semplicemente ottenere una stima inferiore e superiore sullo stesso ordine di grandezza.

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

> Il problema della somma di numeri binari ha complessità $O(n)$ e $\Theta(n)$.

Si ha che un problema ha complessità $O(f(n))$ se esiste almeno un algoritmo che lo risolve con complessità $O(f(n))$. Si ha che un problema ha complessità $\Omega(f(n))$ se tutti gli algoritmi che lo risolvono hanno complessità $\Omega(f(n))$.

Analogamente possiamo discutere della complessità della moltiplicazione. Si dimostra che la moltiplicazione ha complessità $O(n^2)$, perlomeno con l'algoritmo studiato alle elementari.

#### Moltiplicazione divide-et-impera - `pdi`

Usiamo la tecnica divide-et-impera per affrontare questo problema e *provare* a trovare un algoritmo che abbia complessità sotto $\Omega(n^2)$. Dividiamo i nostri numeri binari in due parti:

$$X = a 2^{n/2} + b\\
Y = c 2^{n/2} + d\\
XY = ac2^n + (ad + bc) 2 ^ {n/2} + bd$$

```c++
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

Grazie alle moltiplicazioni per $2^n$ che vengono risolte in tempo lineare, così come le somme, otteniamo una funzione di ricorrenza (vedi slide 41) che viene ridotta nuovamente a una funzione di costo O(n^2).

#### Moltiplicazione di Karatsuba - `karatsuba`

Usiamo lo stesso principio di Gauss visto in precedenza per ridurre il numero di moltiplicazioni richieste a tre.

```c++
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

Questo algoritmo ha complessità $n^{1.58}$. Esistono comunque altri algoritmi (Toom-Cook, Furer, che vengono usati, a causa dei fattori moltiplicativi, solo per numeri molto grandi) che hanno ulteriormente abbassato la complessità della moltiplicazione, e si suppone che la moltiplicazione ha un limite inferiore pari a $\Omega(n\log(n))$.

### Algoritmi di ordinamento

Valuteremo ora gli algoritmi di ordinamento in base a dimensione e tipologia dell'input. Conoscere il tipo dell'input porta a scelte diverse sull'algoritmo da usare.

#### Tipologie di analisi

- __Caso pessimo__: il tempo di esecuzione nel caso peggiore (ordinamento inverso); sarà il nostro limite superiore.
- __Caso medio__: difficile in aucuni casi, corrispondente a un input con distribuzione uniforme.
- __Caso ottimo__: utile se si hanno informazioni particolari

Il problema da risolvere è il seguente:
> Data una sequenza A di n valori, ottenere una sequenza Bche sia una permutazione dell'input tale che $\forall b \in b, b_1 \le b_2 \le ... \le b_n$.

#### Selection Sort - `selectionsort`

```c++
void selectionSort(T[] A, int n)
```

```Coffee
for i = 1 to n - 1 do
    int min = min(A, i, n)
    A[i] <-> A[min]
```

L'algoritmo ha una complessità pari a $O(n^2)$ e $\Theta(n^2)$.

#### Insertion Sort - `insertionsort`

```c++
void insertionSort(T[] A, int n)
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

Questo algoritmo costa in media e nel caso pessimo $O(n^2)$, ma nei casi migliori si avvicina a $O(n)$.

## 25/09/2018

### Algoritmi di ordinamento (cont.)

#### Merge Sort - `mergesort`

Dato un vettore di $n$ interi, andiamo a usare la tecnica divide et impera per ordinare il vettore. Usiamo come appoggio il metodo `merge()` che dato in input un vettore di $n$ interi contenente due sottovettori di interi già ordinati, fornisce in output un vettore ordinato tramite un vettore di appoggio B.

> Nell'implementazione del programma, abbiamo un singolo vettore d'appoggio $B$ lungo $n$ che viene utilizzato durante tutta l'esecuzione del programma.

```c++
void merge(int A[], int first, int last, int mid)
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

`merge()` ha un costo computazionale di $O(n)$. Il resto dell'algoritmo si basa appunto sulla tecnica divide-et-impera ricorsiva; il caso base è dato da vettori di lunghezza 1.

```c++
void mergeSort(int A[], int first, int last)
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
$$\forall c, \exists m : f(n) < cg(n), \forall n \ge m$$

Sia $g(n)$ una funzione di costo; indichiamo con $\omega(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\forall c, \exists m : f(n) > cg(n), \forall n \ge m$$

### Classificazione delle funzioni

Possiamo ora trarre un ordinamento delle principali espressioni viste fin'ora:
$$\forall r < s,\ h < k, \ a < b:$$
$$O(1) \subset O(\log^r n) \subset O(\log^s n) \subset O(n^h) \subset O(n^h \log^r n)\\ \subset O(n^h log^s n) \subset O(n^k) \subset O(a^n) \subset O(b^n)$$

### Equazioni di ricorrenza

Si ottengono calcolando la complessità di un algoritmo ricorsivo. L'obiettivo è ottenere una *forma chiusa* che rappresenti la complessità. Utilizzeremo le equazioni di ricorrenza anche per risolvere problemi.

__Problema__:
> Un bambino scende una scala composta da n scalini. Ad ogni passo,
può decidere di fare 1, 2, 3, 4 scalini alla volta. Determinare in quanti
modi diversi può scendere le scale.

Una possibile soluzione può essere una funzione ricorsiva che conta a ogni passo il numero di modi possibili, con due casi base, uno quando si hanno terminato gli scalini (con un modo possibile) e uno quando si "sfora" (con zero modi).

Distinguiamo ora tre metodi per le risolvere le ricorrenze.

#### Metodo dell'albero di ricorsione / per livelli

Si "srotola" la ricorrenza in un albero come già visto prima. Una volta arrivati al caso base, si valutano i costi delle chiamate comprimendoli in una sommatoria per poi usare passaggi algebrici (segue).

## 27/09/2018

### Equazioni di ricorrenza (cont.)

#### Metodo dell'albero di ricorsione / per livelli (cont.)

(cont.) Bisogna fare estrema attenzione ai fattori moltiplicativi associati alle chiamate ricorsive in quanto si ripercuotono su tutta la chiamata. All'arrivo del caso base ($T(1)$) si ottengono generalmente $\log (n) + 1$ elementi di cui l'ultima conterrà $T(1)$, e le altre si potranno condensare, ad esempio, in una serie matematica.

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

A volte le assunzioni, pur risultando valide, possono fallire sotto certi aspetti (ad esempio un termine di ordine inferiore che rende invalida una disequazione). In tali casi è opportuno effettuare una dimostrazione sottraendo il termine di ordine superiore nell'ipotesi, ad esempio:
$$\exists c > 0, \exists m \ge 0 : T(n) \le cn, \forall n \ge m$$
Ipotesi possibili:
$$\forall k < n : T(k) \le ck \qquad\ \quad\text{fallisce}\\
  \forall k < n : T(k) \le ck - b \qquad \text{ funziona}$$

Altre volte, invece, si possono presentare problemi con il caso base $T(0)$ (ovvero che la dimostrazione fallisce). Grazie all'arbitrarietà di $m$, possiamo andare a dimostrare i vari casi base ($T(1), T(2)...$) che dipendono ancora da $T(0)$ finché non si esauriscono. Si ottengono quindi diversi $c$ dalla quale poi si sceglie il $\max()$.

Bisogna infine fare attenzione ad ipotizzare soluzioni troppo strette.

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

| Caso | Condizione                                                                                                                                                 |                                  | Risultato                      |
| ---- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------- | ------------------------------ |
| (1)  | $\exists \epsilon > 0: f(n) = O(n^{\log_b{a - \epsilon}})$                                                                                                 | $\qquad \Longrightarrow \qquad$  | $T(n) = \Theta(n^{log_b{a}})$ |
| (2)  | $f(n) = \Theta(n^{log_b{a}})$                                                                                                                              | $\qquad \Longrightarrow \qquad$  | $T(n) = \Theta(f(n) \log n)$  |
| (3)  | $\exists \epsilon > 0 : f(n) = \Omega(n^{log_b{a+\epsilon}})\\ \wedge \exists c : 0 < c < 1, \exists m > 0:\text{} \\ af(n/b) \le cf(n), \forall n \ge m$  | $\qquad \Longrightarrow \qquad$  | $T(n) = \Theta(f(n))$          |

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