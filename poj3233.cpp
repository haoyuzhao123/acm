//poj3233
//Matrix power series

#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

int M;

mat mul(mat & A, mat & B) {
  mat C(A.size(), vec(B[0].size()));

  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B[0].size(); j++) {
      for (int k = 0; k < B.size(); k++) {
	C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
      }
    }
  }

  return C;
}

mat pow(mat A, ll N) {
  mat B(A.size(), vec(A[0].size()));
  for (int i = 0; i < A.size(); i++) {
    B[i][i] = 1;
  }

  while (N > 0) {
    if (N & 1) {
      B = mul(A, B);
    }
    A = mul(A, A);
    N = N >> 1;
  }

  return B;
}

int n;
ll k;

void solve(mat A) {
  
  mat B(n * 2, vec(n * 2));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      B[i][j] = A[i][j];
    }
    B[i + n][i] = 1;
    B[i + n][i + n] = 1;
  }
  
  B = pow(B, k + 1);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a = B[i + n][j] % M;
      if (i == j) {
	a = (a + M - 1) % M;
      }
      printf("%d%c", a, (j + 1) == n ? '\n' : ' ');
    }
  }
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  scanf("%d%lld%d", &n, &k, &M);
  mat A(n, vec(n));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &(A[i][j]));
    }
  }


  solve(A);

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif

  return 0;
}
