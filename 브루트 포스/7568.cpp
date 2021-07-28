// 덩치
// 브루트 포스 문제
// 주어진 입력을 모두 비교해 본다
// res를 초기화 하는 부분에서 에러가 있었다.
// int res[n] = {1,};

#include <iostream>
using namespace std;

int main()
{
    int n, i, j;
    cin >> n;

    int height[200], weight[200];
    int res[n] = {0,};
    for(i = 0; i < n; i++)
    {
        cin >> weight[i] >> height[i];
    }

    for(i = 0; i < n; i++)
    {
        res[i] = 1;
        for(j = 0; j < n; j++)
        {
            if(i==j) continue;
            if(height[i] < height[j] && weight[i] < weight[j])
            {
                res[i] += 1;
            }
        }
    }

    for(i = 0; i < n; i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
