/*
ID: mathgen2
PROG: contact
LANG: C++11
*/

#include <bits/stdc++.h>

#define kBit(num, k) (num >> k)&1

using namespace std;

string emm = "";

string bitToString(int num, int lgt){
  string ans = "";
  for(int i = 0; i < lgt; i++, num >>=1){
    ans += num&1 ? '1' : '0';
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int stringToBit(string str){
  int ans = 0;
  //  reverse(str.begin(), str.end());
  for(int i = 0; i < str.size(); i++){
    ans *= 2;
    ans += str[i] - '0';
  }
  return ans;
}

int freq[15][10000];
vector<tuple<int, int, int> > nums;

int main() {
  ifstream fin("contact.in");
  ofstream fout("contact.out");
  memset(freq, sizeof(freq), 0);
  int a, b, n;
  fin >> a >> b >> n;
  //cout << a << " " << b << " " << n << endl;
  string part;
  while(fin >> part){
    emm += part;
  }
  //cout << emm << endl;

  int stt, MOD = pow(2, a-1);
  for(int i = a; i <= b; i++){
    MOD *= 2;
    if(emm.length() < i) continue;
    stt = stringToBit(emm.substr(0, i));
    freq[i][stt]++;
    for(int pos = i; pos < emm.length(); pos++){
      stt = (stt*2 + ((int)emm[pos]) - 48) % MOD;
      freq[i][stt]++;
    }
  }

  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 10000; j++){
      if(freq[i][j] == 0) continue;
      nums.push_back(make_tuple(freq[i][j], -1*i, -1*j));
    }
  }
  sort(nums.begin(), nums.end());
  //reverse(nums.begin(), nums.end());
  int count = 0, ff, pos;
  while(count < n && nums.size() > 0){
    ff = get<0>(nums[nums.size()-1]);
    fout << ff << endl;
    fout << bitToString(-1*get<2>(nums[nums.size()-1]), -1*get<1>(nums[nums.size()-1]));
    nums.pop_back();
    int mCount = 1;
    while(get<0>(nums[nums.size()-1]) == ff){
      if(mCount == 0){
	fout << endl;
      }
      else{
	fout << " ";
      }
      fout << bitToString(-1*get<2>(nums[nums.size()-1]), -1*get<1>(nums[nums.size()-1]));
      nums.pop_back();
      mCount = (mCount + 1)%6;
    }
    fout << endl;
    count++;
  }
}
