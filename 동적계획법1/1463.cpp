// 1로 만들기
// 3가지 연산을 거쳐서 1로 만들어야 하기 때문에
// 3가지 연산에 대해 검사해보고 가장 작은 경우를 저장한다
// 이전 경우에 최소값을 저장했기 때문에 가져와서 계산해도 된다

include <iostream>
#define MAX 1000001

using namespace std;

int n;
int dp[MAX];

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= n; i++)
    {
        dp[i] = dp[i-1]+1;

        if(i%3 == 0)
        {
            dp[i] = min(dp[i], dp[i/3]+1);
        }

        if(i%2 == 0)
        {
            dp[i] = min(dp[i], dp[i/2]+1);
        }
    }

    cout << dp[n] << endl;
    return;
}

int main()
{
    cin >> n;
    solve();
    return 0;
}
