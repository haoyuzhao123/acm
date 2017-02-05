//poj2229
//sumsets
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long ll;

const int MAX_N = 1000000;
int N;
ll res[MAX_N + 1];

void solve(){
  res[1] = 1;
  for(int i = 2; i <= N; i++){
    if(i % 2 == 0){
      res[i] = (res[i - 1] + res[i >> 1]) % 1000000000;
    }
    else{
      res[i] = res[i - 1];
    }
  }
  printf("%lld\n", res[N]);
}

int main()
{
  scanf("%d", &N);
  solve();
  return 0;
}
