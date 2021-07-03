#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

#ifdef EVAL
ifstream in("input.txt");
ofstream out("output.txt");
#else
istream &in(cin);
ostream &out(cout);
#endif

/*
 * Il primo soldato consegna tutte le le componenti, partendo da quella
 * per cui d1 - d2 è minima.
 *
 */

struct punto {
  int x;
  int y;

  // costruttore
  punto() : x(0), y(0) {}
};

// numerp componenti, numero soldati
int nC, nS;

// vettore componenti, vettori soldati, target
vector<punto> C;
vector<punto> S;
punto T;


void read_input() {
  in >> nC >> nS;

  C.resize(nC);
  S.resize(nS);

  for(int i=0; i<nC; i++) {
    int x, y;
    in >> x >> y;
    
    C[i].x = x;
    C[i].y = y;
  }  

  for(int j=0; j<nS; j++) {
    int x, y;
    in >> x >> y;
    
    S[j].x = x;
    S[j].y = y;
  }

  // (temporary) variable scoping
  {
    int x, y;
    in >> x >> y;
    T.x = x;
    T.y = y;
  }
}


int distance(const punto& A, const punto& B) {
  return (abs(A.x-B.x) + abs(A.y-B.y));
}


int main(void) {

  read_input();

  // "mesciu" o il "mastro" in dialetto salentino
  // http://www.dialettosalentino.it/mesciu.html
  punto mesciuscintu(S[0]);

  int diffmin = INT_MAX;
  int minid = -1;
  for(int i=0; i<nC; i++) {
    int d1 = distance(mesciuscintu, C[i]) + distance(C[i], T);
    int d2 = 2*distance(C[i], T);
    int diff = d1 - d2;

    if(diff < diffmin) {
      diffmin = diff;
      minid = i;
    }
  }

  // recupero la componente più conveniente
  int disttot = 0;
  disttot = distance(mesciuscintu, C[minid]) + distance(C[minid], T);

  // recupero tutte le altre componenti
  for(int i=0; i<nC; i++) {
    if(i==minid) { continue; }
    disttot += 2*distance(C[i], T);
  }

  // tutte le componenti sono consegnate dall'unico soldato presente (id: 0)
  out << disttot << endl;
  for(int i=0; i<nC; i++) {
    out << 0 << endl;
  }

  return 0;
}
