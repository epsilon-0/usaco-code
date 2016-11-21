/*
ID: mathgen2
PROG: crypt1
LANG: C++11
*/
#include <bits/stdc++.h>

#define FOR(i, val) for(int kkk = 0; kkk < val.size(); i = val[++kkk])

using namespace std;

vector<int> num;

bool inside(int n){
  for(int i : num)
    if(i == n)
      return true;
  return false;
}

bool val(int n){
  while(n>0){
    int d = n%10;
    n /= 10;
    if(!inside(d))
      return false;
  }
  return true;
}

int lgt(int n){
  return (n>0)?1+lgt(n/10):0;
}

int main(){
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");
  int n;
  fin >> n;
  for(int i = 0; i < n; i++){
    int temp;
    fin >> temp;
    num.push_back(temp);
  }
  int cnt = 0;
  for(int A : num)
    for(int B : num)
      for(int C : num)
	for(int D : num)
	  for(int E : num){
	    int x = 100*A + 10*B + C;
	    int y = 10*D + E;
	    if( val(x*y) && val(x*D) && val(x*E) && lgt(x*y)==4 && lgt(x*D)==3 && lgt(x*E)==3)
	      cnt++;
	  }
  cout << cnt << endl;
  fout << cnt << endl;
}
