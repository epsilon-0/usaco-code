/*
ID: mathgen2
PROG: prefix
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

bool isPrefixAt(string& word, int mPos, string& prefix){
  if(prefix.size() > word.size() - mPos){
    return false;
  }
  for(int i = 0; i < prefix.size(); i++){
    if(prefix[i] != word[mPos + i]){
      return false;
    }
  }
  return true;
}

string con[300];
int DP[200010];
string word;

int main() {
  ifstream fin("prefix.in");
  ofstream fout("prefix.out");

  int tWords = 0;
  cout << "wtf\n";

  while(1) {
    string cc;
    fin >> cc;
    if(cc != ".") {
      con[tWords++] = cc;
    }
    else{
      break;
    }
  }
  cout << tWords << endl;
  cout << "wtf\n";

  string mWord;
  while(fin >> mWord){
    word += mWord;
  }
  cout << "wtf\n";
  for(int pos = word.size(); pos > -1; pos--){
    for(int w = 0; w < tWords; w++){
      if(isPrefixAt(word, pos, con[w])){
        int temp = con[w].size() + DP[pos+con[w].size()];
        DP[pos] = max(DP[pos], temp);
      }
    }
  }

  fout << DP[0] << endl;

}
