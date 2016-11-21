/*
ID: mathgen2
PROG: cowtour
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

const double INF = 999999;

bool graph[151][151];
double pasture[151][2];
int pastures;
double dist[151][151];
double mDist[151];
double tDist[151];

int main() {
  ifstream fin("cowtour.in");
  FILE *fout;
  fout = fopen("cowtour.out", "w");

  for(int i = 0; i < 150; i++){
    mDist[i] = INF;
    for(int j = 0; j < 150; j++){
      dist[i][j] = INF;
    }
  }

  fin >> pastures;

  for(int i = 0; i < pastures; i++){
    fin >> pasture[i][0] >> pasture[i][1];
  }

  char connected;
  for(int i = 0; i < pastures; i++){
    for(int j = 0; j < pastures; j++){
      fin >> connected;
      graph[i][j] = (connected == '1');
    }
  }
  
  // FLOYD WARSHALL
  for(int i = 0; i < pastures; i++){
    dist[i][i] = 0;
    for(int j = 0; j < pastures; j++){
      if(graph[i][j]){
	dist[i][j] = sqrt(pow(pasture[i][0]-pasture[j][0], 2) + 
			  pow(pasture[i][1]-pasture[j][1], 2));
      }
    }
  }

  for(int k = 0; k < pastures; k++){
    for(int i = 0; i < pastures; i++){
      for(int j = 0; j < pastures; j++){
      	dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  double mMax;
  for(int i = 0; i < pastures; i++){
    mMax = -1;
    for(int j = 0; j < pastures; j++){
      if(dist[i][j] != INF){
	mMax = max(mMax, dist[i][j]);
      }
    }
    mDist[i] = mMax;
  }

  double mDiam = INF;
  double fDiam = *max_element(mDist, mDist+pastures);
  for(int i = 0; i < pastures; i++){
    for(int j = i+1; j < pastures; j++){
      if(dist[i][j] != INF){
	continue;
      }
      double cDist = sqrt(pow(pasture[i][0]-pasture[j][0], 2) + 
			  pow(pasture[i][1]-pasture[j][1], 2));
      
      mDiam = min(mDiam, max(fDiam, mDist[i] + mDist[j] + cDist));
    }
  }
  fprintf(fout, "%.6f\n", mDiam);
}
