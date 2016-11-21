/*
ID: mathgen2
PROG: gift1
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

map<string, int> orig, after;
string names[15];

int main(){
  ifstream fin("gift1.in");
  ofstream fout("gift1.out");
  int num;
  fin >> num;
  string name;
  for(int i = 0; i < num; i++){
    fin >> name;
    names[i] = name;
    orig[name] = 0;
    after[name] = 0;
  }
  int tot, friends;
  for(int i = 0; i < num; i++){
    fin >> name >> tot >> friends;
    if(friends == 0){
      after[name] += tot;
      continue;
    }
    after[name] += (tot%friends)-tot;
    for(int j = 0; j < friends; j++){
      fin >> name;
      after[name] += tot/friends;
    }
  }
  for(int i = 0; i < num; i++) fout << names[i] << " " << after[names[i]] << endl;
}
