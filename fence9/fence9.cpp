/*
ID: mathgen2
PROG: fence9
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
  ifstream fin("fence9.in");
  ofstream fout("fence9.out");

  int n, m, p;
  fin >> n >> m >> p;

  double area2 = p*m; // twice the area
  cout << area2 << endl;

  int pA = p + 1; // points on (0,0) to (p,0)
  int pB = gcd(n,m) + 1; // on (0,0) to (n,m)
  int pC = gcd(abs(p-n), m) + 1; // points on third side
  int tPoints = pA + pB + pC - 3; // total points

  int interiorPt = (area2 - tPoints)/2 + 1;

  fout << interiorPt << endl;
}
