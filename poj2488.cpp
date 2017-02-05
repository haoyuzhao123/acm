//poj 2488
//A Knight's Journey

#include <cstdio>
#include <vector>

using namespace std;

const int MAX_P = 26;
const int MAX_Q = 26;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

vector<pair<int, int> > path;
typedef pair<int, int> Pi;

int chessboard[MAX_Q][MAX_P];

int P, Q;
int count;

void init_board() {
  for (int i = 0; i < MAX_Q; i++) {
    for (int j = 0; j < MAX_P; j++) {
      chessboard[i][j] = 0;
    }
  }
}

bool in_board(int x, int y) {
  return (x >= 0) && (x < Q) &&
    (y >= 0) && (y < P);
}

bool dfs(int x, int y) {
  if (count == (P * Q)) {
    return true;
  }
  else {
    for (int i = 0; i < 8; i++) {
      int _x = x + dx[i];
      int _y = y + dy[i];
      if (in_board(_x, _y) && chessboard[_x][_y] == 0) {
	chessboard[_x][_y] = 1;
	path.push_back(Pi(_x, _y));
	count++;
	
	if(dfs(_x, _y)) {
	  return true;
	}
	else {
	  chessboard[_x][_y] = 0;
	  path.pop_back();
	  count--;
	}
      }
    }
    return false;
  }
}

void solve() {
  init_board();
  path.clear();
  count = 1;
  chessboard[0][0] = 1;
  if (dfs(0, 0)) {
    printf("%c%d", 'A', 1);
    for (int i = 0; i < path.size(); i++) {
      char c = 'A' + path[i].first;
      int d = 1 + path[i].second;
      printf("%c%d", c, d);
    }
    printf("\n\n");
  }
  else {
    printf("impossible\n\n");
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  int cases;
  scanf("%d", &cases);
  for (int i = 0; i < cases; i++) {
    scanf("%d%d", &P, &Q);
    printf("Scenario #%d:\n", i + 1);
    solve();
  }

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
}
