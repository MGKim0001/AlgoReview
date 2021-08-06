// 전깃줄
// 이어진 전깃줄의 페어를 시작 부분 순으로 오름차순으로 정렬한 뒤
// 만약 현재 끝부분의 전깃줄이 뒤에 있는 끝부분의 전깃줄보다 앞에 있다면 갯수를 세어준다
// 다시말해 끝부분의 전깃줄이 겹치지 않은 갯수를 세어준다
// 그 중 가장 큰 값을 전깃줄의 총 갯수에서 빼주면 가장 적게 자를 수 있는 전깃줄의 갯수가 나온다

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int n;
vector<vector<int>> v;
int dp[MAX];

bool comp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void init()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;
        vector<int> in (2);
        in[0] = f;
        in[1] = s;
        v.push_back(in);
    }

    sort(v.begin(), v.end(), comp);
}

void solve()
{
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(dp[j]+1 > dp[i] && v[i][1] > v[j][1])
            {
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << n-ans << endl;
}

int main()
{
    init();
    solve();
    return 0;
}
