//poj 3468
//a simple problem with integers

#include <cstdio>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

using namespace std;

typedef long long ll;

const int DAT_SIZE = (1 << 18) - 1;
const int MAX_N = 100000;
const int MAX_Q = 100000;

int N, Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

ll data[DAT_SIZE], datb[DAT_SIZE];

void add(int a, int b, int x, int k, int l, int r) {
  if (a <= l && r <= b) {
    data[k] += x;
  }
  else if (l < b && a < r) {
    datb[k] += (min(b, r) - max(a, l)) * x;
    add(a, b, x, k * 2 + 1, l, (l + r) / 2);
    add(a, b, x, k * 2 + 2, (l + r) / 2, r);
  }
}

ll sum(int a, int b, int k, int l, int r) {
  if ( b <= l || a >= r) {
    return 0;
  }
  else if (a <= l && b >= r) {
    return data[k] * (r - l) + datb[k];
  }
  else {
    ll res = (min(b, r) - max(a, l)) * data[k];
    res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
    res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
    return res;
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    add(i - 1, i, A[i], 0, 0, N);
  }

  for (int i = 0; i < Q; i++) {
    if (T[i] == 'C') {
      add(L[i] - 1, R[i], X[i], 0, 0, N);
    }
    else {
      printf("%lld\n", sum(L[i] - 1, R[i], 0, 0, N));
    }
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
    scanf("%d", A + i);
  }

  for (int i = 0; i < Q; i++) {
    scanf(" %c", T + i);
    scanf("%d%d", L + i, R + i);
    if (T[i] == 'C') {
      scanf("%d", X + i);
    }
  }

  solve();
  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif  

  return 0;
}	       
