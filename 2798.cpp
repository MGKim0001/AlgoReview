// 블랙잭
// 브루트 포스 문제
// 브루트 포스 문제이기 때문에 3장의 카드를 뽑을 수 있는 모든 경우의 수를
// 3중 for 문으로 구하면 된다

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int ans = -1;
    int nums[101];
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int x = j+1; x < n; x++)
            {
                int num = nums[i] + nums[j] + nums[x];
                if(num <= m && ans <= num)
                {
                    ans = num;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
