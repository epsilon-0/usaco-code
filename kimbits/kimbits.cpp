/*
ID: mathgen2
PROG: kimbits
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

long long choose(int n, int r){
  long long ans = 1;
  for(int i = 1; i <= r; i++){
    ans *= (n-r+i);
    ans /= i;
  }
  return ans;
}

long long ways(int n, int l){
  long long w = 0;
  for(int i = 0; i <= l; i++){
    w += choose(n, i);
  }
  return w;
}

int main() {
  ifstream fin("kimbits.in");
  ofstream fout("kimbits.out");

  int N,L;
  long long I;
  fin >> N >> L >> I;
  int l = L;
  for(int i = 0; i < N; i++){
    long long w = ways(N-i-1, l);
    cout << i << " " << w << " " << l << " " << I << endl;
    if(w < I){
      fout << '1';
      l--;
      I -= w;
    }
    else{
      fout << '0';
    }
  }
  fout << endl;
}
