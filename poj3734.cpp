//poj3734
//Blocks

#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;

const int M = 10007;

//mat[i][j] is the element at the i th row and j th column
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

mat pow(mat & A, ll n) {
  mat B(A.size(), vec(A.size()));
  for (int i = 0; i < A.size(); i++) {
    B[i][i] = 1;
  }

  while (n > 0) {
    if (n & 1) {
      B = mul(A, B);
    }
    A = mul(A, A);
    n = (n >> 1);
  }

  return B;
}

ll N;

void solve() {
  mat A(3, vec(3));
  A[0][0] = 2;
  A[0][1] = 1;
  A[0][2] = 0;
  A[1][0] = 2;
  A[1][1] = 2;
  A[1][2] = 2;
  A[2][0] = 0;
  A[2][1] = 1;
  A[2][2] = 2;

  A = pow(A, N);

  printf("%d\n", A[0][0]);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    scanf("%lld", &N);
    solve();
  }

  #ifndef ONLINE_JUDGE
  fclose(stdin);
  fclose(stdout);
  #endif

  return 0;
}
