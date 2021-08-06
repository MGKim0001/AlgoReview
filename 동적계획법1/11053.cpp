// 가장 긴 증가하는 부분 수열
// 현재 숫자 보다 작은 숫자의 갯수를 저장하는 식으로 해결한다

#include <iostream>
#define MAX 1001

using namespace std;

int n;
int dp[MAX];
int p[MAX];
int input[MAX];

int max(int a, int b)
{
    return a > b ? a : b;
}

void init()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        input[i] = e;
    }
}

void solve()
{
    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(input[i] > input[j] && dp[j]+1 > dp[i])
            {
                dp[i] = dp[j]+1;
            }
        }
    }

    int ans = 0;
    for(int m = 0; m < n; m++)
    {
        ans = max(ans, dp[m]);
    }
    cout << ans << endl;
}

int main()
{
    init();
    solve();
    return 0;
}
