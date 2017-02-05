//poj3061
//subsequence

#include <cstdio>

using namespace std;

const int MAX_N = 100010;
const int INF = 1<<20;

int n, S;
int a[MAX_N];

void solve() {
  int i = 0;
  int j = 0;
  int res = INF;
  int sum = 0;
  if (sum >= S) {
    printf("%d\n", 0);
    return;
  }
  
  for (; i < n; i++) {
    for (; j <= n; j++) {
      if (sum >= S) {
	int len = j - i;
	if (len < res) {
	  res = len;
	}
	break;
      }
      if (j != n) {
	sum += a[j];
      }
      else {
        break;
      }
      
    }
    
    sum -= a[i];
  }

  if (res == INF) {
    printf("%d\n", 0);
  }
  else {
    printf("%d\n", res);
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  int cases;
  scanf("%d", &cases);
  for (int i = 0; i < cases; i++) {
    scanf("%d%d", &n ,&S);
    for (int j = 0; j < n; j++) {
      scanf("%d", a + j);
    }
    solve();
  }
  
  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
}
