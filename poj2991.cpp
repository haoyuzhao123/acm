//poj2991
//crane

#include <cstdio>
#include <cmath>

using namespace std;

const int MAX_N = 10000;
const int MAX_C = 10000;
const int ST_SIZE = (1 << 15) - 1;
const double MPI = 3.14159265;

int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

double vx[ST_SIZE], vy[ST_SIZE], ang[ST_SIZE];
double pre[MAX_N];

void init(int k, int l, int r) {
  ang[k] = 0.0;
  vx[k] = 0.0;
  if (r - l == 1) {
    vy[k] = L[l];
  }
  else {
    int chl = 2 * k + 1;
    int chr = 2 * k + 2;
    init(chr, (1 + r) / 2, r);
    init(chl, l, (l + r) / 2);
    vy[k] = vy[chl] + vy[chr];
  }
}

void change(int s, double a, int v, int l, int r) {
  if (s <= l) {
    return;
  }
  else if (s < r) {
    int chl = v * 2 + 1;
    int chr = v * 2 + 2;
    int m = (l + r) / 2;
    change(s, a, chl, l, m);
    change(s, a, chr, m, r);

    if (s <= m) {
      ang[v] += a;
    }

    double s = sin(ang[v]);
    double c = cos(ang[v]);
    vx[v] = vx[chl] + c * vx[chr] - s * vy[chr];
    vy[v] = vy[chl] + s * vx[chr] + c * vy[chr];
  }
}

void solve() {
  init(0, 0, N);
  for (int i = 1; i < N; i++) {
    pre[i] = M_PI;
  }

  for (int i = 0; i < C; i++) {
    int s = S[i];
    double a = A[i] / 360.0 * 2 * MPI;
    change(s, a - pre[s], 0, 0, N);
    pre[s] = a;

    printf("%.2f %.2f\n", vx[0], vy[0]);
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  while(true) {
    if (scanf("%d%d", &N, &C) != EOF) {
      for (int i = 0; i < N; i++) {
	scanf("%d", L + i);
      }
      for (int i = 0; i < C; i++) {
	scanf("%d%d", S + i, A + i);
      }
      solve();
      printf("\n");
    }
    else {
      break;
    }
  }
  
  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
}
