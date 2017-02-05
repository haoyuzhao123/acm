//poj 3176
//cow bowling

#include<cstdio>
#include<cstring>

using namespace std;

#define max(a, b) ((a > b) ? a : b)

const int MAX_N = 350;
int N;
int value[MAX_N + 1][MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];

void solve(){
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= i; j++){
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + value[i][j];
    }
  }
  int res = 0;
  for(int i = 0; i <= N; i++){
    res = max(res, dp[N][i]);
  }
  printf("%d\n", res);
}

int main()
{
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= i; j++){
      scanf("%d", &(value[i][j]));
    }
  }
  solve();
  return 0;
}
