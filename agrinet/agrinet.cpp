/*
ID: mathgen2
PROG: agrinet
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

template <class num_t>
class Prims{
public:
  Prims(){}

  vector<tuple<num_t, int, int> > MST(vector<vector<pair<int, num_t> > > graph){
    vector<tuple<num_t, int, int> > mst;
    set<tuple<num_t, int, int> > edges;
    vector<bool> inSet(graph.size(), false);
    for(int vert = 0; vert < graph.size(); vert++){
      if(inSet[vert]) continue;
      inSet[vert] = true;
      for(auto edge : graph[vert]){
	edges.insert(make_tuple(edge.second, vert, edge.first));
      }
      while(!edges.empty()){
	auto edge = *edges.begin(); edges.erase(edges.begin());
	int nextVert = get<2>(edge);
	if(inSet[nextVert])
	  continue;
	inSet[nextVert] = true;
	mst.push_back(edge);
	for(auto edge : graph[nextVert]){
	  edges.insert(make_tuple(edge.second, nextVert, edge.first));
	}
      }
    }
    return mst;
  }
};

vector<vector<pair<int, int> > > graph;

int main() {
  ifstream fin("agrinet.in");
  ofstream fout("agrinet.out");

  graph.resize(111);

  int n;
  
  fin >> n;
  int e;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      fin >> e;
      graph[i].push_back(make_pair(j, e));
    }
  }
  Prims<int> prim;
  auto mst = prim.MST(graph);
  int total = 0;
  for(auto edge : mst){
    total += get<0>(edge);
  }
  fout << total << endl;
}
