/*
ID: mathgen2
PROG: friday
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int freq[] = {0, 0, 0, 0, 0, 0, 0, 0};

bool isLeap(int year){
  if(year%100) return year%4==0;
  return year%400==0;
}

int main(){
  ifstream fin("friday.in");
  ofstream fout("friday.out");
  int num;
  fin >> num;
  int cday, day;
  cday = 0;
  for(int year = 1900; year < 1900+num; year++){
    for(int month = 0; month < 12; month++){
      day = (cday+12)%7;
      freq[day]++;
      cday += isLeap(year) ? leapDays[month] : days[month];
    }
  }
  fout << freq[5] << " " << freq[6] << " " << freq[0] << " " << freq[1] << " " << freq[2] << " " << freq[3] << " " << freq[4] << endl;
}
