/*
ID: mathgen2
PROG: barn1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > cow, temp;

int main(){
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");
  int M, S, C, stall;
  fin >> M >> S >> C;
  cout << C << endl;
  for(int i = 0; i < C; i++){
    fin >> stall;
    cow.push_back(make_pair(stall, stall));
    cout << stall << endl;
  }
  sort(cow.begin(), cow.end());
  while(cow.size() > M){
    int mn = 100000;
    int index = -1;
    for(int i = 1; i < cow.size(); i++){
      if(mn > cow[i].first - cow[i-1].second){
	index = i-1;
	mn = cow[i].first - cow[i-1].second;
      }
    }
    temp.clear(); 
    for(int i = 0; i < cow.size(); i++){
      if(i == index){
	temp.push_back(make_pair(cow[i].first, cow[i+1].second));
	i++;
      }
      else{
	temp.push_back(cow[i]);
      }
    }
    cow = temp;
    cout << cow.size() << endl;
  }
  int tot = 0;
  for(int i = 0; i < cow.size(); i++){
    tot += cow[i].second - cow[i].first;
    cout << cow[i].first << " " << cow[i].second << endl;
  }
  fout << tot+cow.size() << endl;
}
