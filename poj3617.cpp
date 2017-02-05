//poj3617
//Best Cow Line

#include<cstdio>
#include<iostream>

using namespace std;

const int MAX_N = 2000;

int N;
char s[MAX_N + 1];

void solve(){
  int a = 0;
  int b = N-1;

  int num = 0;
  while(a <= b){
    bool left = false;
    for(int i = 0; i <= b - a; i++){
      if(s[a + i] < s[b - i]){
	left = true;
	break;
      }
      else if( s[a+i] > s[b-i]){
	left = false;
	break;
      }
    }
    
    if(left){
      putchar(s[a++]);
    }
    else{
      putchar(s[b--]);
    }
    
    num++;
    
    if(num % 80 == 0){
      putchar('\n');
    }
  }

  putchar('\n');
}

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    cin >> s[i];
  }
  solve();
  return 0;
}
