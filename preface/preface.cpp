/*
ID: mathgen2
PROG: preface
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

string int_to_roman(int n, map<int, string>& st){
  string res = "";
  for(auto darude = st.rbegin(); darude != st.rend(); darude++){
    while(darude->first <= n){
      res += darude->second;
      n -= darude->first;
    }
  }
  return res;
}

int main(){
  ifstream fin("preface.in");
  ofstream fout("preface.out");

  int n;
  fin >> n;
  map<int, string> st;
  st[1] = "I"; st[10] = "X"; st[100] = "C"; st[1000] = "M";
  st[4] = "IV"; st[40] = "XL"; st[400] = "CD";
  st[9] = "IX"; st[90] = "XC"; st[900] = "CM";
  st[5] = "V"; st[50] = "L"; st[500] = "D";
  map<int, char> stt;
  stt[1] = 'I'; stt[10] = 'X'; stt[100] = 'C'; stt[1000] = 'M';
  stt[5] = 'V'; stt[50] = 'L'; stt[500] = 'D';
  map<char, int> ans;
  for(int i = 1; i <= n; i++){
    string roman = int_to_roman(i, st);
    cout << roman << endl;
    for(int j = 0; j < roman.size(); j++)
      ans[roman[j]]++;
  }
  for(auto darude : stt){
    if(darude.first > n) break;
    fout << darude.second << " " << ans[darude.second] << endl;    
  }
}
