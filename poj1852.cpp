//POJ 1852
//Ants

#include<cstdio>

using namespace std;

//global variables
const int MAX_INPUT = 1000005;
int array[MAX_INPUT];
int L,n;
int mintime, maxtime;

//functions
int min(int a, int b){
  return a<b?a:b;
}

int max(int a, int b){
  return a>b?a:b;
}

void solve(){
  mintime = 0;
  maxtime = 0;
  
  for(int i=0;i<n;i++){
    mintime = max(min(array[i], L-array[i]), mintime);
  }

  for(int i=0;i<n;i++){
    maxtime = max(max(array[i], L-array[i]), maxtime);
  }
}

int main()
{
  int ncases;
  scanf("%d", &ncases);
  for(int j=0;j<ncases;j++){
    scanf("%d%d", &L, &n);
    for(int i=0;i<n;i++){
      scanf("%d", array+i);
    }

    solve();
    printf("%d %d\n", mintime, maxtime);
  }
  return 0;
}
