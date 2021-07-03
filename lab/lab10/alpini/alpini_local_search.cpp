#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include "alpini.h"
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
  bool inlist = false;
  int left = 0;
};

vector<nodo> g;


void local_search(){
  vector<int> l;
  int st = rand()%N;
  l.push_back(st);
  g[st].inlist=true;
  int best = 0;

  double T = 0.9;
  double alpha = 0.99;
  int Nt = 50;

  int count = 0;
  while(true){
    int next;
    do{
      next = rand()%N;
    }while(g[next].inlist);
    set<int> s(g[next].vic.begin(), g[next].vic.end());
    vector<int> vic;
    for(int i=0;i<l.size();i++){
      if(s.find(l[i]) !=s.end()){
        vic.push_back(i);
      }
    }

    if(vic.size()==0){
      l.insert(l.begin(), next);
      g[next].inlist=true;
    }else if(vic.size()==1){
      l.insert(l.begin()+vic[0]+1, next);
      g[next].inlist=true;
      g[next].left = 1;
    }else{
      int del = 0;
      for(int i=1;i<vic.size();i++){
        if(g[l[vic[i]]].left == 1)
          del++;
      }

      int delta = -1 + del;
      double r = rand()/(RAND_MAX+1.0);
      double p = exp(-delta/T);
      if(delta <=0 || r < exp(-delta/T)){
        for(int i=l.size()-1;i>vic[0];i--){
          if(s.find(l[i])!=s.end()){
            if(g[l[i]].left == 0){
              g[l[i]].left = 1;
            }else{
              int v = l[i];
              l.erase(l.begin()+i);
              g[v].inlist=false;
              g[v].left = 0;
            }
          }
        }
        l.insert(l.begin()+vic[0]+1, next);
        g[next].inlist=true;
        g[next].left = 1;
      }
      if(g[next].inlist){
        count++;
        if(count==Nt){
          count = 0;
          T *= alpha;
        }
      }
    }
    if(l.size()> best){
      best = l.size();
      out<<N-l.size();
      for(int i=0;i<N;i++)
        if(!g[i].inlist)
          out<<" "<<i;
      out<<"#"<<endl;
    }

  }
}

int main() {
  in >> N >> M;
  g.resize(N);

  for(int i=0;i<M;i++){
    int f, t;
    in >> f >> t;
    g[f].vic.push_back(t);
    g[t].vic.push_back(f);
  }


  local_search();

  return 0;
}
