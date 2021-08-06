// 파도반 수열
// 수열이기 때문에 수열 안에 있는 일정한 규칙을 찾고 그 규칙에 따라 저장하면 된다

#include <iostream>
#define MAX 101

using namespace std;

int n;
long long cache[MAX];

void padoban(int m)
{
    cache[1] = 1;
    cache[2] = 1;
    cache[3] = 1;

    if(!cache[m])
    {
        for(int i = 4; i <= m; i++)
        {
            cache[i] = cache[i-2] + cache[i-3];
        }
    }

    cout << cache[m] << endl;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        padoban(e);
    }
    return 0;
}
