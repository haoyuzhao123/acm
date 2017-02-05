//poj 3276
//face the right way

#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 5000;
const int INF = 1<<20;

int dir[MAX_N];
int f[MAX_N];
int N;

int calc(int K) {
  memset(f, 0, sizeof(f));
  int res = 0;
  int sum = 0;
  for (int i = 0; i <= N - K; i++) {
    if ((dir[i] + sum) % 2 != 0) {
      res++;
      f[i] = 1;
    }
    sum += f[i];
    if (i - K + 1 >= 0) {
      sum -= f[i - K + 1];
    }
  }
  
  for (int i = N - K + 1; i < N; i++) {
    if ((dir[i] + sum) % 2 != 0) {
      return -1;
    }
    if (i - K + 1 >= 0) {
      sum -= f[i - K + 1];
    }
  }
  return res;
}

void solve() {
  int K = 1;
  int M = N;
  for (int i = 1; i <= N; i++) {
    int m = calc(i);
    if (m >= 0 && M > m) {
      M = m;
      K = i;
    }
  }
  printf("%d %d\n", K, M);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    char c;
    scanf(" %c", &c);
    if (c == 'B') {
      dir[i] = 1;
    }
    else {
      dir[i] = 0;
    }
  }
  solve();

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif

  return 0;
}
