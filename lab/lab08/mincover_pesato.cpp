#include <fstream>
#include <vector>
using namespace std;

struct nodo{
  vector<int> figli;
  int peso;
};

vector<nodo> albero;
vector<int>  S;
vector<int> L;

int N;

int getS(int);
int getL(int);

int getS(int node){
  if(S[node]==-1){
    S[node]=albero[node].peso;
    for(int f:albero[node].figli)
      S[node]+=getL(f);
  }
  return S[node];
}

int getL(int node){
  if(L[node]==-1){
    L[node]=0;
    for(int f:albero[node].figli)
      L[node]+=getS(f);
    L[node]=min(getS(node),L[node]);
  }
  return L[node];
}

int main(void) {
  ifstream in("input.txt");
  ofstream out("output.txt");
  in>>N;
  albero.resize(N);
  S.resize(N,-1);
  L.resize(N,-1);
  for(int i=0;i<N;i++)
    in>>albero[i].peso;
  for(int i=0;i<N-1;i++){
    int p,f;
    in>>p>>f;
    albero[p].figli.push_back(f);
  }
  out<<getL(0)<<endl;
  return 0;
}

