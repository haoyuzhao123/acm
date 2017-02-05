//poj 3616
//milking time
#include<cstdio>
#include<algorithm>

using namespace std;

#define max(a, b) ((a > b) ? a : b)

struct Interval{
  int start;
  int end;
  int efficiency;
  bool operator < (const Interval& i) const{
    return start < i.start;
  }
};

const int MAX_N = 1000010;
const int MAX_M = 10010;

int N;
int M;
int R;

int dp[MAX_M];
Interval interval[MAX_M];

void solve(){
  for(int i = 1; i <= M; i++){
    dp[i] = interval[i].efficiency;
  }
  for(int i = 1; i <= M; i++){
    for(int j = 1; j <= i; j++){
      if(interval[j].end <= interval[i].start){
	dp[i] = max(dp[i], dp[j] + interval[i].efficiency);
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= M; i++){
    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
}

int main()
{
  scanf("%d%d%d", &N, &M, &R);
  for(int i = 0; i < M; i++){
    scanf("%d%d%d", &(interval[i].start),
	  &(interval[i].end), &(interval[i].efficiency));
    interval[i].end = interval[i].end + R;
  }
  sort(interval + 1, interval + M + 1);
  solve();
  return 0;
}
