// 행렬 곱셈 순서
// 행렬의 곱셈을 앞뒤로만 가능하기 때문에 점화식을 세울 수 있다
// dp[i][j] = dp[i][k] + dp[k+1][j]
// 부분합을 사용하지 않기 때문에 Knuth optimizaiton은 사용할 수 없다

// 완전히 같은 풀이를 사용해 풀었다고 해도 전역변수의 선언여부나 변수명을 바꾸는 것 만으로도
// 문제가 틀렸다고 출력해버리기 때문에 주의가 필요하다
// 풀이는 금방 떠올렸지만 그 외적인 것들에 더 많이 시간이 들어갔다

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 1000000000

using namespace std;

int main()
{
  int n;
  cin >> n;

  int dp[501][501];
  int matrix[501][2];
  for(int i = 1; i <= n; i++)
  {
    int r, c;
    cin >> r >> c;

    matrix[i][0] = r;
    matrix[i][1] = c;
  }

  for(int i = 1; i < n; i++)
  {
    for(int j = 1; i+j <= n; j++)
    {
      dp[j][i+j] = INF;

      for(int k = j; k <= i+j; k++)
      {
          int last_cost = matrix[j][0] * matrix[k][1] * matrix[i+j][1];
          dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + last_cost);
      }
    }
  }

  cout << dp[1][n];
  return 0;
}
