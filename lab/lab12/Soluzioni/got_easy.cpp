#include <bits/stdc++.h>
#include "got.h"
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int> > mappa;
vector<vector<bool> > visited;
int n, m;

struct nodo{
    int x;
    int y;
    int val;
    bool operator <(nodo a) const { // nodes are ordered by value in the priority queue I use
        return a.val < val;
    }
};

priority_queue<nodo> myqueue;

bool isvalid(int x, int y, int v){
    if(mappa[x][y] != 0)
        return false;
    return true;
}

int trysomething(int x, int y, int miss){ // miss = number of missing pieces to fill a block
    if(miss == 0)
        return 0;

    int v = mappa[x][y];

    // where I can move
    queue<nodo> trywith;
    if(x > 0) trywith.push({x-1,y,v});
    if(y > 0) trywith.push({x,y-1,v});
    if(x < n-1) trywith.push({x+1,y,v});
    if(y < m-1) trywith.push({x,y+1,v});

    bool stop = false;

    while(!stop){
        if(trywith.empty()){ // I cannot try nothing more, I return the number of missing pieces
            stop = true;
        }
        else{
            nodo next = trywith.front();
            trywith.pop();
            if(isvalid(next.x,next.y,next.val)){
                mappa[next.x][next.y] = next.val;
                miss = trysomething(next.x,next.y,miss-1);
                if(miss == 0)
                    stop = true;
            }
        }
    }

    return miss;
}

int dfs(int x, int y, int v){ // number of elements in the cc
    int nelements = 1;
    visited[x][y] = true;

    if(x > 0)
        if(mappa[x-1][y] == v && !visited[x-1][y])
            nelements += dfs(x-1,y,v);
    if(y > 0)
        if(mappa[x][y-1] == v && !visited[x][y-1])
            nelements += dfs(x,y-1,v);
    if(x < n-1)
        if(mappa[x+1][y] == v && !visited[x+1][y])
            nelements += dfs(x+1,y,v);
    if(y < m-1)
        if(mappa[x][y+1] == v && !visited[x][y+1])
            nelements += dfs(x,y+1,v);

    return nelements;
}

void setzero(int x, int y, int v){ // set to 0 all the cc with value v starting from (x,y)
    mappa[x][y] = 0;
    if(x > 0)
        if(mappa[x-1][y] == v)
            setzero(x-1,y,v);
    if(y > 0)
        if(mappa[x][y-1] == v)
            setzero(x,y-1,v);
    if(x < n-1)
        if(mappa[x+1][y] == v)
            setzero(x+1,y,v);
    if(y < m-1)
        if(mappa[x][y+1] == v)
            setzero(x,y+1,v);
    return;
}

int main (){

    in >> n >> m;

    mappa.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            in >> mappa [i][j];
            visited[i][j] = false;
            if(mappa[i][j] != 0){
                myqueue.push({i,j,mappa[i][j]});
            }
        }
    }

    while(!myqueue.empty()){
        nodo mynodo = myqueue.top();
        cout << mynodo.val << endl;
        myqueue.pop();
        trysomething(mynodo.x,mynodo.y,mynodo.val-1);

    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!visited[i][j] && mappa[i][j] != 0){
                if(dfs(i,j,mappa[i][j]) != mappa[i][j]){ // when I find a component with values different from #elements -> I set all zero
                    setzero(i,j,mappa[i][j]);
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            out << mappa[i][j] << "\t";
        }
        out << endl;
    }
    out << "***" << endl;

    return 0;
}
