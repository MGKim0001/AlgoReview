// 정수 삼각형
// 각 경로에서 어느 값을 택해야 가장 큰 값이 나오는지 확인한 뒤 저장한다
// 마지막에 삼각형의 바닥 부분에서 어느 값이 가장 큰지 출력한다

#include <iostream>
#define MAX 5001

using namespace std;

int n;
int dp[MAX][MAX];

int max(int a, int b)
{
    return a > b ? a : b;
}

void init()
{
    int i, j, idx = 1;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < idx; j++)
        {
            int e;
            cin >> e;
            dp[i][j] = e;
        }
        idx++;
    }
    return;
}

void solve()
{
    int i, j, idx = 2;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < idx; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j];
            }
            else if(j == idx-1)
            {
                dp[i][j] = dp[i-1][j-1] + dp[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + dp[i][j];
            }
        }
        idx++;
    }

    int result = 0;
    for(i = 0; i < n; i++)
    {
        if(result < dp[n-1][i])
        {
            result = dp[n-1][i];
        }
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
