#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "tsp.h"
using namespace std;

#ifdef EVAL
ifstream in("input.txt");
ofstream out("output.txt");
#else
istream &in(cin);
ostream &out(cout);
#endif

#define MAXN 1000

int N;

double w[MAXN][MAXN];

stack<int> qstack;
double best_w= 1000000000.0;

void print(){
  stack<int> bk = qstack;
  out<<0;
  while(!qstack.empty()){
    out<<" "<<qstack.top();
    qstack.pop();
  }
  out<<"#"<<endl;
  qstack = bk;
}

/*
Stima lower bound costo atteso prendendo il minimo per ogni riga
 */
double estimate(vector<bool>&visited, int depth){
  double lb = 0.0;
  for(int i=0;i<N;i++)
    if(!visited[i]){
      if(depth == N-2)
        return w[i][0];
      double b=10000000.0;
      for(int j=0;j<N;j++)
        if(!visited[j] && i!=j)
          b = min(b, w[i][j]);
      lb += b;
    }
  return lb;
}
void recursive_branch_and_bound(vector<bool>& visited, double cur_w, int depth){
  int cur = qstack.top();
  if(depth == N-1){ // Se siamo nell'ultimo caso, lo stampiamo se è un miglioramento
    cur_w += w[cur][0];
    if(best_w > cur_w){
      best_w = cur_w;
      print();
    }
    return;
  }
  vector<pair<double, int>> choices;


  double es = estimate(visited, depth);
  //Stimiamo lower bound per ogni possibile mossa successiva
  for(int i=0;i<N;i++){
    if(!visited[i]){
      choices.push_back(make_pair(w[cur][i] + es, i));
    }
  }
  sort(choices.begin(), choices.end());
  int c = 0;
  //Visitiamo le scelte se lower bound è migliore di best
  for(auto p:choices){
    c++;
    if(p.first + cur_w < best_w){
      visited[p.second]=true;
      qstack.push(p.second);
      recursive_branch_and_bound(visited, cur_w + w[cur][p.second], depth+1);
      qstack.pop();
      visited[p.second]=false;
    }else{
      break;
    }
  }

}

int main() {
  in >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      in >> w[i][j];
      w[j][i]=w[i][j];
    }
  }

  for(int h=0;h<N;h++)
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        if(w[i][j] > w[i][h] + w[h][j])
          w[i][j] = w[i][h] + w[h][j];

  vector<bool> visited(N, false);
  visited[0]=true;
  qstack.push(0);
  recursive_branch_and_bound(visited, 0, 0);
  return 0;
}
