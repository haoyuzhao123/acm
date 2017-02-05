//poj3264
//balanced lineup

#include <cstdio>
#include <map>

using namespace std;

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

typedef pair<int, int> P;

const int MAX_N = 50000;
const int MAX_Q = 200000;
const int INF = 10000000;

//segment-tree size
const int ST_SIZE = (1 << 17) - 1;

//the parameters
int N, Q;

int H[MAX_N];
int L[MAX_Q], R[MAX_Q];

//segment-tree
int maxh[ST_SIZE];
int minh[ST_SIZE];

void init() {
  for (int i = 0; i < ST_SIZE; i++) {
    minh[i] = INF;
  }
}

void change(int i, int height, int k, int l, int r) {
  if (l > i)
    return;
  if (r <= i)
    return;
  if (r - l == 1) {
      maxh[k] = height;
      minh[k] = height;
      return;
  }
  
  int m = (l + r) / 2;
  int chl = 2 * k + 1;
  int chr = 2 * k + 2;
  if (i < m) {
    change(i, height, chl, l, m);
  }
  else {
    change(i, height, chr, m, r);
  }
  maxh[k] = max(maxh[chl], maxh[chr]);
  minh[k] = min(minh[chl], minh[chr]);
}

P maxmin(int a, int b, int k, int l, int r) {
  if (a >= r || b <= l) {
    return P(-INF, INF);
  }
  else if (a <= l && b >= r) {
    return P(maxh[k], minh[k]);
  }
  else {
    int m = (l + r) / 2;
    int chl = 2 * k + 1;
    int chr = 2 * k + 2;
    P p1 = maxmin(a, b, chl, l, m);
    P p2 = maxmin(a, b, chr, m, r);
    return P(max(p1.first, p2.first), min(p1.second, p2.second));
  }
}

int diff(int a, int b) {
  P p = maxmin(a, b, 0, 0, N);
  return p.first - p.second;
}

void solve() {
  init();
  
  for (int i = 0; i < N; i++) {
    change(i, H[i], 0, 0, N);
  }

  for (int i = 0; i < Q; i++) {
    printf("%d\n", diff(L[i] - 1, R[i]));
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  scanf("%d%d", &N, &Q);
  for (int i = 0; i < N; i++) {
    scanf("%d", H + i);
  }
  for (int i = 0; i < Q; i++) {
    scanf("%d%d", L + i, R + i);
  }

  solve();

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
}
