/*
ID: mathgen2
PROG: concom
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int triples;
int controlPercent[101][101];
int control[101];
int visited[101];

void dfs(int vertex){
  if(visited[vertex] == 1){
    return;
  }
  //cout << "movein to " << vertex << endl;
  visited[vertex] = 1;
  //cout << "control is ";
  for(int i = 1; i < 101; i++){
    //cout << control[i] << " ";
  }
  //cout << endl;
  for(int i = 1; i < 101; i++){
    control[i] += controlPercent[vertex][i];
    //cout << i << " " << control[i] << endl;
    if(control[i] > 50){
      //cout << i << "'th control is " << control[i] << endl;
      if(visited[i] == 0){
        dfs(i);
      }
    }
  }
  return;
}

int main() {
  ifstream fin("concom.in");
  ofstream fout("concom.out");

  fin >> triples;

  int c1, c2, p;
  for(int i = 0; i < triples; i++){
    fin >> c1 >> c2 >> p;
    controlPercent[c1][c2] = p;
  }

  for(int i = 1; i < 101; i++){
    for(int k = 0; k < 101; k++){
      control[k] = 0;
      visited[k] = 0;
    }
    //cout << "starting dfs at " << i << endl;
    ////cout << visited[i] << endl;
    dfs(i);
    for(int j = 1; j < 101; j++){
      if(control[j] > 50 && i != j){
        fout << i << " " << j << endl;
      }
    }
  }
}
