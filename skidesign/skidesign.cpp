/*
ID: mathgen2
PROG: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1003;

int n, hill[MAXN];


int main(){
  ifstream fin("skidesign.in");
  fin >> n;
  for(int i = 0; i < n; i++) fin >> hill[i];
  fin.close();
  ofstream fout("skidesign.out");
  int tot, mcost;
  mcost = 123456789;
  for(int i = 0; i < 83; i++){
    tot = 0;
    for(int j = 0; j < n; j++){
      if(hill[j] < i){
	tot += pow(i-hill[j], 2);
      }
      if(hill[j] > i+17){
	tot += pow(hill[j]-i-17, 2);
      }
    }
    mcost = min(tot, mcost);
  }
  fout << mcost << endl;
}
