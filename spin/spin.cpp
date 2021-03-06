/*
ID: mathgen2
PROG: spin
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > wheel[5];
int speed[5];

bool pass(int ray, vector<pair<int, int> > wh){
  for(auto w : wh){
    if(w.first + w.second >= 360){
      if((ray >= w.first) && (ray - w.first <= w.second))
	return true;
      if((ray < w.first) && (ray + 360 - w.first <= w.second))
	return true;
    }
    if((w.first + w.second < 360) && (ray - w.first <= w.second) && (ray >= w.first))
      return true;
  }
  return false;
}

bool passes(){
  for(int ray = 0; ray < 360; ray++){
    bool p = true;
    for(int i = 0; i < 5; i++){
      p = p && pass(ray, wheel[i]);
    }
    if(p)
      return true;
  }
  return false;
}

void advance(){
  for(int w = 0; w < 5; w++){
    for(int s = 0; s < wheel[w].size(); s++){
      wheel[w][s].first += speed[w];
      wheel[w][s].first %= 360;
      //      cout << wheel[w][s].first << " " << wheel[w][s].second << ",";
    }//cout << "; ";
  }//cout << endl;
}

int main() {
  ifstream fin("spin.in");
  ofstream fout("spin.out");

  for(int i = 0; i < 5; i++){
    fin >> speed[i];
    int w;
    fin >> w;
    for(int j = 0; j < w; j++){
      int s, e;
      fin >> s >> e;
      wheel[i].push_back(make_pair(s, e));
    }
  }
  int tTime = -1;
  for(int mTime = 0; mTime < 360; mTime++){
    if(mTime != 0)
      advance();
    if(passes() == true){
      tTime = mTime;
      break;
    }
  }
  if(tTime == -1)
    fout << "none\n";
  else
  fout << tTime << endl;
}
