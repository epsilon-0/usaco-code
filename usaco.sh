#!/bin/bash
mkdir $1
mFile="$1/$1.cpp"
echo "/*" >> $mFile
echo "ID: mathgen2" >> $mFile
echo "PROG: $1" >> $mFile
echo "LANG: C++11" >> $mFile
echo "*/" >> $mFile
echo "" >> $mFile
echo "#include <bits/stdc++.h>" >> $mFile
echo "" >> $mFile
echo "using namespace std;" >> $mFile
echo "" >> $mFile
echo "int main() {" >> $mFile
echo "  ifstream fin(\"$1.in\");" >> $mFile
echo "  ofstream fout(\"$1.out\");" >> $mFile
echo "" >> $mFile
echo "}" >> $mFile
touch "$1/$1.in"
touch "$1/$1.out"
