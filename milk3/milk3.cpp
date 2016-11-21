/*
ID: mathgen2
PROG: milk3
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool poss[21] = {false};
bool searched[21][21] = {false};

int a, b, c;

void dfs(int x, int y, int z){
  //cout << x << " " << y << " " << z << endl;
  if(searched[x][y]) return;
  searched[x][y] = true;
  if(x == 0) poss[z] = true;
  if (x>0 && y<b) 
    dfs(max(0,x+y-b),min(b,x+y),z);
  if (x>0 && z<c) 
    dfs(max(0,x+z-c),y,min(c,x+z));
  if (y>0 && x<a) 
    dfs(min(a,y+x),max(0,y+x-a),z);
  if (y>0 && z<c) 
    dfs(x,max(0,y+z-c), min(c,y+z));
  if (z>0 && x<a) 
    dfs(min(a,z+x),y,max(0,z+x-a));
  if (z>0 && y<b) 
    dfs(x,min(b,z+y),max(0,z+y-b));
}

int main(){
  ifstream fin("milk3.in");
  ofstream fout("milk3.out");
  fin >> a >> b >> c;
  fin.close();
  dfs(0, 0, c);
  for(int i = 0; i < c; i++)
    if(poss[i]) 
      fout << i << " ";
  fout << c << endl;
}
