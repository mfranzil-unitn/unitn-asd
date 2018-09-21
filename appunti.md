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

__Problema computazionale__
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
ovvero è un limite asintotico superiore.

__Limite asintotico inferiore__:

Indichiamo con $\Omega(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\exists c > 0, \exists m \ge 0 : f(n) \ge c g(n), \forall n \ge m$$
ovvero è un limite asintotico inferiore.

__Limite asintotico superiore e inferiore__:

Indichiamo con $\Theta(g(n))$ l'insieme delle funzioni f(n) tali per cui
$$\exists c > 0, \exists m \ge 0 :c_1 g(n) \le f(n) \le c_2 g(n), \forall n \ge m$$
ovvero, grazie al teorema dei Carabinieri, f(n) cresce esattamente come g(n).

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