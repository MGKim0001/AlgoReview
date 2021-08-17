// 팰린드롬?
// dp[s][e]에 s부터 e가 팰린드롬인지 저장한다
// 사이즈가 1과 2인 것 부터 미리 구해놓고
// 사이즈를 하나씩 증가시키면서 저장값을 구한다
// 이렇게 구하면 모든 팰린드롬 값을 구할 필요 없이
// 저장된 값을 사용해서 구할 수 있게 된다.

#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001];
int n, m, s, e;

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  int i, j;
  for(i = 1; i <= n; i++)
  {
    cin >> arr[i];
    dp[i][i] = 1;
  }

  for(i = 1; i <= n; i++)
  {
    if(arr[i] == arr[i+1])
    {
      dp[i][i+1] = 1;
    }
  }

  int start, size;
  for(size = 2; size <= n; size++)
  {
    for(start = 1; start+size <= n; start++)
    {
      int end = start+size;
      if(arr[start] == arr[end] && dp[start+1][end-1])
      {
        dp[start][end] = 1;
      }
    }
  }

  cin >> m;
  for(i = 0; i < m; i++)
  {
    cin >> s >> e;
    int ans = dp[s][e];
    printf("%d\n", ans);
  }

  return 0;
}
