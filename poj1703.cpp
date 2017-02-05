//poj1703
//Find them, catch them
#include<cstdio>

using namespace std;

const int MAX_N = 100010;

//union-find
int par[2 * MAX_N];
int rank[2 * MAX_N];

void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x)
    return x;
  else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(x == y)
    return;
  if(rank[x] < rank[y])
    par[x] = y;
  else{
    par[y] = x;
    if(rank[x] == rank[y])
      rank[x]++;
  }
}

bool same(int a, int b){
  return find(a) == find(b);
}

int T, N, M;

void solve(){
  char request;
  int a, b;
  init(2 * N);
  for(int i = 0; i < M; i++){
    scanf(" %c%d%d", &request, &a, &b);
    a--;
    b--;
    if(request == 'A'){
      if(same(a, b + N))
	printf("In different gangs.\n");
      else if(same(a, b))
	printf("In the same gang.\n");
      else
	printf("Not sure yet.\n");
    }
    else if(request == 'D'){
      unite(a, b + N);
      unite(a + N, b);
    }
  }
}
  

int main()
{
  scanf("%d", &T);
  for(int j = 0; j < T; j++){
    scanf("%d%d", &N, &M);
    solve();
  }
  return 0;
}
