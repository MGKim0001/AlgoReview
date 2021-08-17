// 내리막 길
// 기본적으로 dfs를 사용해 경로를 탐색하지만
// 이미 탐색된 경로일 경우 저장된 값만 반환한다

#include <iostream>
#include <stack>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dp[501][501];
int input[501][501];
int m, n;

int dfs(int x, int y)
{
  if(x == n && y == m) return 1;

  if(dp[y][x] == -1)
  {
    dp[y][x] = 0;
    int i;
    for(i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx > 0 && nx <= n && ny > 0 && ny <= m && input[ny][nx] < input[y][x])
      {
        dp[y][x] += dfs(nx, ny);
      }
    }
  }

  return dp[y][x];
}

int main()
{
  cin >> m >> n;

  int i, j;
  for(i = 1; i <= m; i++)
  {
    for(j = 1; j <= n; j++)
    {
        cin >> input[i][j];
        dp[i][j] = -1;
    }
  }

  int ans = dfs(1, 1);

  cout << ans;

  return 0;
}
