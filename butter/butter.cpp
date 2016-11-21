/*
ID: mathgen2
PROG: butter
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
  num_t _INF = 9999999;
};

Dijkstra<long long> djk;

vector<int> cow;
vector<vector<pair<int, long long> > > graph;

int main() {
  graph.resize(805);
  ifstream fin("butter.in");
  ofstream fout("butter.out");

  int n, p, c;
  fin >> n >> p >> c;

  int past;
  for(int i = 0; i < n; i++){
    fin >> past;
    cow.push_back(past);
  }

  int a, b;
  long long w;
  for(int i = 0; i < c; i++){
    fin >> a >> b >> w;
    graph[a].push_back(make_pair(b, w));
    graph[b].push_back(make_pair(a, w));
  }

  vector<long long> dist = djk.distance(graph, cow[0]);
  for(int c = 1; c < cow.size(); c++){
    vector<long long> temp = djk.distance(graph, cow[c]);
    for(int i = 0; i < dist.size(); i++){
      dist[i] += temp[i];
    }
  }

  fout << *min_element(dist.begin(), dist.end()) << endl;
}
