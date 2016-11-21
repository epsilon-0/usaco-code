/*
ID: mathgen2
PROG: sprime
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5+1e5;

vector<int> prime;
bool iscomp[MAXN] = {false};

void init(){
  iscomp[0] = iscomp[1] = true;
  for(int i = 2; i < 320; i++)
    if(!iscomp[i])
      for(int j = i*i; j < 1e5; j += i)
	iscomp[j] = true;
  for(int i = 2; i < 1e5; i++)
    if(!iscomp[i])
      prime.push_back(i);
}

bool isprime(int n){
  for(int i = 0; i < prime.size() && prime[i] <= pow(n, 0.5); i++)
    if(n%prime[i] == 0)
      return false;
  return true;
}

set<int> sprime;

void dfs(int num, int depth, int maxdepth){
  if(depth == maxdepth)
    sprime.insert(num);
  else{
    int tnum;
    for(int i = 1; i <= 9; i += 2){
      tnum = num*10 + i;
      if(isprime(tnum))
	dfs(tnum, depth+1, maxdepth);
    }
  }
}

int main(){
  ifstream fin("sprime.in");
  ofstream fout("sprime.out");
  int n;
  fin >> n;
  init();
  dfs(2, 1, n);
  dfs(3, 1, n);
  dfs(5, 1, n);
  dfs(7, 1, n);
  for(int i : sprime)
    fout << i << endl;
}
