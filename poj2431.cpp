//poj2431
//expedition
#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

const int MAX_N = 10010;

int N, L, P;
int A[MAX_N];
int B[MAX_N];

void solve(){
  A[N] = L;
  B[N] = 0;
  N++;
  priority_queue<int> que;

  int ans = 0;
  int pos = 0;
  int tank = P;
  for(int i = 0; i < N; i++){
    int d = A[i] - pos;
    while(tank - d < 0){
      if(que.empty()){
	cout<<-1<<endl;
	return;
      }
      tank += que.top();
      que.pop();
      ans++;
    }

  tank -= d;
  pos = A[i];
  que.push(B[i]);
  }
  printf("%d\n", ans);
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d%d", A+i, B+i);
  }
  scanf("%d%d", &L, &P);
  solve();
  return 0;
}
