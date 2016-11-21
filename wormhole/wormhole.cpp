/*
ID: mathgen2
PROG: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 13;

int n, X[MAXN], Y[MAXN];
int partner[MAXN], on_right[MAXN];

bool cycle(){
  for(int start = 1; start <= n; start++){
    int pos = start;
    for(int count = 0; count < n; count++)
      pos = on_right[partner[pos]];
    if(pos != 0) return true;
  }
  return false;
}

int solve(){
  int unpaired;
  for(unpaired = 1; unpaired <= n; unpaired++)
    if(partner[unpaired] == 0)
      break;
  if(unpaired == n+1){
    if(cycle()) return 1;
    else return 0;
  }
  int total = 0;
  for(int nt = unpaired+1; nt <= n; nt++){
    if(partner[nt] == 0){
      partner[unpaired] = nt;
      partner[nt] = unpaired;
      total += solve();
      partner[nt] = partner[unpaired] = 0;
    }
  }
  return total;
}

int main(){
  ifstream fin("wormhole.in");
  fin >> n;
  for(int i = 1; i <= n; i++) fin >> X[i] >> Y[i];
  fin.close();
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(X[j] > X[i] && Y[i] == Y[j])
	if(on_right[i] == 0 || X[on_right[i]]-X[i] > X[j]-X[i])
	  on_right[i] = j;
  ofstream fout("wormhole.out");
  fout << solve() << endl;
}
