// 연속합
// 입력된 수를 계속해서 더해가면서 가장 큰 값을 출력한다

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, i;
    int ans = 0;

    cin >> n;
    int input[n];
    int dp[n];

    for(i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        input[i] = e;
    }

    dp[0] = input[0];
    ans = dp[0];

    for(i = 1; i < n; i++)
    {
        dp[i] = max(dp[i-1]+input[i], input[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
