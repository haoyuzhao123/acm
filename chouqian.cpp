#include<cstdio>

using namespace std;

const int MAX_N = 50;

int main()
{
  //the number of the mod of set
  int n;
  //the number we want to sum to
  int m;
  //the array to store the set
  int k[MAX_N];
  scanf("%d%d", &n, &m);
  for (int i=0;i<n;i++){
    scanf("%d", (k+i));
  }
  //enumerate all the possible sums
  bool isSum = false;
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      for(int p=0;p<n;p++)
	for(int q=0;q<n;q++){
	  if(m == k[i]+k[j]+k[p]+k[q])
	    isSum = true;
	}

  if(isSum)
    printf("Yes");
  else
    printf("No");

  return 0;
}
