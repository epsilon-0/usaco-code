/*
ID: mathgen2
PROG: hamming
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int hamming_distance(int x, int y){
  int dist = 0;
  int val = x^y;
  while(val){
    dist++;
    val &= val - 1;
  }
  return dist;
}

int main(){
  ifstream fin("hamming.in");
  ofstream fout("hamming.out");
  int n, b, d;
  fin >> n >> b >> d;
  int curr = 1;
  int nums[70];
  nums[0] = 0;
  for(int i = 0; i <= (1<<b); i++){
    if(curr == n) break;
    int j;
    for(j = 0; j < curr; j++){
      if(hamming_distance(i, nums[j]) < d) 
	break;
    }
    if(j == curr){
      nums[curr] = i;
      curr++;
    }
  }
  for(int i = 0; i < n; i++){
    fout << nums[i];
    if((i+1)%10 == 0 || i == (n-1)) fout << endl;
    else fout << " ";
  }
}
