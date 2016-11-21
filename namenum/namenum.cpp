/*
ID: mathgen2
PROG: namenum
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int nums[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 1, 7, 7, 8, 8, 8, 9, 9, 9, 1};

long long decrypt(string name){
  long long dec = 0;
  for(int i = 0; i < name.size(); i++){
    dec *= 10;
    dec += nums[name[i]-'A'];
  }
  return dec;
}

vector<string> valid;

int main(){
  ifstream fin("namenum.in");
  ifstream din("dict.txt");
  ofstream fout("namenum.out");
  long long ans;
  fin >> ans;
  string name;
  while(din >> name){
    if(ans == decrypt(name)) valid.push_back(name);
  }
  sort(valid.begin(), valid.end());
  for(int i = 0; i < valid.size(); i++) fout << valid[i] << endl;
  if(valid.size() == 0) fout << "NONE\n";
}
