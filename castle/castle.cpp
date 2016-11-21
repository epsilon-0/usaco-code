/*
ID: mathgen2
PROG: castle
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 51;

int m, n, comp;
int grid[MAXN][MAXN];
int visited[MAXN][MAXN];
int scomp[MAXN][MAXN];
int ncomp[MAXN][MAXN];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int getDFS(int x, int y){
  if(x < 0 || x >= m || y < 0 || y >= n) return 0;
  if(visited[x][y] == 1) return 0;
  visited[x][y] = 1;
  int ans = 1;
  for(int p = 0; p < 4; p++)
    if((grid[x][y] & 1<<p) == 0)
      ans += getDFS(x+dx[p], y+dy[p]);
  return ans;
}

void setDFS(int x, int y, int s){
  if(x < 0 || x >= m || y < 0 || y >= n) return;
  if(visited[x][y] == 2) return;
  visited[x][y] = 2;
  scomp[x][y] = s;
  ncomp[x][y] = comp;
  for(int p = 0; p < 4; p++)
    if((grid[x][y] & 1<<p) == 0)
      setDFS(x+dx[p], y+dy[p], s);
  return;
}

int main(){
  ifstream fin("castle.in");
  ofstream fout("castle.out");
  fin >> n >> m;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      fin >> grid[i][j];
  int msize = -1;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      if(visited[i][j] == 0){
	comp++;
	int sz = getDFS(i, j);
	msize = max(sz, msize);
	setDFS(i, j, sz);
      }
  fout << comp << endl;
  fout << msize << endl;
  msize = -1;
  int mx, my;
  char tt;
  // most to west
  for(int j = 0; j < n; j++){
    // first check north walls
    for(int i = m-1; i > 0; i--){
      if((grid[i][j] & 1<<1) != 0 && ncomp[i][j] != ncomp[i-1][j] && scomp[i][j]+scomp[i-1][j] > msize){
	msize = scomp[i][j]+scomp[i-1][j];
	mx = i;
	my = j;
	tt = 'N';
      }
    }
    if(j<n-1){
      for(int i = m-1; i >= 0; i--){
	if((grid[i][j] & 1<<2) != 0 && ncomp[i][j] != ncomp[i][j+1] && scomp[i][j]+scomp[i][j+1] > msize){
	  msize = scomp[i][j]+scomp[i][j+1];
	  mx = i;
	  my = j;
	  tt = 'E';
	}
      }
    }
  }
  fout << msize << endl;
  fout << mx+1 << " " << my+1 << " " << tt << endl;
}
