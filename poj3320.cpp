//poj3320
//jessica's reading problem

#include <cstdio>
#include <set>
#include <map>

using namespace std;

#define min(a, b) a<b?a:b

const int INF = 1<<20;
const int MAX_P = 1000000;

int a[MAX_P];
int P;

void solve() {
  set<int> all;
  for (int i = 0; i < P; i++) {
    all.insert(a[i]);
  }
  int n = all.size();

  int s = 0;
  int t = 0;
  int num = 0;
  map<int, int> count;
  int res = P;
  for (;;) {
    while (t < P && num < n) {
      if(count[a[t++]]++ == 0) {
	num++;
      }
    }
    if (num < n) break;
    res = min(res, t - s);
    if (--count[a[s++]] == 0) {
      num--;
    }
  }

  printf("%d\n", res);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif

  scanf("%d", &P);
  for (int i = 0; i < P; i++) {
    scanf("%d", a + i);
  }
  solve();
  
  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
} 
