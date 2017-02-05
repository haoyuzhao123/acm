//poj 2104
//k-th number

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//some constant
const int ST_SIZE = (1 <<18) - 1;
const int MAX_N = 100010;
const int MAX_M = 5010;

//the input
int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N];
vector<int> dat[ST_SIZE]; //segment-tree data

//the construction of the segment-tree
void init(int k, int l, int r) {
  if (r - l == 1) {
    dat[k].push_back(A[l]);
  }
  else {
    int m = (l + r) / 2;
    int lch = 2 * k + 1;
    int rch = 2 * k + 2;
    init(lch, l, m);
    init(rch, m, r);
    dat[k].resize(r - l);
    //using merge to construct the current node data
    merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(),
	  dat[k].begin());
  }
}

//compute # of numbers that less or equal to x in the interval
int query(int i, int j, int x, int k, int l, int r) {
  if (j <= l || i >= r) {
    return 0;
  }
  else if (i <= l && r <= j) {
    return upper_bound(dat[k].begin(), dat[k].end(), x) -
      dat[k].begin();
  }
  else {
    int lc = query(i, j, x, 2 * k + 1, l, (l + r) / 2);
    int rc = query(i, j, x, 2 * k + 2, (l + r) / 2, r);
    return lc + rc;
  }
}

void solve() {
  for (int i = 0; i < N; i++) {
    nums[i] = A[i];
  }
  sort(nums, nums + N);

  init(0, 0, N);

  for (int i = 0; i < M; i++) {
    int l = I[i] - 1;
    int r = J[i];
    int k = K[i];

    int lb = -1;
    int ub = N - 1;
    while (ub - lb > 1) {
      int md = (lb + ub) / 2;
      int c = query(l, r, nums[md], 0, 0, N);
      if (c >= k) {
	ub = md;
      }
      else {
	lb = md;
      }
    }
    printf("%d\n", nums[ub]);
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", A + i);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", I + i, J + i, K + i);
  }

  solve();

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif

  return 0;
}
