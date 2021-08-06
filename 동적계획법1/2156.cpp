// 포도주 시식
// 계단 오르기와 비슷한 문제로 포도주를 3잔 연속 마시지 못하는 규칙을 위해서
// 전전 포도주를 마시지 않은 경우와 이전 포도주를 마시지 않은 경우를 세 주어야 한다
// 포도주를 2잔 연속으로 마시지 않는 경우도 추가해 주어야 한다
// 첫번째 경우 마심 마심 안마심 마심
// 두번째 경우 마심 안마심 마심
// 세번째 경우 안마심 안마심

#include <iostream>
#define MAX 10003
using namespace std;

int n;
int dp[MAX];
int input[MAX];

int max(int a, int b)
{
    return a > b ? a : b;
}

void init()
{
    for(int i = 3; i < n+3; i++)
    {
        int e;
        cin >> e;
        input[i] = e;
    }
}

void solve()
{
    int result = 0;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;

    for(int i = 3; i < n+3; i++)
    {
        dp[i] = max(input[i] + input[i-1] + dp[i-3], input[i] + dp[i-2]);
        dp[i] = max(dp[i-1], dp[i]);
        result = max(result, dp[i]);
    }

    cout << result << endl;
    return;
}

int main()
{
    cin >> n;
    init();
    solve();
    return 0;
}
