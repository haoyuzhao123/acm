//bellmanford
#include<cstdio>

using namespace std;

struct edge{
  int from;
  int to;
  int cost;
};

edge es[MAX_E];

int d[MAX_V];
int V, E;

void bellmanford(int s){
  for(int i = 0; i < V; i++){
    d[i] = INF;
  }
  d[s] = 0;
  while(true){
    bool update = false;
    for(int i = 0; i < E; i++){
      edge e = es[i];
      if(d[e.from] != INF && d[e.to] > d[e.from] + d[e.cost]){
	d[e.to] = d[e.from] + d[e.cost];
	update = true;
      }
    }
    if(!update)
      break;
  }
}
