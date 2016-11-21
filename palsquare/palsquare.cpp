/*
ID: mathgen2
PROG: palsquare
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
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");
  int base;
  fin >> base;
  for(int i = 1; i <= 300; i++){
    if(ispalin(tobase(i*i,base))){
      string temp = tobase(i, base);
      reverse(temp.begin(), temp.end());
      fout << temp << " " << tobase(i*i, base) << endl;
    }
  }
}
