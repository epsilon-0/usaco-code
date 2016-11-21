/*
ID: mathgen2
PROG: fracdec
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

bool visited[MAXN] = {false};

int length(int num){
  int ans = 0;
  do{
    ans++;
    num /= 10;
  }while(num);
  return ans;
}

int main() {
  ifstream fin("fracdec.in");
  ofstream fout("fracdec.out");

  int n, d;
  
  fin >> n >> d;

  int lgt = length(n/d); lgt++;

  fout << n/d << ".";

  int rem = n % d;

  while(!visited[rem] && rem != 0){
    visited[rem] = true;
    rem *= 10;
    rem %= d;
  }

  cout << rem << endl;

  int cycleStart = rem;

  rem = n % d;

  int passed = 0;
  if(rem == 0)
    fout << 0;

  while(1){
    if(rem == cycleStart){
      passed++;
      if(passed == 1 && rem != 0){
	fout << "(";
	lgt = (lgt + 1) % 76;
      }
      else{
	break;
      }
    }
    if(lgt == 0){
      fout << "\n";
    }    rem *= 10;
    if(rem != 0)
      fout << rem / d;
    rem %= d;
    lgt = (lgt + 1) % 76;
  }
  if(rem != 0)
    fout << ")";
  fout << endl;
}
