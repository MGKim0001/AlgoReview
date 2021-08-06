// LCS
// 단순하게 두 문자열을 비교하면서 같은 문자가 있으면 저장된 값은 1 증가시켜 준다

#include <iostream>
#include <string.h>
#define MAX 1001

using namespace std;

char s1[MAX];
char s2[MAX];
int len1, len2;
int dp[MAX][MAX];

int maximum(int a, int b)
{
    return a > b ? a : b;
}

void init()
{
    cin >> s1 >> s2;
    len1 = strlen(s1);
    len2 = strlen(s2);

    for(int i = 0; i <= len1; i++)
        for(int j = 0; j <= len2; j++)
            dp[i][j] = 0;
}

void solve()
{
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = maximum(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[len1][len2] << endl;
}

int main()
{
    init();
    solve();
    return 0;
}
