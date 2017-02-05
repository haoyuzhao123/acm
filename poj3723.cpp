//poj 3723
//Conscription

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 10000;
const int MAX_M = 10000;
const int MAX_R = 50000;

struct edge{
  int u;
  int v;
  int cost;
};

bool comp(const edge & e1, const edge & e2) {
  return e1.cost < e2.cost;
}

class Unionfind{
public:
  Unionfind();
  
  Unionfind(int n){
    par = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) {
      rank[i] = 0;
      par[i] = i;
    }
  }

  ~Unionfind(){
    delete[] rank;
    delete[] par;
  }
  
  int find(int x){
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }
  
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (rank[x] < rank[y]) {
      par[x] = y;
    }
    else {
      par[y] = x;
      if (rank[x] == rank[y]) {
	rank[x] += 1;
      }
    }
  }
  
  bool same(int x, int y){
    return find(x) == find(y);
  }
  
private:
  int * par;
  int * rank;
};

int N, M, R;
edge es[MAX_R];

void solve(){
  sort(es, es + R, comp);
  Unionfind uf(M + N);
  int res = 0;
  for (int i = 0; i < R; i++) {
    edge e = es[i];
    if (uf.same(e.u, e.v))
      continue;
    else {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  printf("%d\n", 10000 * (M + N) + res);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  int cases;
  scanf("%d", &cases);
  for (int i = 0; i < cases; i++){
    scanf("%d%d%d", &N, &M, &R);
    for (int j = 0; j < R; j++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      c = -c;
      b += N;
      es[j].u = a;
      es[j].v = b;
      es[j].cost = c;
    }
    solve();
  }

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
}
