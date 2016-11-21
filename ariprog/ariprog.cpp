/*
ID: mathgen2
PROG: ariprog
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> bsqr;
vector<bool> avail;

bool check(int st, int df, int lgt){
  for(int i = st; i < st + df*lgt; i += df){
    if(!avail[i]){
      return false;
    }
  }
  return true;
}

int main(){
  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");
  int n, m;
  fin >> n >> m;
  fin.close();
  bsqr.clear();
  int mdiff = (m*m*2 + 1)/(n-1);
  cout << mdiff << endl;
  avail.clear();
  avail.resize(m*m*2 + 1, false);
  for(int i = 0; i <= m; i++)
    for(int j = 0; j <= m; j++){
      if(!avail[i*i+j*j]){
	cout << i*i+j*j << endl;
	bsqr.push_back(i*i + j*j);
	avail[i*i+j*j] = true;
      }
    }
  sort(bsqr.begin(), bsqr.end());
  bool dn = false;
  for(int d = 1; d <= mdiff; d++){
    int lim = 2*m*m + 1 - (n-1)*d;
    for(int i = 0; i < bsqr.size() && bsqr[i] < lim; i++){
      if(check(bsqr[i], d, n)){
	dn = true;
	fout << bsqr[i] << " " << d << endl;
      }
    }
  }
  if(!dn) fout << "NONE\n";
  fout.close();
}
