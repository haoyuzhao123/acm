//poj1182
//shi wu lian
#include<cstdio>

using namespace std;

const int MAX_N = 50010;
const int MAX_K = 100010;

//union-find code
int par[3 * MAX_N];
int rank[3 * MAX_N];

void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }
  else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y)
    return;

  if(rank[x] < rank[y]){
    par[x] = y;
  }
  else{
    par[y] = x;
    if(rank[x] == rank[y]){
      rank[x] += 1;
    }
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

//this problem
int N, K;
int T[MAX_K];
int X[MAX_K];
int Y[MAX_K];

void solve(){
  init(3 * N);
  int ans = 0;
  for(int i = 0; i < K; i++){
    int t = T[i];
    int x = X[i] - 1;
    int y = Y[i] - 1;

    if(x < 0 || x >= N || y < 0 || y >= N){
      ans++;
      continue;
    }

    if(t == 1){
      if(same(x, y +  N) || same(x, y + 2 * N)){
	ans++;
      }
      else{
	unite(x, y);
	unite(x + N, y + N);
	unite(x + 2 * N, y + 2 * N);
      }
    }
    else{
      if(same(x, y) || same(x, y + 2 * N)){
	ans++;
      }
      else{
	unite(x, y + N);
	unite(x + N, y + 2 * N);
	unite(x + 2 * N, y);
      }
    }
  }
  printf("%d\n", ans);
}

int main()
{
  scanf("%d%d", &N, &K);
  for(int i = 0; i < K; i++){
    scanf("%d%d%d", T + i, X + i, Y + i);
  }
  solve();
  return 0;
}
