/*
ID: mathgen2
PROG: pprime
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5+1e5;

vector<int> prime;
bool iscomp[MAXN] = {false};

void init(){
  iscomp[0] = iscomp[1] = true;
  for(int i = 2; i < 320; i++)
    if(!iscomp[i])
      for(int j = i*i; j < 1e5; j += i)
	iscomp[j] = true;
  for(int i = 2; i < 1e5; i++)
    if(!iscomp[i])
      prime.push_back(i);
}

bool isprime(int n){
  for(int i = 0; i < prime.size() && prime[i] <= pow(n, 0.5); i++)
    if(n%prime[i] == 0)
      return false;
  return true;
}

vector <int> palinList;
 
void oneDigit(){
  for(int i = 1; i <= 9; i += 2)
    palinList.push_back(i);
}
 
void twoDigit(){
  for(int i = 1; i <= 9; i += 2)
    palinList.push_back(i * 10 + i);
}
 
void threeDigit(){
  for(int i = 1; i <= 9; i += 2)
    for(int j = 0; j <= 9; j++)
      palinList.push_back(100 * i + 10 * j + i);
}
 
void fourDigit(){
  for(int i = 1; i <= 9; i += 2)
    for(int j = 0; j <= 9; j++)
      palinList.push_back(1000 * i + 100 * j + 10 * j + i);
}
 
void fiveDigit(){
  for(int i = 1; i <= 9; i += 2)
    for(int j = 0; j <= 9; j++)
      for(int k = 0; k <= 9; k++)
	palinList.push_back(10000 * i + 1000 * j + 100 * k + 10 * j + i);
}
 
void sixDigit(){
  for(int i = 1; i <= 9; i += 2)
    for(int j = 0; j <= 9; j++)
      for(int k = 0; k <= 9; k++)
	palinList.push_back(100000 * i + 10000 * j + 1000 * k + 100 * k + 10 * j + i);
}
 
void sevenDigit(){
  for(int i = 1; i <= 9; i += 2)
    for(int j = 0; j <= 9; j++)
      for(int k = 0; k <= 9; k++)
	for(int l = 0; l <= 9; l++)
	  palinList.push_back(1000000 * i + 100000 * j + 10000 * k + 1000 * l + 100 * k + 10 * j + i);
}

 
void eightDigit(){
  for(int i = 1; i <= 9; i += 2)
    for(int j = 0; j <= 9; j++)
      for(int k = 0; k <= 9; k++)
	for(int l = 0; l <= 9; l++)
	  palinList.push_back (10000000 * i + 1000000 * j + 100000 * k + 10000 * l + 1000 * l + 100 * k + 10 * j + i);
}
 
void generatePalindrome(){
    oneDigit();
    twoDigit();
    threeDigit();
    fourDigit();
    fiveDigit();
    sixDigit();
    sevenDigit();
    eightDigit();
}


int main(){
  ifstream fin("pprime.in");
  ofstream fout("pprime.out");

  init();
  generatePalindrome();
  int a, b;
  fin >> a >> b;
  for(vector<int>::iterator it = lower_bound(palinList.begin(), palinList.end(), a); it != palinList.end() && *it <= b; it++){
    if(isprime(*it))
      fout << *it << endl;
  }
}
