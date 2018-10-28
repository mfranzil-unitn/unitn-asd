# Appunti di Algoritmi e Strutture Dati [20180927 -]

- [Appunti di Algoritmi e Strutture Dati [20180927 -]](#appunti-di-algoritmi-e-strutture-dati-20180927--)
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
            - [Visite degli alberi binari](#visite-degli-alberi-binari)
            - [Alberi generici](#alberi-generici)
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
            - [Rotazioni](#rotazioni)
            - [Inserimento con condizioni negli alberi RB](#inserimento-con-condizioni-negli-alberi-rb)
  
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

Possiamo trovare all'interno di ambiti informatici o meno tantissimi esempi di alberi; ad esempio, l'albero genealogico, così come la struttura di una pagina HTML può essere rappresentata con un albero.

#### Albero radicato

Un **albero radicato** è un particolare tipo di albero nella quale un certo nodo è designato come **radice**, ogni nodo ha esattamente un arco entrante (eccetto la radice), esiste un cammino unico tra un nodo e l'altro, e l'albero è connesso.

Definiamo come **profondità** la lunghezza del cammino dalla radice al nodo misurato in numero di archi; **livello** l'insieme di nodi alla stessa profondità; **altezza** la profondità massima.

#### Alberi binari

Un **albero binario** è un albero radicato in cui ogni nodo ha al massimo due figli, identificati come *sinistro* e *destro*. Vedi slide per implementazione della struttura dati

#### Visite degli alberi binari

Un albero binario può essere visitato *in profondità* (ovvero ricorsivamente sui sottoalberi) oppure *in ampiezza* (ovvero per livello).

Per la visità in profondità, si usa uno *stack* per gestire le chiamate ricorsive.

```ruby
def dfs(t):
    if t != nil:
        # pre-order visit of t
        print(t)

        dfs(t.left())

        # in-order visit of t
        print(t)

        dfs(t.right())

        # post-order visit of t
        print(t)
```

La post-visita viene spesso applicata per il conteggio dei nodi di un dato albero.

```ruby
def count(T):
    if T == nil:
        return 0
    else
    Cl = count(T.left())
    Cr = count(T.right())
    return Cl + Cr + 1
```

L'in-visita viene spesso applicata per stampare espressioni matematiche. Un'espressione matematica puà essere infatti sintetizzata tramite un albero binario nella quale le foglie sono numeri e i padri sono operazioni. Il corso computazionale è generalmente $\Theta(n)$.

```ruby
def printExp(T)
    if T.left() == nil and T.right == nil:
        print T.read()
    else
        print("(")
        printExp(T.left())
        print(T.read())
        printExp(T.right())
        print(")")
```

#### Alberi generici

Un albero generico differisce dagli alberi binari in quanto può avere un numero arbitrario di figli. L'implementazione nel codice differisce per l'uso di iteratori per scorrere in tutti i sottoalberi, dato un certo nodo.

Vediamo ora la visita in ampiezza di un albero generico che è perfettamente applicabile anche a quelli binari. Si utilizza una coda per gestire i nodi da visitare.

```ruby
def bfs(t):
    Queue Q = Queue()
    Q.enqueue(t)
    while not Q.isEmpty() do
        Tree u = Q.dequeue()

        # visita per livelli dal nodo u
        print u
        u = u.leftmostChild()
        while u != nil do
            Q.enqueue(u)
            u = u.rightSibling()
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

Nel caso dell'incremento, avremo che il costo effettivo di $n$ operazioni sarà pari a $O(n^2) = O(n)$, ma il costo ammortizzato sarà pari a $O(n)$.

## 23/10/2018

Esercitazione svolta in Aula A101. Nessun nuovo argomento di teoria trattato.

## 25/10/2018

### Alberi binari di ricerca

Andiamo ora ad approfondire l'implementazione di un albero binario di ricerca tramite un dizionario. L'idea è quella di ottenere una struttura dati efficiente per la ricerca, sfruttando la ricerca con complessità $O(\log n)$ negli alberi. Avremo quindi il nostro albero con nodi aventi questa struttura:

> `Tree`
> `Tree parent`
> `Tree left`
> `Tree right`
> `Item key`
> `Item value`

In un albero binario di ricerca, avremo che le chiavi contenute nei nodi del sottoalbero sinistra di un qualsiasi nodo $u$ saranno più piccole di `u.key` e le chiavi contenute in quello di destra saranno maggiori. Le funzioni a nostre disposizione saranno le stesse degli alberi binari; andremo ora a implementare delle funzioni per inserire, visitare e rimuovere nodi nel nostro albero.

#### Funzioni degli alberi binari di ricerca

`lookupNode()` restituirà il nodo dell'albero T che contiene la chiave k, oppure nil.

```c++
Tree lookupNode(Tree T, Item k)
```

```python
Tree u = T
while u != nil and u.key != k:
    if k < u.key then
        u = u.left # Sotto-albero di sinistra
    else
        u = u.right # Sotto-albero di destra
return u
```

`max()` e `min()` restituiranno rispettivamente il massimo e il minimo di un albero; questi saranno sempre e comunque il nodo in fondo a destra e rispettivamente a sinistra di qualsiasi albero binario di ricerca.

```c++
Tree min(Tree T)
```

```python
Tree u = T
while u.left != nil do
    u = u.left
return u
```

```c++
Tree max(Tree T)
```

```python
Tree u = T
while u.right != nil do
u = u.right
return u
```

`successorNode()` e `predecessorNode()` ritroveranno rispettivamente il successore (ovvero il più piccolo nodo maggiore di un dato nodo u) e il predecessore (ovvero il più grande nodo minore di un dato nodo u). Per fare ciò, ad esempio, `successorNode()` va a cercare prima nei suoi figli destri e ne prende il minimo; se non ha figli destri, risalendo attraverso i padri, il predecessore è il primo avo $v$ tale per cui il nodo di partenza $u$ è nel suo sottoalbero sinistro.

```c++
Tree predecessorNode(Tree t)
```

```python
if t == nil then
    return t
if t.left != nil then # Caso 1
    return max(t.left)
else # Caso 2
    Tree p = t.parent
    while p != nil and t == p.left do
        t = p
        p = p.parent
    return p
```

```c++
Tree successorNode(Tree t)
```

```python
if t == nil then
r   eturn t
if t.right != nil then # Caso 1
    return min(t.right)
else # Caso 2
    Tree p = t.parent
    while p != nil and t == p.right do
        t = p
        p = p.parent
    return p
```

`insertNode()` andrà a inserire un'associazione chiave valore nell'albero T; se la chiave è già presente, verrà sostituito il valore, altrimenti verrà inserita una nuova associazione. Alla fine il metodo va a restituire l'albero T inalterato oppure un nuovo albero T nel caso fosse stato appena creato (= è stato passato nil come parametro).

```c++
Tree insertNode(Tree T, Item k, Item v)
```

```python
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

```c++
link(Tree p, Tree u, Item k)
```

```python
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

```c++
Tree removeNode(Tree T, Item k)
```

```python
Tree t
Tree u = lookupNode(T, k)
if u != nil then
    if u.left == nil and u.right == nil then # Caso 1
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

#### Rotazioni

Qui segue l'esempio di una rotazione a sinistra. 

```c++
Tree rotateLeft(Tree x)
```

```python
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

#### Inserimento con condizioni negli alberi RB

Per inserire un nodo senza rompere i vincoli in un albero RB, si colora inizialmente il nodo di rosso e poi, risalendo, si sceglie uno tra 7 casi diversi per sistemare eventuali vincoli violati. Innanzitutto nella `insertNode()` andremo a inserire la chiamata del nostro nuovo metodo subito dopo `link()`. Nel nostro `balanceInsert()` inseriremo un enorme ciclo `while` nella quale andremo a risalire l'albero una volta inserito il nodo, via via sistemando i nodi che non rispettano i vincoli. I 7 casi citati in precedenza sono:

1. Il nuovo nodo $t$ non ha padre; significa che si tratta del primo nodo o che siamo arrivati alla radice. Lo coloriamo di nero.
2. Il padre di $t$ è nero; allora no problem, lo inseriamo normalmente.
3. Abbiamo il caso in cui $t$ è rosso, così come il padre e lo zio (ovvero il fratello del padre). Risolviamo colorando padre e zio di nero e continuando per vedere se abbiamo violato vincoli sul nonno.
4. Abbiamo il caso in cui il padre è rosso e lo zio è nero, e t è figlio **destro** di $p$, $p$ figlio **sinistro** di $n$. Allora procediamo con una rotazione a **sinistra** a partire del nodo $p$, ottenendo che $t$ sarà ora il figlio di $n$. Una variante sul tema è quando si scambia sinistro e destro e viceversa.
5. Abbiamo il caso in cui il padre è rosso e lo zio è nero, e t è figlio **sinistro** di $p$, $p$ figlio **sinistro** di $n$. Allora procediamo con una rotazione a **destra** a partire del nodo $n$, ottenendo che $t$ sarà ora il figlio di $p$. Una variante sul tema è quando si scambia sinistro e destro e viceversa.

```c++
balanceInsert(Tree t)
```

```python
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

Questo algoritmo ha complessità totale $O(n \log n)$. Per quanto riguarda la cancellazione, potremmo andare a implementare `balanceDelete()` per ripristinare la proprietà Red-Black in caso di cancellazione. In particolare:

- Se il nodo “cancellato” è rosso
    - Altezza nera invariata
    - Non sono stati creati nodi rossi consecutivi
    - La radice resta nera
- Se il nodo “cancellato” è nero
    - Possiamo violare il vincolo 1: la radice può essere un nodo rosso
    - Possiamo violare il vincolo 3: se il padre e uno dei figli del nodo cancellato erano rossi
    - Abbiamo violato il vincolo 4: altezza nera cambiata