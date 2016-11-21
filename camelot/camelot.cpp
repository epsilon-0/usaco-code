/*
ID: mathgen2
PROG: camelot
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int dx[8] = {1,1,-1,-1,2,2,-2,-2};
int dy[8] = {2,-2,2,-2,1,-1,1,-1};
int kDist[32][32][32][32];
bool visited[32][32][32][32];

void distGraph(int x, int y, int r, int c){
  queue<tuple<int, int, int> > que;
  que.push(make_tuple(x, y, 0));
  while(!que.empty()){
    auto node = que.front(); que.pop();
    auto row = get<0>(node); auto col = get<1>(node); auto d = get<2>(node);
//    cout << row << " " << col << endl;
    if(visited[x][y][row][col])
      continue;
    kDist[x][y][row][col] = d;
    visited[x][y][row][col] = true;
    for(int i = 0; i < 8; i++){
      if(row+dx[i]>=0 && row+dx[i]<r && col+dy[i]>=0 && col+dy[i]<c){
      	que.push(make_tuple(row+dx[i], col+dy[i], d+1));
      }
    }
  }
}

int main() {
  ifstream fin("camelot.in");
  ofstream fout("camelot.out");
  
  int r, c;
  fin >> c >> r;
  vector<pair<int, int> > knight;
  pair<int, int> king;
  char pos;
  int d;
  fin >> pos >> king.second;
  king.first = pos - 'A';
  king.second--;
  while(fin >> pos){
    fin >> d;
    knight.push_back(make_pair(pos-'A', d-1));
  }

  for(int i = 0; i < 32; i++)
  	for(int j = 0; j < 32; j++)
  		for(int k = 0; k < 32; k++)
  			for(int l = 0; l < 32; l++){
  				visited[i][j][k][l] = false;
  				kDist[i][j][k][l] = 100000;
  			}
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++){
      distGraph(i, j, r, c);
  	}
  int mMinDist = 100000000;
  for(int rr = 0 ; rr < r; rr++){
    for(int cc = 0; cc < c; cc++){
      int tDist = 0;
      for(auto kk : knight){
        tDist += kDist[kk.first][kk.second][rr][cc];
      }
      // choose meeting point
      for(int mx = 0; mx < r; mx++){
        for(int my = 0; my < c; my++){
          for(auto kk : knight){
            int mtDist = tDist - kDist[kk.first][kk.second][rr][cc] + max(abs(king.first-mx), abs(king.second-my))
                       + kDist[kk.first][kk.second][mx][my] + kDist[mx][my][rr][cc];
            mMinDist = min(mMinDist, mtDist);
          }
        }
      }
    }
  }
  if(knight.size()==0)
  	mMinDist = 0;
  fout << mMinDist << endl;
}