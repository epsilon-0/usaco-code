/*
ID: mathgen2
PROG: game1
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int DP[105][105];
int sums[105];
int num[105];

int main() {
  ifstream fin("game1.in");
  ofstream fout("game1.out");
  int n;
  fin >> n;
  memset(sums, 0, sizeof(sums));
  memset(DP, 0, sizeof(DP));
  memset(num, 0, sizeof(num));

  for(int i = 1; i <= n; i++){
  	fin >> num[i];
  	sums[i] = sums[i-1] + num[i];
  }

  for(int i = 1; i <= n; i++){
  	DP[i][i] = num[i];
  	//cout << DP[i][i] << " " << sums[i] << endl;
  }

  for(int i = 1; i <= n-1; i++)
  	for(int j = 1; j <= n-i; j++){
		DP[j][i+j] = sums[i+j] - sums[j-1] - min(DP[j][i+j-1], DP[j+1][i+j]);
		//cout << j << " " << i+j << " " << DP[j][i+j] << endl;
  	}
  fout << DP[1][n] << " " << sums[n]-sums[0]-DP[1][n] << endl;
}
