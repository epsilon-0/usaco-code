/*
ID: mathgen2
PROG: holstein
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool check(int* tot, int* needed, const int &v){
  for(int i = 0; i < v; i++)
    if(tot[i] < needed[i])
      return false;
  return true;
}

int numbits(int n){
  int res;
  for(res = 0; n; res++)
    n &= n-1;
  return res;
}

int reverseBits(int num){
  int NO_OF_BITS = sizeof(num) * 8;
  int reverse_num = 0;
  int i;
  for (i = 0; i < NO_OF_BITS; i++){
    if((num & (1 << i)))
      reverse_num |= 1 << ((NO_OF_BITS - 1) - i);  
  }
  return reverse_num;
}

int mmin(int x, int y){
  if(numbits(x) < numbits(y))
    return x;
  if(numbits(y) < numbits(x))
    return y;
  return reverseBits(min(reverseBits(x), reverseBits(y)));
}

int main(){
  ifstream fin("holstein.in");
  ofstream fout("holstein.out");
  int v;
  fin >> v;
  int needed[v];
  for(int i = 0; i < v; i++) 
    fin >> needed[i];

  int g;
  fin >> g;
  int contains[g][v];
  for(int i = 0; i < g; i++)
    for(int j = 0; j < v; j++)
      fin >> contains[i][j];
  
  int mn = (1<<27)-1;
  int tot[v];
  for(int bmap = 0; bmap <= (1<<g); bmap++){
    for(int i = 0; i < v; i++) tot[i] = 0;
    for(int i = 0; i < g; i++){
      if(bmap&(1<<i)){
	for(int j = 0; j < v; j++)
	  tot[j] += contains[i][j];
      }
    }
    if(check(tot, needed, v)){
      mn = mmin(bmap, mn);
    }
  }
  for(int i = 0; i < v; i++) tot[i] = 0;
  for(int i = 0; i < g; i++)
    if(mn&(1<<i)){
      for(int j = 0; j < v; j++)
	tot[j] += contains[i][j];
    }
  for(int i = 0; i < v; i++)
    cout << tot[i] << " " << needed[i] << endl;
  fout << numbits(mn);
  for(int i = 0; i < g; i++)
    if(mn&(1<<i))
      fout << " " << i+1;
  fout << endl;
}
