/*
ID: mathgen2
PROG: ratios
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int goal[3];
int mix[3][3];

int isMix(int a, int b, int c){
  int q;
  if(goal[0] != 0)
    q = a/goal[0];
  else if(goal[1] != 0)
    q = b/goal[1];
  else
    q = c/goal[2];
  if ((a == q*goal[0]) && (b == q*goal[1]) && (c == q*goal[2]))
    return q;
  else 
    return -5;
}

int main() {
  ifstream fin("ratios.in");
  ofstream fout("ratios.out");
  for(int i = 0; i < 3; i++)
    fin >> goal[i];
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      fin >> mix[i][j];

  int mMin = 50000, minX, minY, minZ, minW;
  int x, y, z;
  for(int i = 0; i < 104; i++){
    for(int j = 0; j < 104; j++){
      for(int k = 0; k < 104; k++){
	x = i*mix[0][0] + j*mix[1][0] + k*mix[2][0];
	y = i*mix[0][1] + j*mix[1][1] + k*mix[2][1];
	z = i*mix[0][2] + j*mix[1][2] + k*mix[2][2];
	int poss = isMix(x, y, z);
	if(poss != -5 && (i+j+k > 0) && mMin > i+j+k){
	  mMin = i + j + k;
	  minX = i; minY = j; minZ = k; minW = poss;
	}
      }
    }
  }
  if(mMin == 50000)
    fout << "NONE\n";
  else
    fout << minX << " " << minY << " " << minZ << " " << minW << endl;
}
