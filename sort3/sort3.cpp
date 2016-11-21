/*
ID: mathgen2
PROG: sort3
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3+1e3;

int num[MAXN], arr[MAXN];

int main(){
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");
  int n;
  fin >> n;
  for(int i = 0; i < n; i++){
    fin >> num[i];
    arr[i] = num[i];
  }
  sort(arr, arr+n);
}
