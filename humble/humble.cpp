/*
ID: mathgen2
PROG: humble
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

long long pfact[101];
int INDEX[101];
vector<long long> humble;

int main() {
  ifstream fin("humble.in");
  ofstream fout("humble.out");

  int k, n;
  fin >> k >> n;
  for(int i = 0; i < n; i++){
    fin >> pfact[i];
  }
  memset(INDEX, sizeof(INDEX), 0);
  humble.push_back(1);
  while(humble.size() <= n){
    long long mNum = pfact[0]*humble[INDEX[0]];
    for(int i = 1; i < k; i++){
      mNum = min(mNum, pfact[i]*humble[INDEX[i]]);
    }
    for(int i = 0; i < k; i++){
      if(mNum == pfact[i]*humble[INDEX[i]])
	INDEX[i]++;
    }
    humble.push_back(mNum);
  }

  fout << humble[humble.size()-1] << endl;
}
