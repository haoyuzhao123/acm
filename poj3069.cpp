//poj 3069
//saruman's army
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAX_R = 1000;
const int MAX_N = 1000;

int R, N;
int x[MAX_N];

void solve(){
  sort(x, x + N);
  int ans = 0;
  int i = 0;
  int s;
  while(i < N){
    ans++;
    s = x[i++];
    while(x[i] <= s + R && i < N){
      i++;
    }

    int p = x[i-1];

    while(i < N && x[i] <= p + R){
      i++;
    }
  }

  printf("%d\n", ans);
}

int main()
{
  while(true){
    scanf("%d%d", &R, &N);
    if( R == -1 && N == -1)
      break;
    for(int i = 0; i < N; i++){
      scanf("%d", x + i);
    }
    solve();
  }
  return 0;
}
