/*
ID: mathgen2
PROG: transform
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

vector<vector<char> > rotate(vector<vector<char> > grid){
  vector<vector<char> > answer(grid[0].size(), vector<char>(grid.size(), '.'));
  int n = grid.size();
  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[0].size(); j++){
      answer[j][n-i-1] = grid[i][j];
    }
  }
  return answer;
}

vector<vector<char> > reflect(vector<vector<char> > grid){
  vector<vector<char> > answer;
  for(int i = 0; i < grid.size(); i++){
    vector<char> temp = grid[i];
    reverse(temp.begin(), temp.end());
    answer.push_back(temp);
  }
  return answer;
}

void print_grid(vector<vector<char> > grid){
  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[i].size(); j++){
      cout << grid[i][j];
    }
  }cout << endl;
}

int main(){
  ifstream fin("transform.in");
  ofstream fout("transform.out");
  int n;
  fin >> n;
  vector<vector<char> > orig(n, vector<char>(n, '.'));
  vector<vector<char> > after(n, vector<char>(n, '.'));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      fin >> orig[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      fin >> after[i][j];
    }
  }
  if(after == rotate(orig)){
    fout << 1;
  }
  else if(after == rotate(rotate(orig))){
    fout << 2;
  }
  else if(after == rotate(rotate(rotate(orig)))){
    fout << 3;
  }
  else if(after == reflect(orig)){
    fout << 4;
  }
  else if((after == rotate(reflect(orig))) || (after == rotate(rotate(reflect(orig)))) || (after == rotate(rotate(rotate(reflect(orig)))))){
    fout << 5;
  }
  else if(after == orig){
    cout << 6;
  }
  else{
    fout << 7;
  }
  fout << endl;
}
