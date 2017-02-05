//poj 3368
//frequent values

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
const int MAX_Q = 100000;
const int ST_SIZE = (1 << 18) - 1;

//inputs
int N, Q;
int A[MAX_N];
int I[MAX_Q], J[MAX_Q];

//segment-tree data
int most[ST_SIZE];
int left[ST_SIZE];
int right[ST_SIZE];

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

//the function to construct the segment-tree
//k is the number of the cell, l and r means interval [l,r)
void init(int k, int l, int r) {
  if (r - l == 1) {
    most[k] = 1;
    left[k] = 1;
    right[k] = 1;
    return;
  }
  else {
    int chl = 2 * k + 1;
    int chr = 2 * k + 2;
    int m = (l + r) / 2;
    init(chl, l, m);
    init(chr, m, r);
    left[k] = upper_bound(A + l, A + r, A[l]) - A - l;
    right[k] = A + r - lower_bound(A + l, A + r, A[r - 1]);
    most[k] = max(most[chl], most[chr]);
    if (A[m - 1] == A[m]) {
      most[k] = max(most[k], right[chl] + left[chr]);
    }
  }
}

//the function to query the most frequent
//value in interval [i, j)
int query(int i, int j, int k, int l, int r) {
  if (r <= i || l >= j) {
    return 0;
  }
  else if (l >= i && r <= j) {
    return most[k];
  }
  else {
    int m = (l + r) / 2;
    int chl = 2 * k + 1;
    int chr = 2 * k + 2;
    int a = query(i, j, chl, l, m);
    int b = query(i, j, chr, m, r);
    int res = max(a, b);
    if (i <= m-1 && m < j && A[m - 1] == A[m]) {
      res = max(res, min(right[chl], m - i) + min(left[chr], j - m));
    }
    return res;
  }
}

void solve() {
  init(0, 0, N);
  for (int i = 0; i < Q; i++) {
    int l = I[i] - 1;
    int r = J[i];
    int res = query(l, r, 0, 0, N);
    printf("%d\n", res);
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  while (true) {
    //the input part
    scanf("%d", &N);
    if (N == 0)
      break;
    scanf("%d", &Q);
    for (int i = 0; i < N; i++) {
      scanf("%d", A + i);
    }
    for (int i = 0; i < Q; i++) {
      scanf("%d%d", I + i, J + i);
    }

    //the main solution part
    solve();
  }

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif
  
  return 0;
}
