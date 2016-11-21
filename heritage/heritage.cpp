/*
ID: mathgen2
PROG: heritage
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

string postord(string inord, string preord){
	if(inord.size()<=1)
		return inord;
	char root = preord[0];
	int pos = inord.find(root);
	string leftinord = inord.substr(0, pos);
	string rightinord = inord.substr(pos+1, inord.size());
	string leftpreord = "", rightpreord = "";
	for(int i = 1; i < preord.size(); i++){
		if(leftinord.find(preord[i])!=string::npos)
			leftpreord += preord[i];
		else
			rightpreord += preord[i];
	}

	return postord(leftinord, leftpreord)+postord(rightinord, rightpreord)+root;
}

int main() {
  ifstream fin("heritage.in");
  ofstream fout("heritage.out");

  string inord, preord;
  fin >> inord >> preord;

  fout << postord(inord, preord) << endl;

}
