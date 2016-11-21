/*
ID: mathgen2
PROG: fact4
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int P(int n){
  int A[] = {6, 2, 4, 8};
  return (n<1)?1:A[n%4];
}

int L(int n){
  int A[] = {1,1,2,6,4};
  return (n<5)?A[n]:((P(n/5)*L(n/5)*L(n%5))%10);
}

int main() {
  ifstream fin("fact4.in");
  ofstream fout("fact4.out");

  int n;
  fin >> n;
  fout << L(n) << endl;
}
