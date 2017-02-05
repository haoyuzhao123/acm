//poj2385
//apple catching
#include<cstdio>

using namespace std;

#define max(a, b) ((a > b) ? a : b)

const int MAX_T = 1001;
const int MAX_W = 31;
const int STATUS = 2;
const int INF = 100000000;

int T, W;
int value[MAX_T];
int dp[MAX_T][MAX_W][STATUS];

void solve(){
  for(int i = 1; i <= T; i++){
    dp[i][0][1] = dp[i - 1][0][1] + (value[i] % 2);
  }
  for(int i = 1; i <= T; i++){
    for(int j = 1; j <= W; j++){
      for(int s = 0; s <= STATUS; s++){
	if((j + s) % 2 == 1){
	  dp[i][j][s] = max(dp[i - 1][j][s] + (1 + value[i] + s) % 2,
			    dp[i - 1][j - 1][(s + 1) % 2] + (1 + value[i] + s) % 2);
	}
      }
    }
  }
  int ans = 0;
  for(int i = 0; i <= W; i++){
    ans = max(ans, dp[T][i][(i + 1) % 2]);
  }
  printf("%d\n", ans);
}

int main()
{
  scanf("%d%d", &T, &W);
  for(int i = 1; i<= T; i++){
    scanf("%d", value + i);
  }
  solve();
  return 0;
}
