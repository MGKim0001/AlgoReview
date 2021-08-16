// 행렬 곱셈 순서
// 행렬의 곱셈을 앞뒤로만 가능하기 때문에 점화식을 세울 수 있다
// dp[i][j] = dp[i][k] + dp[k+1][j]
// 전역변수를 사용해서 풀었어야 했던 문제다
// 전역변수로 선언하지 않았을 경우 문제를 여러번 푸는 과정에서
// 메모리에 덮어씌워지는 값에 문제가 생기는 듯 하다

#include <iostream>
#include <vector>

using namespace std;

int n, r, c;
int dp[501][501];
vector<pair<int, int>> v(501);

int main()
{
  cin >> n;

  int i;
  for(i = 1; i <= n; i++)
  {
    cin >> r >> c;

    v[i] = make_pair(r, c);
  }

  int size, start, mid;
  for(size = 1; size < n; size++)
  {
    for(start = 1; start+size <= n; start++)
    {
      int end = start+size;
      dp[start][end] = 987654321;

      for(mid = start; mid <= end; mid++)
      {
          int last_cost = v[start].first * v[mid].second * v[end].second;

          dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid+1][end] + last_cost);
      }
    }
  }
  cout << dp[1][n];

  return 0;
}
