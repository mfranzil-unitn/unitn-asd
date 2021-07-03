#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 501;

#ifdef EVAL
ifstream in("input.txt");
ofstream out("output.txt");
#else
istream &in(cin);
ostream &out(cout);
#endif

int N;
string inp;

int DP[MAXN][MAXN][2][2];

int canDelete(int l, int r, int st, int en) {
  // we succeeded in removing the whole string
  if (l > r) { return 1; }

  if (DP[l][r][st][en] != -1) {
    return DP[l][r][st][en];
  }

  int ans = 0;

  // i is the last removed triangle, which will eliminate the whole
  // string[l, r]
  for (int i = l + st; i <= r - en; i++)
  {
    if (inp[i] == 's') {
      // it will remove a triangle to the left, but which one?
      for (int j = l; j < i; j++) {
        // triangle i will remove triangle j
        if (canDelete(l, j - 1, st, 0)
            && canDelete(j + 1, i - 1, 0, 0)
            && canDelete(i + 1, r, 0, en))
          ans = 1;
      }
    }
    else
      // it will remove a ball to the right, but which one?
      if (inp[i] == 'd') {
        for (int j = i + 1; j <= r; j++) {
          // ball i will remove ball j
          if (canDelete(l, i - 1, st, 0)
              && canDelete(i + 1, j - 1, 0, 0)
              && canDelete(j + 1, r, 0, en))
            ans = 1;
        }
      }
    }

  // memoization
  DP[l][r][st][en] = ans;

  return ans;
}

int main(void) {
  in >> N;
  in >> inp;

  assert(inp.size() == N);

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      for(int d=0; d<2; d++) {
        for(int e=0; e<2; e++){
          DP[i][j][d][e] = -1;
        }
      }
    }
  }
  vector<int> sol;
  for(int i=0; i<N; i++) {
    if(canDelete(0,i-1,1,0) && canDelete(i+1,N-1,0,1)) {
      sol.push_back(i);
    }
  }
  out << sol.size() << endl;
  for(int i:sol) {
    out << i <<" ";
  }

  return 0;
}
