//poj2386
//Lake Counting

#include<cstdio>
#include<iostream>

using namespace std;

const int MAX_INPUT = 100;
char field[MAX_INPUT][MAX_INPUT];
int N,M;

bool infield(int x, int y){
  return x>=0 && x<N && y>=0 && y<M;
}

void dfs(int x, int y){
  field[x][y] = '.';
  for(int dx = -1; dx<=1; dx++){
    for(int dy = -1; dy<=1; dy++){
      if(infield(x+dx, y+dy) && field[x+dx][y+dy] == 'W')
	dfs(x+dx, y+dy);
    }
  }
}

void solve(){  
  int result = 0;
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      if(field[i][j] == 'W'){
	dfs(i,j);
	result++;
      }
    }
  }
  cout<<result;
}

int main()
{
  scanf("%d%d", &N, &M);
  for(int i=0; i<N; i++){
    for(int j=0; j<M; j++){
      cin>>field[i][j];
    }
  }
  
  solve();
  return 0;
}
