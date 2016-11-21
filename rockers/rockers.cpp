/*
ID: mathgen2
PROG: rockers
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int DP[25][25][25], song[25];

int main() {
  ifstream fin("rockers.in");
  ofstream fout("rockers.out");

  int n, t, m;
  fin >> n >> t >> m;
  for(int i = 1; i <= n; i++)
  	fin >> song[i];

  memset(DP, 0, sizeof(DP));

  for(int i = 1; i <= m; i++)
  	for(int j = 0; j <= t; j++)
  		for(int k = 1; k <= n; k++){
  			if(j==0)
  				DP[i][j][k] = DP[i-1][t][k];
  			else if(song[k]<=j)
  				DP[i][j][k] = max(DP[i][j-song[k]][k-1] + 1, DP[i][j][k-1]);
  			else if(song[k]>j)
  				DP[i][j][k] = max(DP[i-1][t][k], DP[i][j][k-1]);
  		}
  fout << DP[m][t][n] << endl;
}
