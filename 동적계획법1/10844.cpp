// 쉬운 계단 수
// 각 숫자에 대해 앞 뒤로 1차이가 나는 숫자가 오는 경우를 모두 구해 더한다

#include <iostream>
#define DIV 1000000000

using namespace std;

int n;
long long dp[101][10];

void solve()
{
    int i, j;

    dp[1][0] = 0;
    for(i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    for(i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][9] = dp[i-1][8];

        for(j = 1; j < 9; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%DIV;
        }
    }

    long long result = 0;
    for(i = 0; i <= 9; i++)
    {
        result += dp[n][i];
    }
    result = result%DIV;
    cout << result << endl;
}

int main()
{
    cin >> n;
    solve();
    return 0;
}
