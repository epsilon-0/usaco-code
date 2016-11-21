/*
ID: mathgen2
PROG: msquare
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 87654325;

map<int, int> parent;
map<int, char> mPrev;

int getDigit(int n, int d){
  return ((n/((int)pow(10, d)))%10);
}

int doB(int n){
  return 10000000*getDigit(n, 4)+
         1000000*getDigit(n, 7)+
         100000*getDigit(n, 6)+
         10000*getDigit(n, 5)+
         1000*getDigit(n, 2)+
         100*getDigit(n, 1)+
         10*getDigit(n, 0)+
         getDigit(n, 3);
}

int doA(int n){
  return 10000000*getDigit(n, 0)+
         1000000*getDigit(n, 1)+
         100000*getDigit(n, 2)+
         10000*getDigit(n, 3)+
         1000*getDigit(n, 4)+
         100*getDigit(n, 5)+
         10*getDigit(n, 6)+
         getDigit(n, 7);
}

int doC(int n){
  return 10000000*getDigit(n, 7)+
         1000000*getDigit(n, 1)+
         100000*getDigit(n, 6)+
         10000*getDigit(n, 4)+
         1000*getDigit(n, 3)+
         100*getDigit(n, 5)+
         10*getDigit(n, 2)+
         getDigit(n, 0);
}

void bfs(){
  queue<int> que;
  que.push(12345678);
  parent[12345678]=0;
  int n, v;
  while(!que.empty()){
    n = que.front(); que.pop();
    v = doA(n);
    if(parent.count(v) == 0){
      parent[v] = n;
      mPrev[v] = 'A';
      que.push(v);
    }
    v = doB(n);
    if(parent.count(v) == 0){
      parent[v] = n;
      mPrev[v] = 'B';
      que.push(v);
    }
    v = doC(n);
    if(parent.count(v) == 0){
      parent[v] = n;
      mPrev[v] = 'C';
      que.push(v);
    }
  }
}

int main() {
  ifstream fin("msquare.in");
  ofstream fout("msquare.out");
  int sink = 0;
  for(int i = 0; i < 8; i++){
    int d;
    fin >> d;
    sink = sink*10 + d;
  }
  bfs();
  string path;
  while(sink!=12345678){
    path+=mPrev[sink];
    sink=parent[sink];
  }
  reverse(path.begin(), path.end());
  fout << path.length() << endl;
  fout << path << endl;
  cout << path << endl;
}
