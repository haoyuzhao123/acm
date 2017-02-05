//poj 3255
//Roadblocks

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> P;

struct edge{
  int to;
  int cost;
};

const int INF = 2 << 29;
const int MAX_R = 100010;
const int MAX_N = 5010;

int N, R;
vector<edge> G[MAX_N];

int dist[MAX_N];
int dist2[MAX_N];

void solve(){
  priority_queue<P, vector<P>, greater<P> > que;
  for (int i = 0; i < N; i++){
    dist[i] = INF;
    dist2[i] = INF;
  }
  dist[0] = 0;
  que.push(P(0, 0));

  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second;
    int d = p.first;
    if(dist2[v] <= d)
      continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      int d2 = e.cost + d;
      if (d2 < dist[e.to]){
	int temp;
	dist[e.to] = temp;
	dist[e.to] = d2;
	d2 = temp;
	que.push(P(dist[e.to], e.to));
      }
      if (d2 < dist2[e.to] && dist[e.to] <= d2) {
	dist2[e.to] = d2;
	que.push(P(d2, e.to));
      }
    }
  }
  printf("%d\n", dist2[N-1]);
}

int main()
{
  scanf("%d%d", &N, &R);
  for (int i = 0; i < R; i++) {
    int A, B, D;
    scanf("%d%d%d", &A, &B, &D);
    edge e;
    A--;
    B--;
    e.to = B;
    e.cost = D;
    G[A].push_back(e);
    e.to = A;
    G[B].push_back(e);
  }
  solve();
  return 0;
}
