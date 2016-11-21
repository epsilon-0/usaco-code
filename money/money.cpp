/*
ID: mathgen2
PROG: money
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int coins[35];
long long DP[10005] = {0};

int main() {
  ifstream fin("money.in");
  ofstream fout("money.out");

  int v, n;
  fin >> v >> n;

  for(int i = 0; i < v; i++){
    fin >> coins[i];
  }

  DP[0] = 1;

  for(int i = 0; i < v; i++){
    for(int j = coins[i]; j <= n; j++){
      DP[j] += DP[j-coins[i]];
    }
  }

  fout << DP[n] << endl;
}
