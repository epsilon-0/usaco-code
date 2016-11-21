/*
ID: mathgen2
PROG: milk2
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> times[5005];
int ntimes[5005][2];

int main(){
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");
  int cows, st, nd;
  fin >> cows;
  for(int i = 0; i < cows; i++){
    fin >> st >> nd;
    times[i] = make_pair(st, nd);
  }
  sort(times, times+cows);
  ntimes[0][0] = times[0].first;
  ntimes[0][1] = times[0].second;
  int pos = 1;
  for(int i = 1; i < cows; i++){
    st = times[i].first;
    nd = times[i].second;
    if(st <= ntimes[pos-1][1]){
      ntimes[pos-1][1] = max(nd, ntimes[pos-1][1]);
    }
    else{
      ntimes[pos][0] = st;
      ntimes[pos][1] = nd;
      pos++;
    }
  }
  //  for(int i = 0; i < pos; i++) cout << ntimes[i][0] << " " << ntimes[i][1] << endl;
  int maxMilkTime = 0;
  int maxNoMilk = 0;
  for(int i = 0; i < pos; i++){
    maxMilkTime = max(maxMilkTime, ntimes[i][1] - ntimes[i][0]);
  }
  for(int i = 1; i < pos; i++){
    maxNoMilk = max(maxNoMilk, ntimes[i][0] - ntimes[i-1][1]);
  }
  fout << maxMilkTime << " " << maxNoMilk << endl;
}
