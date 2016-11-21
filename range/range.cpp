/*
ID: mathgen2
PROG: range
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

char grid[255][255];
int DP[255][255] = {0};
int sz[255] = {0};

int main() {
  ifstream fin("range.in");
  ofstream fout("range.out");

  int n;
  fin >> n;
  for(int i = 0; i < n; i++){
  	for(int j = 0; j < n; j++){
  	  fin >> grid[i][j];
  	}
  }

  memset(DP, 0, sizeof(DP));
  for(int i = 0; i < n; i++){
  	DP[0][i] = grid[0][i]=='0'?0:1;
  	DP[i][0] = grid[i][0]=='0'?0:1;
  }
  memset(sz, 0, sizeof(sz));
  for(int i = 1; i < n; i++){
  	for(int j = 1; j < n; j++){
      if(grid[i][j]=='1'){
	    DP[i][j] = min(min(DP[i-1][j], DP[i][j-1]), DP[i-1][j-1])+1;
	    int ss = DP[i][j];
	    while(ss>=2){
	      sz[ss]++;
	      ss--;
	    }
	  }
	}
  }

  for(int i = 2; i <= n; i++){
  	if(sz[i]>0){
      fout << i << " " << sz[i] << endl;
  	}
  }
}