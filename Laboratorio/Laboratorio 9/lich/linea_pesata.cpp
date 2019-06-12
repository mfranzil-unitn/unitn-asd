#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/*
Ci sono 2 portali, che si trovano alle estremità della linea,
sono gli unici nodi con un solo vicino;
 
Per ogni nodo si calcola la distanza dai $2$ portali e si prende quella
massima;

si enumerano tutti i possibili segmenti della linea, $C_i$ è la lunghezza del
segmento più lungo per il quale valgono i requisiti;
*/

struct nodo{
  vector<pair<int, int> > vic;
  int dist = -1;
};

vector<nodo> G;

int main(){ 
  int N;
  in >> N;
  G.resize(N);
  for(int i=0;i<N-1;i++){
    int v1, v2, w;
    in >> v1 >> v2 >> w;
    G[v1].vic.push_back(make_pair(v2,w));
    G[v2].vic.push_back(make_pair(v1,w));
  }

  int leaf=0;
  while(G[leaf].vic.size()>1)
    leaf++;

  vector<int> sequence;
  sequence.push_back(leaf);
  G[leaf].dist = 0;
  int cur = leaf;
  int prev = -1;
  while(sequence.size()<N){
    for(auto& edge:G[cur].vic){
      if(edge.first != prev){
        sequence.push_back(edge.first);
        prev = cur;
        cur = edge.first;
        G[cur].dist = G[prev].dist + edge.second;
        break;
      }
    }
  }

  int tot = G[sequence[sequence.size()-1]].dist;
  for(auto& node:G){
    node.dist= max(node.dist, tot-node.dist);
  }

  
  int L;
  in >> L;
  for(int i=0;i<L;i++){
    int curL;
    in >> curL;
    int best = 1;
    for(int i=0;i<N;i++){
      int mi, ma;
      mi = ma = G[sequence[i]].dist;
      for(int j=i+1;j<N;j++){
        mi = min(mi, G[sequence[j]].dist);
        ma = max(ma, G[sequence[j]].dist);
        if(ma-mi<=curL){
          best=max(best,j-i+1);
        }else{
          break;
        }
      }
    }
    out<<best<<endl;
  }

  
  return 0;
}

