//poj 3279
//fliptile

#include <cstdio>

using namespace std;

const int MAX_M = 15;
const int MAX_N = 15;
const int INF = 1<<20;

int dx[] = {-1, 0, 0, 0, 1};
int dy[] = {0, -1, 0, 1, 0};

int M, N;
int field[MAX_M][MAX_N];
int solution[MAX_M][MAX_N];
int opt[MAX_M][MAX_N];

bool inBoard(int m, int n) {
  return m >= 0 && m < M && n >= 0 && n < N;
}

int fill(int m, int n) {
  int v = field[m][n];
  for (int i = 0; i < 4; i++) {
    if (inBoard(m + dx[i], n + dy[i])) {
      v += solution[m + dx[i]][n + dy[i]];
    }
  }
  return v % 2;
}

void copySolution() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      opt[i][j] = solution[i][j];
    }
  }
}

bool isSolution() {
  for (int i = 0; i < N; i++) {
    if (fill(M - 1, i)) {
      return false;
    }
  }
  return true;
}

int countStep() {
  int res = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      res += solution[i][j];
    }
  }
  return res;
}

void solve() {
  int MIN_STEP = INF;
  for (int i = 0; i < 1<<N; i++) {
    for (int j = 0; j < N; j++) {
      solution[0][N-j-1] = (i>>j) & 1;
    }

    for (int i = 1; i < M; i++) {
      for (int j = 0; j < N; j++) {
	solution[i][j] = fill(i - 1, j);
      }
    }
    
    int temp = countStep();
    if (isSolution() && temp < MIN_STEP) {
      MIN_STEP = temp;
      copySolution();
    }
  }
  
  if (MIN_STEP == INF)
    printf("IMPOSSIBLE\n");
  else {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
	printf("%d ", opt[i][j]);
      }
      printf("\n");
    }
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  scanf("%d%d", &M, &N);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &(field[i][j]));
    }
  }
  solve();

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif

  return 0;
}
