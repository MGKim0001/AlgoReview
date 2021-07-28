// 이항계수 2
// 똑같은 이항계수지만 범위가 넓기 때문에 동적계획법을 이용하여 구현한다
// 파스칼 삼각형을 이용하여 점화식을 세워야 한다
// dp[n][k] = dp[n-1][k-1] + dp[n-1][k]

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  int dp[n+1][k+1];

  int i, j;
  for(i = 1; i <= n; i++)
  {
    for(j = 0; j <= k; j++)
    {
      if(i == j || j == 0)
      {
        dp[i][j] = 1;
      }
      else
      {
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
      }
    }
  }

  cout << dp[n][k];

  return 0;
}
