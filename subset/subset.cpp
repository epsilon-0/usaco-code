/*
ID: mathgen2
PROG: subset
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

long long DP[45][2025] = {0};  // DP[i][j] = #ways to get j using first i numbers

int main(){
  ifstream fin("subset.in");
  ofstream fout("subset.out");

  int n;
  fin >> n;
  
  if(n*(n+1) % 4){
    fout << 0 << endl;
    return 0;
  }

  DP[1][1] = 1;
  DP[1][0] = 1;
  
  for(int i = 2; i < n+2; i++){
    for(int j = 0; j < 2000; j++){
      DP[i][j] = DP[i-1][j];
      if(j > i){
	DP[i][j] += DP[i-1][j-i];
      }
    }
  }
  fout << DP[n][n*(n+1)/4] << endl;
}
