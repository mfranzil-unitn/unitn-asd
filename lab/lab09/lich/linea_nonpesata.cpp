#include <fstream>
using namespace std;

/*
La soluzione si può esprimere tramite una formula chiusa,
il numero massimo di cavalieri C è funzione di N e L:
            
             / min(N, 2*(1+L)    se N è pari
  C(N, L) = <
             \ min(N, 1+2*L)     se N è dispari

non serve memorizzare la dispozione dei nodi, conoscendo
N si ricostruisce la struttura della linea.
*/

int main(){ 
  int N;
  in >> N;
  int v;
  for(int i=0;i<N-1;i++)
    in >> v >> v >> v;
  int L;
  in >> L;
  for(int i=0;i<L;i++){
    int cur;
    in >> cur;
    if(N%2==0){
      out<<min(N, (cur+1)*2)<<endl;
    }else{
      out<<min(N, 1+cur*2)<<endl;      
    }
  }
  return 0;
}
