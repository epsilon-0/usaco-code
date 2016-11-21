/*
ID: mathgen2
PROG: nocows
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 9901;

int DP[205][105] = {0};

int main() {
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");

  for(int i = 1; i < 105; i++) {
    DP[1][i] = 1;
    DP[0][i] = 1;
  }

  for(int h = 2; h < 105; h++) {
    for(int n = 1; n < 205; n+=2) {
      for(int c = 1; c < n; c+=2) {
        DP[n][h] = (DP[n][h] + DP[n-c-1][h-1]*DP[c][h-1]) % MOD;
      }
    }
  }

  int n, k;
  fin >> n >> k;
  fout << (DP[n][k] - DP[n][k-1] + MOD) % MOD << endl;
}