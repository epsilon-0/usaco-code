/*
ID: mathgen2
PROG: ttwo
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

bool farm[11][11];
int john[2];
int johnD = 0;
int cow[2];
int cowD = 0;
int dirs[4][2];

int main() {
  ifstream fin("ttwo.in");
  ofstream fout("ttwo.out");

  dirs[0][0] = -1; dirs[0][1] = 0;
  dirs[1][0] = 0; dirs[1][1] = 1;
  dirs[2][0] = 1; dirs[2][1] = 0;
  dirs[3][0] = 0; dirs[3][1] = -1;

  char pos;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      fin >> pos;
      farm[i][j] = (pos == '*');
      if(pos == 'F'){
	john[0] = i;
	john[1] = j;
      }
      if(pos == 'C'){
	cow[0] = i;
	cow[1] = j;
      }
    }
  }

  int steps = 0;

  while(!(cow[0] == john[0] && cow[1] == john[1])) {
    steps++;
    if((john[0] + dirs[johnD][0] < 0) ||
       (john[0] + dirs[johnD][0] > 9) ||
       (john[1] + dirs[johnD][1] < 0) ||
       (john[1] + dirs[johnD][1] > 9) ||
       (farm[john[0] + dirs[johnD][0]][john[1] + dirs[johnD][1]])) {
      johnD = (johnD + 1) % 4;
    }
    else{
      john[0] = john[0] + dirs[johnD][0];
      john[1] = john[1] + dirs[johnD][1];
    }
    if((cow[0] + dirs[cowD][0] < 0) ||
       (cow[0] + dirs[cowD][0] > 9) ||
       (cow[1] + dirs[cowD][1] < 0) ||
       (cow[1] + dirs[cowD][1] > 9) ||
       (farm[cow[0] + dirs[cowD][0]][cow[1] + dirs[cowD][1]])) {
      cowD = (cowD + 1) % 4;
    }
    else{
      cow[0] = cow[0] + dirs[cowD][0];
      cow[1] = cow[1] + dirs[cowD][1];
    }
    if(steps > 160000){
      steps = 0;
      break;
    }
    //    cout << john[0] << "," << john[1] << "," << johnD << " " << cow[0] << "," << cow[1] << "," << cowD << endl;    
  }
  fout << steps << endl;
}
