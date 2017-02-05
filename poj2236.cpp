//poj2236
//wireless network
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

const int MAX_N = 1024;

//the distance funciton
struct point{
  int x;
  int y;
};

int square(int a){
  return a * a;
}

//the union-find
int par[MAX_N];
int rank[MAX_N];

void init(int n){
  for(int i = 0; i < n; i++){
    par[i] = i;
    rank[i] = 0;
  }
}

int find(int x){
  if(par[x] == x){
    return x;
  }
  else{
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y){
  x = find(x);
  y = find(y);
  if(find(x) == find(y))
    return;

  if(rank[x] < rank[y]){
    par[x] = y;
  }
  else{
    par[y] = x;
    if(rank[x] == rank[y]){
      rank[x] += 1;
    }
  }
}

bool same(int x, int y){
  return find(x) == find(y);
}

//this problem
int N, d;
point computers[MAX_N];
bool able[MAX_N][MAX_N];
bool STATUS[MAX_N];

int main()
{
  scanf("%d%d", &N, &d);
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      able[i][j] = false;
    }
    STATUS[i] = false;
  }
  
  for(int i = 0; i < N; i++){
    scanf("%d%d", &(computers[i].x), &(computers[i].y));
    for(int j = 0; j <= i; j++){
      if(square(computers[i].x - computers[j].x) +
	 square(computers[i].y - computers[j].y) <= square(d)){
	able[i][j] = true;
	able[j][i] = true;
      }
    }
  }



  init(N);

  char opt;
  while(cin >> opt){
    if(opt == 'O'){
      int p;
      scanf("%d", &p);
      p--;
      STATUS[p] = true;
      for(int i =0 ; i < N; i++){
	if(STATUS[i] && able[i][p]){
	  if(!same(p, i)){
	    unite(p, i);
	  }
	}
      }
    }
    else if(opt == 'S'){
      int p, q;
      scanf("%d%d", &p, &q);
      p--;
      q--;
      if(same(p, q)){
	printf("SUCCESS\n");
      }
      else{
	printf("FAIL\n");
      }
    }
  }

  return 0;
}
