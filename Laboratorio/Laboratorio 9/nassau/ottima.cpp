#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int V, F, M;

double memo[2][2][20000];
/*
La funziona di ricorrenza cerca di calcolare la probabilità che una specifica coppia Vascello/Fregata sopravviva ai colpi.

La funzione di ricorrenza ha come parametri:
hp2: il numero di navi con due punti vita
hp1: il numero di navi con un punto vita
wounded: 1 se il vascello iniziale è ferito.
 */

double solve(){
  for(int hp2 =0; hp2 <= V; hp2++){
    for(int wounded = 1; wounded>=0 ; wounded--){
      for(int hp1 = 0; hp1 <= V+F; hp1++){
	double score = 0.0;
	// Dati i numeri di navi, possiamo calcolare quanti colpi sono stati già effettuati
	int shot = (V * 2 + F) - (hp2*2 + hp1 + (2 - wounded) + 1);
	if (shot==M)
	  //La coppia è sopravvissuta
	  score = 1.0;
	else{
	  if(wounded == 0) //Potrebbe essere colpito il vascello sano con probabilità 1/(hp1+hp2+2)
	    score += memo[hp2%2][1][hp1] / (hp1 + hp2 + 2.0);
	  if(hp2 > 0) //Potrebbe essere colpito uno dei vascelli sani con probabilità hp2/(hp1+hp2+2)
	    score += memo[(hp2-1)%2][wounded][hp1+1] * hp2 / (hp2 + hp1 + 2.0);
	  if(hp1 > 0) //Potrebbe essere affondata una nave da 1 punto vita con probabilità hp1/(hp1+hp2+2)
	    score += memo[hp2%2][wounded][hp1-1] * hp1 / (hp2 + hp1 + 2.0);
	}
	memo[hp2%2][wounded][hp1] = score;
      }
    }
  }
  return memo[(V-1)%2][0][F-1];
}

int main(void)
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  in >> V >> F >> M;
  if(V == 0 || F == 0) //Risposta ovvia
    out << 0 <<endl;
  else{
    double p = solve();
    // Notare che la probabilità di sopravvivenza di una coppia
    // va moltiplicata per il numero di coppie
    out<< scientific <<setprecision(10) << p * (V*F) << endl;
  }
  return 0;
}

