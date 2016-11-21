/*
ID: mathgen2
PROG: comehome
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

template <class num_t>
class Dijkstra{
public:
  Dijkstra(){}

  vector<num_t> distance(vector<vector<pair<int, num_t> > >& graph, int source){
    vector<num_t> distance(graph.size(), _INF);
    distance[source] = 0;
    set<pair<num_t, int> > que;
    que.insert(make_pair(0, source));
    while(!que.empty()){
      pair<num_t, int> closest = *que.begin(); que.erase(que.begin());
      int vert = closest.second;
      num_t dist = closest.first;
      for(auto nbh : graph[vert]){
	int nbhVert = nbh.first;
	num_t cost = nbh.second;
	if(distance[nbhVert] > distance[vert] + cost){
	  if(distance[nbhVert] != _INF){
	    que.erase(que.find(make_pair(distance[nbhVert], nbhVert)));
	  }
	  distance[nbhVert] = distance[vert] + cost;
	  que.insert(make_pair(distance[nbhVert], nbhVert));
	}
      }
    }
    return distance;
  }
  
  void setInfinity(num_t inf){
    _INF = inf;
  }

private:
  num_t _INF = 99999999;
};

vector<vector<pair<int, int> > > graph;

int main() {
  ifstream fin("comehome.in");
  ofstream fout("comehome.out");

  graph.resize(150);

  int p;
  fin >> p;

  char x, y;
  int e;
  for(int i = 0; i < p; i++){
    fin >> x >> y >> e;
    if(x==y) continue;
    graph[x].push_back(make_pair((int)y, e));
    graph[y].push_back(make_pair((int)x, e));
  }

  Dijkstra<int> djk;

  auto dist = djk.distance(graph, (int)'Z');

  int mMin = (int)'A';
  for(int i = (int)'A'; i < (int)'Z'; i++){
    if(dist[mMin] > dist[i]){
      mMin = i;
    }
  }
  fout << (char)mMin << " " << dist[mMin] << endl;
}
