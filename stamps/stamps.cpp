/*
ID: mathgen2
PROG: stamps
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

long long stamps[50];
int DP[2000005];

int main() {
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");

  for(int i = 0; i < 2000005; i++){
    DP[i] = 500;
  }

  int k, n;
  fin >> k >> n;
  for(int i = 0; i < n; i++){
    fin >> stamps[i];
  }

  DP[0] = 0;
  for(int j = 0; j < n; j++){
    for(int i = stamps[j]; i < 2000005; i++){
      DP[i] = min(1+DP[i-stamps[j]], DP[i]);
    }
  }
  int mMax = 0;
  for(; mMax < 2000005 && DP[mMax] <= k; mMax++);

  fout << mMax-1 << endl;
}
