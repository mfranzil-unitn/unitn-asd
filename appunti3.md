# Appunti di Algoritmi e Strutture Dati [20181127 - ]

- [Appunti di Algoritmi e Strutture Dati [20181127 - ]](#appunti-di-algoritmi-e-strutture-dati-20181127)
    - [27/11/2018](#27112018)
    - [29/11/2018](#29112018)
    - [4/12/2018](#4122018)
    - [6/12/2018](#6122018)
        - [Risoluzione di problemi generali](#risoluzione-di-problemi-generali)
        - [Divide et impera](#divide-et-impera)
        - [Torre di Hanoi](#torre-di-hanoi)
        - [Quicksort](#quicksort)
        - [Moltiplicazione di matrici](#moltiplicazione-di-matrici)
        - [Gap](#gap)
    - [Insiemi e dizionari (cont.)](#insiemi-e-dizionari-cont)

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

```Ruby
if i == j then
    return A[i]
else
    m = floor((i + j) / 2)
    return min(minrec(A, i, m), minrec(A, m + 1, j))
```

In generale, l'uso di algoritmi divide-et-impera è consigliato se e solo se migliorano la complessità rispetto alla corrispondente versione iterativa. Sono facilmente parallelizzabili e sfruttano in maniera ottimale la cache, andando ad accedere su aree contingue di memoria.

### Torre di Hanoi

```Java
hanoi(int n, int src, int dest, int middle)
```

```Ruby
if n == 1 then
    print(src -> dest)
else
    hanoi(n - 1, src, middle, dest)
    print(src -> dest)
    hanoi(n - 1, middle, dest, src)
```

Questo algoritmo ha complessità $\Theta(2^n)$ ma si può dimostrare che è ottimo.

### Quicksort

Quicksort è un algoritmo di ordinamento divide-et-impera. Nel caso medio ha complessità $O(n\log n)$, nel caso pessimo $O(n^2)$; tuttavia ha il vantaggio di avere fattori moltiplicativi minori rispetto a MergeSort e ha un basso impatto sulla memoria.

L'algoritmo prende in input un vettore di $n$ elementi e:

- Sceglie un *perno* $p$ appartenente al vettore e sposta tutti gli elementi più piccoli di $p$ a sinistra di $p$, tutti quelli più grandi a destra.
- Calcola l'indice j in modo che questa condizione venga rispettata e posiziona $p$ su data posizione
- Ordina ricorsivamente i due sottovettori a destra e a sinistra del perno.

```Java
int pivot(Item[] A, int start, int end)
```

```Ruby
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

```Ruby
int j = pivot(A, start, end)
QuickSort(A, start, j-1)
QuickSort(A, j, end)
```

Il costo di `pivot` è $\Theta(n)$, mentre `QuickSort` dal partizionamento:

- Se il vettore di dimensione n viene diviso in sottoproblemi di dimensione 0 e n - 1, generando una complessità pari a $\Theta(n^2)$.
- Se il vettore viene invece diviso in due sottoproblemi pari a n / 2, la complessità sarà pari a $\Theta(n \log n)$.

Per analizzare il caso medio, bisognerebbe eseguire uno studio probabilistico per verificare il comportamento dell'algoritmo dato un certo input.

### Moltiplicazione di matrici

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