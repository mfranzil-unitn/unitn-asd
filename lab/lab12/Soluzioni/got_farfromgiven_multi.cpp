#include <bits/stdc++.h>
#include "got.h"
using namespace std;

#define SEED 2711

default_random_engine myengine = default_random_engine(SEED);

ifstream in("input.txt");
ofstream out("output.txt");

vector<vector<int>> mappa;
vector<vector<bool>> visited;
vector<vector<int>> outmappa;
vector<vector<bool>> usedgivens;

int n, m, score1, score2;

struct nodo{
    int x;
    int y;
    int val;
    bool operator <(nodo a) const {
        return a.val > val;
    }
};

vector<nodo> givens;

bool isvalid(int x, int y, int v){
    // check neighborhood
    queue<nodo> nghb;
    if(x > 0) nghb.push({x-1,y,v});
    if(y > 0) nghb.push({x,y-1,v});
    if(x < n-1) nghb.push({x+1,y,v});
    if(y < m-1) nghb.push({x,y+1,v});

    while(!nghb.empty()){
        nodo next = nghb.front();
        nghb.pop();
        if(outmappa[next.x][next.y] == v)
            return false;
    }

    if(((mappa[x][y] == 0 && outmappa[x][y] == 0) || (outmappa[x][y] == 0 && mappa[x][y] == v)) && !visited[x][y])
        return true;

    return false;
}

int d(int x, int y, int v, int x0, int y0){ // returns 0 if (x,y) is a given of the same value not used,
                                            // returns 1 if (x,y) has a nghb which is a given of the same value not used,
                                            // returns 2 if (x,y) has not a nghb which is a given different from v
                                            // returns 3 otherwise
                                            // (x0,y0) = where I came from

    if(mappa[x][y] == v && outmappa[x][y] == 0)
        return 0;

    queue<nodo> nghb;
    if(x > 0) nghb.push({x-1,y,v});
    if(y > 0) nghb.push({x,y-1,v});
    if(x < n-1) nghb.push({x+1,y,v});
    if(y < m-1) nghb.push({x,y+1,v});

    while(!nghb.empty()){
        nodo next = nghb.front();
        nghb.pop();
        int nx = next.x, ny = next.y;
        if(nx != x0 || ny != y0){
            if(mappa[nx][ny] == v && outmappa[nx][ny] == 0)
                return 1;

            if(mappa[nx][ny] != 0 && mappa[nx][ny] != v && !usedgivens[nx][ny])
                // if this nghb is a given with value different from v (that I cannot join) not used
                return 3;
        }
    }

    return 2;
}

void bestmove(int x, int y, int v, queue<nodo>& trywith){ // chooses the order for visiting nghb -> in trywith
    vector<pair<int,pair<int,int>>> order; // will be ordered looking the first argument

    if(x > 0) trywith.push({x-1,y});
    if(y > 0) trywith.push({x,y-1});
    if(x < n-1) trywith.push({x+1,y});
    if(y < m-1) trywith.push({x,y+1});

    while(!trywith.empty()){
        nodo next = trywith.front();
        trywith.pop();
        int nx = next.x, ny = next.y, dist = d(nx,ny,v,x,y);
        order.push_back({dist,{nx,ny}});
    }

    sort(order.begin(),order.end());

    for(int i = 0; i<order.size(); i++){
        trywith.push({order[i].second.first, order[i].second.second, v});
    }

    return;
}

bool trysomething(int x, int y, vector<nodo>& pos, int v){ // pos = positions I want to fill with value v
    if(!isvalid(x,y,v))
        return false;

    visited[x][y] = true;

    if(v == pos.size())
        return true;

    queue<nodo> trywith; // where I can move
    bestmove(x,y,v,trywith);

    bool stop = false;

    while(!stop){
        if(trywith.empty()){ // I cannot try nothing more, I return the number of missing pieces
            stop = true;
        }
        else{
            nodo next = trywith.front();
            trywith.pop();
            if(isvalid(next.x,next.y,v)){
                pos.push_back({next.x,next.y,v});
                trysomething(next.x,next.y,pos,v);
                if(v == pos.size())
                    stop = true;
            }
        }
    }

    return v == pos.size(); // I have a block of the right dimension
}

int solve(){

    int nv = 0; // number of valid given I used

    for(int i = 0; i<givens.size(); i++){
        nodo mynodo = givens[i];
        vector<nodo> pos;

        pos.push_back({mynodo.x, mynodo.y,mynodo.val});

        if(!usedgivens[mynodo.x][mynodo.y]){
            if(trysomething(mynodo.x,mynodo.y,pos,mynodo.val)){
                for(int j = 0; j<pos.size(); j++){
                    int px = pos[j].x;
                    int py = pos[j].y;
                    outmappa[px][py] = pos[j].val;

                    if(mappa[px][py] != 0){
                        // is a given
                        usedgivens[px][py] = true;
                        nv++;
                    }
                }
            } else {
                for(int j = 0; j<pos.size(); j++){
                    visited[pos[j].x][pos[j].y] = false;
                }
            }
        }

    }

    return nv;

}

int main (){

    in >> n >> m;

    mappa.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));
    outmappa.resize(n, vector<int>(m));
    usedgivens.resize(n, vector<bool>(m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            in >> mappa [i][j];
            visited[i][j] = false;
            outmappa[i][j] = 0;
            usedgivens[i][j] = false;
            if(mappa[i][j] != 0){
                givens.push_back({i,j,mappa[i][j]});
            }
        }
    }

    score1 = 0; // maxscore
    score2 = solve(); // score for this "round"

    while(true){

        if(score2 > score1){
            score1 = score2;

            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    out << outmappa[i][j] << "\t";

                    // reset for next try
                    visited[i][j] = false;
                    outmappa[i][j] = 0;
                    usedgivens[i][j] = false;
                }
                out << endl;
            }
            out << "***" << endl;
        } else {
            for(int i = 0; i<n; i++){
                for(int j = 0; j<m; j++){
                    visited[i][j] = false;
                    outmappa[i][j] = 0;
                    usedgivens[i][j] = false;
                }
            }
        }

        shuffle(givens.begin(),givens.end(),myengine);
        score2 = solve();
    }

    return 0;
}
