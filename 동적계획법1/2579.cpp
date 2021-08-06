// 계단 오르기
// 2가지 경우에 대해서 검사해야 한다
// 첫번째 경우는 지금 있는 계단에서 이전 계단을 밟지 않은 경우이고
// 두번째 경우는 지금 있는 계단에서 전전 계단을 밟지 않는 경우다
// 전전 계단을 밟지 않은 경우는 그 전의 계단을 더해줘야 하는데
// 이유는 3번째 전의 계단을 더해주지 않으면 게단을 2개 건너뛴 것이 되기 때문이다

#include <iostream>
#define MAX 301

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
    int i;
    for(i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        input[i] = e;
    }
    return;
}

void solve()
{
    int i;
    dp[0] = input[0];
    dp[1] = max(input[0] + input[1], input[1]);
    dp[2] = max(input[0] + input[2], input[1] + input[2]);

    for(i = 3; i < n; i++)
    {
        dp[i] = max(dp[i-2] + input[i], dp[i-3] + input[i-1] + input[i]);
    }

    cout << dp[n-1] << endl;
    return;
}

int main()
{
    cin >> n;
    init();
    solve();
    return 0;
}
