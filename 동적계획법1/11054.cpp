// 가장 긴 바이토닉 부분 수열
// 가장 긴 증가하는 부분 수열을 앞에서 부터 하나 만들고 뒤에서 부터 하나 만든 뒤
// 가운데에서 두 값의 합이 가장 커지는 부분을 구한다

#include <iostream>
#define MAX 1001

using namespace std;

int n;
int input[MAX];
int dpf[MAX];
int dpb[MAX+1];
int dp[MAX];

int max(int a, int b)
{
    return a > b ? a : b;
}

void init()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int e;
        cin >> e;
        input[i] = e;
    }

}

void solve()
{
    dpf[0] = 0;
    dpb[MAX+1] = 0;

    for(int i = 1; i <= n; i++)
    {
        dpf[i] = 1;
        dpb[n-i+1] = 1;
        for(int j = 1; j < i; j++)
        {
            if(input[j] < input[i] && dpf[j]+1 > dpf[i])
            {
                dpf[i] = dpf[j]+1;
            }
            if(input[n-j+1] < input[n-i+1] && dpb[n-j+1]+1 > dpb[n-i+1])
            {
                dpb[n-i+1] = dpb[n-j+1]+1;
            }
        }
    }

    int ans = 0;
    for(int m = 1; m <= n; m++)
    {
        dp[m] = dpf[m] + dpb[m];
        ans = max(dp[m], ans);
    }
    ans--;
    cout << ans << endl;

}

int main()
{
    init();
    solve();
    return 0;
}
