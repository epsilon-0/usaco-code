/*
ID: mathgen2
PROG: inflate
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5+1e4;
int val[MAXN], weight[MAXN], DP[MAXN];

int main() {
  ifstream fin("inflate.in");
  ofstream fout("inflate.out");
  int m, n;
  fin >> m >> n;

  for(int i = 0; i < n; i++){
    fin >> val[i] >> weight[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = weight[i]; j < m+5; j++){
      DP[j] = max(DP[j], DP[j-weight[i]] + val[i]);
    }
  }
  fout << DP[m] << endl;
}
