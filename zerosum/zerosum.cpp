/*
ID: mathgen2
PROG: zerosum
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

string choiceN(int k, int n){
  k = k / (pow(3, n));
  string ans;
  if(k%3 == 0){
    ans = "";
  }
  else if(k%3 ==1){
    ans = " ";
  }
  else{
    ans = " -";
  }
  return ans;
}

string mChoiceN(int k, int n){
  k = k / (pow(3, n));
  string ans;
  if(k%3 == 0){
    ans = " ";
  }
  else if(k%3 ==1){
    ans = "+";
  }
  else{
    ans = "-";
  }
  return ans;
}

int evalExp(string expr){
  istringstream inp(expr);
  int num;
  int val = 0;
  while(inp >> num){
    val += num;
  }
  return val;
}

void bruteForce(int n){
  int choices = pow(3, n-1);
  vector<string> exprs;
  for(int i = 0; i < choices; i++){
    string expr = "1";
    for(int j = 2; j <= n; j++){
      expr += choiceN(i, j-2);
      expr += j + '0';
    }
    if(evalExp(expr) == 0){
      string mExpr = "1";
      for(int j = 2; j <= n; j++){
        mExpr += mChoiceN(i, j-2);
        mExpr += j + '0';
      }
      exprs.push_back(mExpr);
    }
  }
  sort(exprs.begin(), exprs.end());
  for(string expr : exprs){
    fout << expr << endl;
  }
}

int main() {
  int n;
  fin >> n;
  bruteForce(n);
}
