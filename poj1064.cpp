//poj 1064
//cable master
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

//define the constant
const int MAX_N = 10000;
const int MAX_K = 10000;
const int INF = 100030;

//define the global variables
int N, K;
double L[MAX_N];

bool isSatisfied(double x) {
  int num = 0;
  for (int i = 0; i < N; i++) {
    num += (int) floor(L[i] / x);
  }
  return num >= K;
}

void solve(){
  double lb = 0;
  double ub = INF;

  for (int i = 0; i < 100; i++) {
    double mid = (lb + ub) / 2;
    if (isSatisfied(mid)) {
      lb = mid;
    }
    else {
      ub = mid;
    }
  }

  printf("%.2f", floor(ub * 100) / 100);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &L[i]);
  }
  
  solve();
  
  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
}
