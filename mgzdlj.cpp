//migongzuiduanlujing
//page 34

#include<cstdio>
#include<queue>
#include<iostream>

using namespace std;

const int INF = 100000000;
const int MAX_N = 100;
const int MAX_M = 100;

//using usr-defined P to represent pair
typedef pair<int, int> P;

char maze[MAX_N][MAX_M];
int N, M;
int sx, sy;
int gx, gy;

//the array to store the distance to the different points
int d[MAX_N][MAX_M];

//using the dx[], dy[] array to represent the moves
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool inBoard(int x, int y){
  return (x >= 0) && (x < N) && (y >= 0) && (y < M);
}

//figure out the shortest distance from start to goal
//if not accessible, reutrn INF
int bfs(){
  queue<P> que;
  //set the distance from the starting point to INF at first
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      d[i][j] = INF;
    }
  }
  //set the original value
  d[sx][sy] = 0;
  que.push(P(sx, sy));
  
  while(que.size()){
    P p ;
    p.first = que.front().first;
    p.second = que.front().second;
    que.pop();

    if(p.first == gx && p.second == gy)
      break;

    for(int i = 0; i < 4; i++){
      int xprime = p.first + dx[i];
      int yprime = p.second + dy[i];
      if(inBoard(xprime, yprime) && (maze[xprime][yprime] != '#')){
	d[xprime][yprime] = d[p.first][p.second] + 1;
	que.push(P(xprime, yprime));
      }
    }
  }

  return d[gx][gy];
}

void solve(){
  int res = bfs();
  printf("%d", res);
}

int main()
{
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> maze[i][j];
      if(maze[i][j] == 'S'){
	sx = i;
	sy = j;
      }
      else if(maze[i][j] == 'G'){
	gx = i;
	gy = j;
      }
    }
  }

  solve();
  
  return 0;
}
