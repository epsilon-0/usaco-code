/*
ID: mathgen2
PROG: dualpal
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

// is reverse //careful
string tobase(int num, int base){
  string ans = "";
  while(num > 0){
    ans += digit[num%base];
    num /= base;
  }
  return ans;
}

bool ispalin(string str){
  int n = str.size(); 
  for(int i = 0; i < n; i++){
    if(str[i] != str[n-1-i])
      return false;
  }
  return true;
}

int main(){
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");
  int n, s;
  fin >> n >> s;
  int num = s+1;
  int tot = 0;
  while(tot < n){
    int count = 0;
    for(int base = 2; base <= 10; base++){
      if(ispalin(tobase(num, base))) count++;
      if(count > 1){
	fout << num << endl;
	tot++;
	break;
      }
    }
    num++;
  }
}
