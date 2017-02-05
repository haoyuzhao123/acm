//poj 3253
//fence repair
#include<cstdio>
#include<queue>

using namespace std;

typedef long long ll;

const int MAX_N = 20000;
int N;
int l[MAX_N];

void solve(){
  ll ans = 0;
  priority_queue<int, vector<int>, greater<int> > que;
  for(int i = 0; i < N; i++){
    que.push(l[i]);
  }
  while(que.size() != 1){
    int first = que.top();
    que.pop();
    int second = que.top();
    que.pop();
    ans += (first + second);
    que.push(first + second);
  }
  printf("%lld\n", ans);
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", l + i);
  }
  solve();
  return 0;
}
