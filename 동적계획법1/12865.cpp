// 평범한 배낭
// 냅색 문제로 두가지 경우로 나뉜다
// 첫번째는 물건을 가져가지 않는 경우고
// 두번째는 물건을 가져가는 경우다
// 물건을 가져가는 경우에는 현재 물건의 무게를 뺀 무게에 저장되어 있는 값에
// 현재 물건의 가치를 더해서 그 값이 원래 저장되어 있던 값보다 큰지 비교한다

#include <iostream>
#define MAXW 100001
#define MAXV 1001

using namespace std;

int n, k;
int dp[101][MAXW];
int weights[MAXW];
int values[MAXV];

void init()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int w, v;
        cin >> w >> v;
        weights[i] = w;
        values[i] = v;
    }
}

void solve()
{
    int i, j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= k; j++)
        {
            if(j - weights[i] < 0)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i]] + values[i]);
            }
        }
    }

    cout << dp[n][k] << endl;
}

int main()
{
    init();
    solve();
    return 0;
}
