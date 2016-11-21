/*
ID: mathgen2
PROG: runround
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool runround(int n);

int dig(int n, int d){
  return (n/(int)pow(10, d)) % 10;
}

int main(){
  ifstream fin("runround.in");
  ofstream fout("runround.out");

  int n;
  fin >> n;
  n++;
  while(!runround(n)) n++;
  fout << n << endl;
}

bool runround(int n){
  bool seen[10] = {false};
  // check all digits are unique;
  int lgt = 0;
  for(int m = n; m > 0; m /= 10){
    if(seen[m%10]) return false;
    seen[m%10] = true;
    lgt++;
  }

  if(seen[0]) return false;  // digit cant be 0

  // now to simulate the weird running
  int curr_pos = lgt-1;  // we can start from any digit as it should be a cycle.
  bool beenat[10] = {false};
  for(int i = n; i > 0; i /= 10){
    beenat[curr_pos] = true;
    int digit = dig(n, curr_pos);
    curr_pos = ((curr_pos-digit+9*lgt) % lgt + lgt) % lgt;
  }
  
  int pos = 0;
  for(int i = n; i > 0; i /= 10){
    if(!beenat[pos]) return false;
    pos++;
  }
  return curr_pos == lgt-1;
}
