/*
ID: mathgen2
PROG: fence
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

class Euler{
public:
  Euler(){}

  vector<int> getTour(vector<vector<int> > mGraph){
    graph.resize(mGraph.size(), multiset<int>());
    circuit.clear();
    for(int i = 0; i < graph.size(); i++){
      for(int j = 0; j < mGraph[i].size(); j++){
	graph[i].insert(mGraph[i][j]);
      }
    }
    int s0=-1, s1=-1, s2;
    for(int i = 0; i < graph.size(); i++){
      if(graph[i].size() > 0 && s0==-1)
	s0 = i;
      if(graph[i].size()%2)
	s1==-1 ? s1=i : s2=i;
    }
    s0 = s1==-1 ? s0 : min(s1, s2);
    cout << s0 << endl;
    findTour(s0);
    reverse(circuit.begin(), circuit.end());
    return circuit;
  }

  void findTour(int node){
    if(graph[node].empty()){
      circuit.push_back(node);
    }
    else{
      while(!graph[node].empty()){
	int nbh = *graph[node].begin(); graph[node].erase(graph[node].begin());
	graph[nbh].erase(graph[nbh].find(node));
	findTour(nbh);
      }
      circuit.push_back(node);
    }
  }

private:
  vector<multiset<int> > graph;
  vector<int> circuit;
};

int main() {
  ifstream fin("fence.in");
  ofstream fout("fence.out");

  vector<vector<int> > graph(500, vector<int>());
  int f, x, y, n=0;
  fin >> f;
  for(int i = 0; i < f; i++){
    fin >> x >> y;
    x--;y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
    n = max(n, max(x, y));
  }
  graph.resize(n+1);
  Euler elr;
  vector<int> circuit = elr.getTour(graph);
  for(auto node : circuit){
    fout << node+1 << endl;
  }
}
