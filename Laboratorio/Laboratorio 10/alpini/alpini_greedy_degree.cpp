#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#ifdef EVAL
ifstream in("input.txt");
ofstream out("output.txt");
#else
istream &in(cin);
ostream &out(cout);
#endif

int N, M;

struct nodo{
  vector<int> vic;
  bool destroyed = false;
  bool visited = false;
  int degree = 0;
};

vector<nodo> g;


bool trova_ciclo(int n, int f, vector<bool>& vis){
  vis[n] = true;
  for(int v: g[n].vic){
    if(v != f && !g[v].destroyed){
      if(vis[v])
        return true;
      if(trova_ciclo(v, n, vis))
        return true;
    }
  }
  return false;
}

bool check_ciclo(){
  vector<bool> vis(N, false);
  for(int i=0;i<N;i++)
    if(!vis[i] && !g[i].destroyed)
      if(trova_ciclo(i, i, vis))
        return false;
  return true;
}


int main() {

  int D = 0;

  in >> N >> M;
  g.resize(N);

  for(int i=0;i<M;i++){
    int f, t;
    in >> f >> t;
    g[f].vic.push_back(t);
    g[f].degree ++;
    g[t].vic.push_back(f);
    g[t].degree ++;
  }

  while(!check_ciclo()){
    int id = -1;
    for(int i=0;i<N;i++)
      if(!g[i].destroyed && (id == -1 || g[i].degree > g[id].degree)){
        id = i;
      }
    g[id].destroyed = true;
    D++;
    for(int v: g[id].vic)
      g[v].degree--;
  }


  out<<D;
  for(int i=0;i<N;i++)
    if(g[i].destroyed)
      out<<" "<<i;
  out<<"#"<<endl;

  return 0;
}
