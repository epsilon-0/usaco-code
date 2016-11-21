/*
ID: mathgen2
PROG: ride
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
  ifstream fin("ride.in");
  ofstream fout("ride.out");
  char c;
  int res1 = 1;
  int res2 = 1;
  while(fin.get(c)){
    if(c == '\n') break;
    res1 *= (c-'A')+1;
    res1 %= 47;
  }
  while(fin.get(c)){
    if(c == '\n') break;
    res2 *= (c-'A')+1;
    res2 %= 47;
  }
  if(res1 == res2) fout << "GO\n";
  else fout << "STAY\n";
}
