// 다리놓기
// 조합문제이기 때문에 동적계획법을 이용하여 구현한다
// 파스칼의 삼각형을 이용하여 점화식을 구현한다
// dp[n][j] = dp[n-1][k-1] + dp[n-1][k]

#include <iostream>
#include <vector>
#define N_MAX 31
#define K_MAX 31

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> vv(n);
  vector<int> ans(n);
  int dp[N_MAX][K_MAX];
  int i, j;
  for(i = 0; i < n; i++)
  {
    int n1, n2;
    cin >> n1 >> n2;
    vv[i] = make_pair(n1, n2);
  }

  for(i = 1; i < N_MAX; i++)
  {
    for(j = 0; j < K_MAX; j++)
    {
      if(i == j || j == 0)
      {
        dp[i][j] = 1;
      }
      else
      {
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
      }
    }
  }

  for(i = 0; i < n; i++)
  {
    ans[i] = dp[vv[i].second][vv[i].first];
    cout << ans[i] << endl;
  }

  return 0;
}
