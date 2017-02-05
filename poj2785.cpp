//poj2785
//4 values whose sum is 0

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 4000;

int n;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

int CD[MAX_N * MAX_N];

void solve() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      CD[i * n + j] = C[i] + D[j];
    }
  }

  sort(CD, CD + n * n);

  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cd = -(A[i] + B[j]);
      res += upper_bound(CD, CD + n * n, cd)
	- lower_bound(CD, CD + n * n, cd);
    }
  }

  printf("%lld\n", res);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", A + i, B + i, C + i, D + i);
  }
  solve();

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  return 0;
}
