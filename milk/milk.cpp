/*
ID: mathgen2
PROG: milk
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

pair<int, int> farmers[5003];

int main(){
  ifstream fin("milk.in");
  ofstream fout("milk.out");
  int want, n, price, tot;
  fin >> want >> n;
  for(int i = 0; i < n; i++){
    fin >> price >> tot;
    farmers[i] = make_pair(price, tot);
  }
  sort(farmers, farmers+n);
  tot = 0;
  for(int i = 0; i < n && want > 0; i++){
    int take = min(want, farmers[i].second);
    want -= take;
    tot +=  farmers[i].first * take;
  }
  fout << tot << endl;
}
