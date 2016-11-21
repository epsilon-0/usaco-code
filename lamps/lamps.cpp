/*
ID: mathgen2
PROG: lamps
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int lamp[101] = {0};
int darude[101] = {0};

bool is_consistent(int *given, int *needed, int v){
  for(int i = 0; i < v; i++)
    if(needed[i] != -1 && needed[i] != given[i])
      return false;
  return true;
}

int steps(int n){
  int res = 0;
  while(n>0){
    if(n&1)
      res++;
    n >>= 1;
  }
  return res;
}

void flip_ap(int a, int d, int *arr, int n){
  for(int i = a; i < n; i += d)
    arr[i] = 1-arr[i];
}

string putin(int *arr, int n, set<string> &sol){
  string res = "";
  for(int i = 0; i < n; i++){
    if(arr[i] == 0)
      res += "0";
    else
      res += "1";
  }
  sol.insert(res);
  return res;
}

int main(){
  ifstream fin("lamps.in");
  ofstream fout("lamps.out");

  memset(lamp, -1, sizeof(lamp));

  int n, c;
  fin >> n >> c;
  int v;
  while(1){
    fin >> v;
    if(v == -1) break;
    lamp[v-1] = 1;
  }
  while(1){
    fin >> v;
    if(v == -1) break;
    lamp[v-1] = 0;
  }

  set<string> sol;
  
  for(int i = 0; i < 16; i++){
    for(int i = 0; i < n; i++) darude[i] = 1;
    if(i&1) flip_ap(0, 1, darude, n);
    if(i&2) flip_ap(0, 2, darude, n);
    if(i&4) flip_ap(1, 2, darude, n);
    if(i&8) flip_ap(0, 3, darude, n);
    for(int i = 0; i  < n; i++) cout << darude[i]; cout << " " << steps(i) << endl;
    if(steps(i) + 2 <= c || steps(i) == c)
      if(is_consistent(darude, lamp, n))
	cout << i << " " << steps(i) << " " << putin(darude, n, sol) << endl;
  }
  for(string dr : sol){
    cout << dr << endl;
    fout << dr << endl;
  }
  if(sol.empty())
    fout << "IMPOSSIBLE\n";
}
