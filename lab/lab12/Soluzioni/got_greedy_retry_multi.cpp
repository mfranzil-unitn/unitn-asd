#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <map>
#include <set>
#include "got.h"

#define SEED 2711

using namespace std;

#ifdef EVAL
ifstream in("input.txt");
ofstream out("output.txt");
#else
istream &in(cin);
ostream &out(cout);
#endif

default_random_engine myengine = default_random_engine(SEED);

typedef pair<pair<int,int>, int> PosVal;

int N, M;
vector<vector<int>> outgrid;
vector<vector<bool>> visited;
map<pair<int,int>,int> inmap;

void printOutgrid() {
  cout << "\t";
  for(int j=0; j<M; j++) {
    if(j==0) {
      cout << " ";
    }
    cout << j << "\t";
  }
  cout << endl;
  cout << "--\t";
  for(int j=0; j<M; j++) {
    if(j==0) {
      cout << "-";
    }
    cout << "-" << "\t";
  }
  cout << endl;

  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(j==0) {
        cout << i << "\t" << "|";
      }
      cout << outgrid[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "***" << endl;
}


void outputOutgrid() {
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      out << outgrid[i][j] << "\t";
    }
    out << endl;
  }
  out << "***" << endl;
}

pair<int,int> dx(1,0);
pair<int,int> up(0,1);
pair<int,int> sx(-1,0);
pair<int,int> dn(0,-1);
vector<pair<int,int>> DIFFS = {dx, up, sx, dn};


bool areValidCoords(int i, int j) {
  return (i>=0 && i<N) && (j>=0 && j<M);
}


int placeNumber(int i, int j, int pi, int pj, int value, int count, vector<pair<int,int>>& pos) {
  for(auto q: DIFFS) {
    int ni = i + q.first;
    int nj = j + q.second;

    if(areValidCoords(ni, nj) \
       && !(ni==pi && nj==pj) \
       && outgrid[ni][nj]==value) {
      // printf("*");
      return count;
    }
  }

  for(auto q: DIFFS) {
    int ni = i + q.first;
    int nj = j + q.second;


    // if (ni, nj) in inmap and count < value - 1
    if(areValidCoords(ni, nj) \
       && !(ni==pi && nj==pj) \
       && inmap.find(make_pair(ni,nj)) != inmap.end() \
       && outgrid[ni][nj]==0 \
       && count < value-1) {
      int val = inmap[make_pair(ni,nj)];

      if(val==value) {
        visited[i][j] = true;
        outgrid[i][j] = value;
        count = count + 1;
        pos.push_back(make_pair(i, j));
        count = placeNumber(ni, nj, i, j, value, count, pos);
        return count;
      }
    }
  }

  visited[i][j] = true;
  outgrid[i][j] = value;
  count = count + 1;
  pos.push_back(make_pair(i, j));

  shuffle(DIFFS.begin(), DIFFS.end(), myengine);
  for(auto p : DIFFS) {
    int ni = i + p.first;
    int nj = j + p.second;

    if(areValidCoords(ni, nj) && !visited[ni][nj]) {
      if(count<value) {
        count = placeNumber(ni, nj, i, j, value, count, pos);
      }
    }
  }

  return count;
}


int greedy(int i, int j, int value) {
  int score_area = 0;
  int score_placed = 0;

  int size = 0;
  vector<pair<int,int>> pos;

  if(value>1) {
    size = placeNumber(i, j, -1, -1, value, 0, pos);

    if(size<value) {
      for(auto xy : pos) {
        int x = xy.first;
        int y = xy.second;

        outgrid[x][y] = 0;

        // we don't want to mark the site of given as non-visited, otherwise
        // it could get overwritten later.
        if(!(x==i && y==j) && inmap.find(make_pair(x, y)) == inmap.end()) {
          visited[x][y] = false;
        }
      }
    } else {
      for(auto xy : pos) {
        int x = xy.first;
        int y = xy.second;
        if((x==i && y==j) || inmap.find(make_pair(x, y)) != inmap.end()) {
          score_placed = score_placed + 1;
        }
      }
      score_area = score_area + size;
    }
  } else {
    outgrid[i][j] = 1;
    score_placed = score_placed + 1;
    score_area = score_area + 1;
  }

  return score_area;
}


struct lt {
  inline bool operator() (const PosVal& a, const PosVal& b) {
    return (a.second < b.second);
  }
};


int main() {
  in >> N >> M;

  outgrid.resize(N, vector<int>(M));
  visited.resize(N, vector<bool>(M));

  vector<PosVal> ingrid;

  int tok = -1;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      in >> tok;
      if(tok>0) {
        ingrid.push_back(make_pair(make_pair(i, j), tok));
        inmap.insert(make_pair(make_pair(i, j), tok));
        visited[i][j] = true;
      }
    }
  }

  int maxscore = 0;
  sort(ingrid.begin(), ingrid.end(), lt());
  for (auto iter = ingrid.rbegin(); iter != ingrid.rend(); ++iter) {
    int i = iter->first.first;
    int j = iter->first.second;
    int value = iter->second;

    maxscore = maxscore + greedy(i, j, value);
  }

  // printOutgrid();
  outputOutgrid();

  int count_retry = 0;
  while(true) {
    count_retry++;
    int tmpscore = 0;

    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        outgrid[i][j] = 0;
        visited[i][j] = false;
      }
    }

    shuffle(ingrid.begin(), ingrid.end(), myengine);
    for (auto iter = ingrid.begin(); iter != ingrid.end(); ++iter) {
      int i = iter->first.first;
      int j = iter->first.second;

      visited[i][j] = true;
    }

    for (auto iter = ingrid.begin(); iter != ingrid.end(); ++iter) {
      int i = iter->first.first;
      int j = iter->first.second;
      int value = iter->second;

      tmpscore = tmpscore + greedy(i, j, value);
    }

    if(tmpscore > maxscore) {
      outputOutgrid();
      maxscore = tmpscore;
    }

    // if(count_retry>5) { break; }
  }

  return 0;
}
