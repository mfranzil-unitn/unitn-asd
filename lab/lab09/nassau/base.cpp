#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define LIM 200

//matrice Vascelli*VascelliFeriti*Fregate
double memo[LIM][LIM][LIM];

int V, F, M;

//Sottoproblema: forza attesa della flotta dati $v vascelli sani, $v1 vascelli feriti e $f fregate
double evDin(int v, int v1, int f) {
  int a = M - ((V*2 + F) - (v*2 + v1 + f)); //calcolo del numero di colpi sparati
  if (a == 0) {// Se ho finito i colpi restituisco la potenza
    return 1.0 * (v+v1)*f;
  }

  if (memo[v][v1][f] == -1.0) {
    memo[v][v1][f] =
      (
       (v ? (v * evDin(v-1, v1+1, f)): 0) + //se ci sono vascelli sani possono essere colpiti
       (v1 ? (v1 * evDin(v, v1-1, f)) : 0) + //se ci sono vascelli feriti possono essere distrutti
       (f ? (f * evDin(v, v1, f-1)) :0)  //se ci sono fregate possono essere distrutte
       ) / double(v+v1+f);
  }
  
  return memo[v][v1][f];
}

double aux(int V, int F, int M) {
  /*
    inizializza matrice memoizzazione
  */
  for (int v=0; v<LIM; v++) {
    for (int v1=0; v1<LIM; v1++) {
      for (int f=0; f<LIM; f++) {
	if ((v+v1)==0 || f==0)
	  memo[v][v1][f] = 0.0;
	else
	  memo[v][v1][f] = -1.0;
      }
    }
  }
  return evDin(V,0,F);
}

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  in >> V >> F >> M;
  out<< scientific << setprecision(10) << aux(V, F, M) << endl;
}

