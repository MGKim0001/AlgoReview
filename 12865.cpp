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
