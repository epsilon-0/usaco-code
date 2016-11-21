/*
ID: mathgen2
PROG: combo
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int N;

#define diff(a,b) min(abs(a-b), N-abs(a-b))
#define isclose(a, b, c, x, y, z) ((diff(a,x)<3) && (diff(b,y)<3) && (diff(c,z)<3))

int main(){
  ifstream fin("combo.in");
  ofstream fout("combo.out");
  fin >> N;
  int a, b, c, x, y, z;
  fin >> a >> b >> c >> x >> y >> z;
  int cnt = 0;
  for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
      for(int k = 1; k <= N; k++)
	if(isclose(i, j, k, a, b, c) || isclose(i, j, k, x, y, z))
	  cnt++;
  cout << cnt << endl;
  fout << cnt << endl;
}
