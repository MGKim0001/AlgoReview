// 나무자르기
// 최적화 문제를 결정 문제로 바꾸는 문제다
// 나무를 자를 수 있는 최대 높이를 구하는 문제에서
// 일정 높이의 나무를 잘랐을 때 원하는 길이를 얻을 수 있는지 구하는 문제로 바꾼다

#include <iostream>
#include <vector>

using namespace std;

long long cut(vector<long long> v, int n, int m, long long max)
{
    long long ans = 0;
    long long l = 1;
    long long h = max;21

    while(l <= h)
    {
        long long mid = (l+h)/2;

        int i;
        long long count = 0;
        for(i = 0; i < n; i++)
        {
            if(v[i] >= mid)
            {
                count += v[i] - mid;
            }
        }

        if(count >= m)
        {
            if(ans < mid)
            {
                ans = mid;
            }

            l = mid+1;
        }
        else
        {
            h = mid-1;
        }
    }

    return h;
}

int main()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> v(n);
    int i;
    long long max = -1;
    for(i = 0; i < n; i++)
    {
        cin >> v[i];

        if(max < v[i])
        {
            max = v[i];
        }
    }

    long long ans = cut(v, n, m, max);
    cout << ans << '\n';
    return 0;
}
