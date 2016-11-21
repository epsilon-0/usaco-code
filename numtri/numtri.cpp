/*
ID: mathgen2
PROG: numtri
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1+1e3;

int num[MAXN][MAXN] = {0};

int main(){
  ifstream fin("numtri.in");
  ofstream fout("numtri.out");
  int r;
  fin >> r;
  for(int i = 1;  i <= r; i++)
    for(int j = 1; j <= i; j++){
      fin >> num[i][j];
      num[i][j] += max(num[i-1][j], num[i-1][j-1]);
    }
  int mmax = num[r][1];
  for(int i = 1; i <= r; i++){
    mmax = max(mmax, num[r][i]);
  }
  fout << mmax << endl;
}
