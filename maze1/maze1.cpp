/*
ID: mathgen2
PROG: maze1
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

int W, H;

int index(int r, int c){
  return r*(2*W+1) + c;
}

char maze[205][80];

vector<vector<int> > graph;

vector<int> BFS(vector<vector<int> >& graph, int source){
  vector<int> distance(graph.size(), -1);
  vector<bool> visited(graph.size(), false);
  queue<pair<int, int> > que;

  que.push(make_pair(source, 0));

  while(!(que.empty())){
    pair<int, int> nVert = que.front();
    que.pop();
    cout << nVert.first << " ";
    if(visited[nVert.first]){
      continue;
    }
    visited[nVert.first] = true;
    distance[nVert.first] = nVert.second;
    for(int nbh : graph[nVert.first]){
      que.push(make_pair(nbh, nVert.second+1));
    }
  }
  cout << endl;
  return distance;
}

int main() {
  ifstream fin("maze1.in");
  ofstream fout("maze1.out");

  fin >> W >> H;

  graph.clear(); graph.resize(16000);

  cout << W << " " << H << endl;
  string row;
  getline(fin, row);

  vector<pair<int, int> > exit;
  exit.clear();

  for(int i = 0; i < 2*H+1; i++){
    getline(fin, row);
    for(int j = 0; j < 2*W+1; j++){
      maze[i][j] = row[j];
      if((i == 0 || i == 2*H || j == 0 || j == 2*W) && (maze[i][j] == ' ')){
	exit.push_back(make_pair(i, j));
      }
      cout << index(i, j) << ",";
    }
    cout << endl;
  }

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      int source = index(2*i+1, 2*j+1);
      int nbh;
      if(i < H-1 && maze[2*i+2][2*j+1] != '-'){
	nbh = index(2*i+3, 2*j+1);
	graph[source].push_back(nbh);
	graph[nbh].push_back(source);
      }
      if(j < W-1 && maze[2*i+1][2*j+2] != '|'){
	nbh = index(2*i+1, 2*j+3);
	graph[source].push_back(nbh);
	graph[nbh].push_back(source);
      }
    } 
  }

  for(auto e : exit){
    int eIndex = index(e.first, e.second);
    int nbh;
    if(e.first == 0){
      nbh = index(e.first+1, e.second);
    }
    else{
      nbh = index(e.first-1, e.second);
    }
    graph[eIndex].push_back(nbh);
    graph[nbh].push_back(eIndex);
    if(e.second == 0){
      nbh = index(e.first, e.second+1);
    }
    else{
      nbh = index(e.first, e.second-1);
    }
    graph[eIndex].push_back(nbh);
    graph[nbh].push_back(eIndex);    
  }

  vector<int> dist1 = BFS(graph, index(exit[0].first, exit[0].second));
  vector<int> dist2 = BFS(graph, index(exit[1].first, exit[1].second));
  
  cout << dist1.size() << " " << dist2.size() << endl;
  
  for(int i = 0; i < dist1.size(); i++){
    dist1[i] = min(dist1[i], dist2[i]);
  }

  fout << *max_element(dist1.begin(), dist1.end()) << endl;
  
}
