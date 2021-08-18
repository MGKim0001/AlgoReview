// 앱
// 메모리 용량, 메모리 가격이 주어지고 구해야하는 값은 최소가격이다
// 평범하게 생각하면 가격순으로 정렬하고 원하는 메모리가 나올 때까지 메모리를 더해가면 된다
// 동적계획법을 사용하면 메모리 가격 별로 얻을 수 있는 최대 메모리 용량을 구한다

#include <iostream>

using namespace std;

int n, m;
int mems[101];
int costs[101];
int dp[10001];

int main()
{
  cin >> n >> m;

  int i, j;
  for(i = 0; i < n; i++)
  {
    cin >> mems[i];
  }
  for(i = 0; i < n; i++)
  {
    cin >> costs[i];
  }

  for(i = 0; i < n; i++)
  {
    for(j = 10000; j >= costs[i]; j--)
    {
      dp[j] = max(dp[j], dp[j - costs[i]] + mems[i]);
    }
  }

  for(i = 0; i < 10001; i++)
  {
    if(dp[i] >= m)
    {
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}
