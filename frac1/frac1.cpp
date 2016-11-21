/*
ID: mathgen2
PROG: frac1
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int mgcd(int a, int b){
  int c;
  while(a != 0){
    c = a;
    a = b%a;
    b = c;
  }
  return b;
}

bool compare(pair<int, int> f1, pair<int, int> f2){
  return f1.first*f2.second < f1.second*f2.first;
}

int main(){
  ifstream fin("frac1.in");
  ofstream fout("frac1.out");
  int n;
  fin >> n;
  n++;
  vector<pair<int, int> > fracs;
  fracs.push_back(make_pair(1, 1));
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++){
      int mg = mgcd(i, j);
      cout << i << " " << j << " " << mg << endl;
      fracs.push_back(make_pair(i/mg, j/mg));
    }
  sort(fracs.begin(), fracs.end(), compare);
  for(int i = 0; i < fracs.size(); i++){
    if(i < fracs.size()-1 && fracs[i] == fracs[i+1]) continue;
    fout << fracs[i].first << "/" << fracs[i].second << endl;
  }
}
