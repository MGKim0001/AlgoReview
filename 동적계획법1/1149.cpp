// RGB 거리
// 집의 갯수가 많이 늘어나도 칠할 수 있는 색의 수는 항상 3이다
// 이 점을 이용하여 각 집에 각각의 색을 칠했을 경우의 최소 비용을 저장한다
// 마지막에 3가지 경우를 비교해서 출력한다

#include <iostream>

using namespace std;

int n;
int arr[1001][3];
int cache[1001][3];

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    cin >> n;

    int i, r, g, b;
    for(i = 0; i < n; i++)
    {
        cin >> r >> g >> b;
        arr[i][0] = r;
        arr[i][1] = g;
        arr[i][2] = b;
    }

    cache[0][0] = arr[0][0];
    cache[0][1] = arr[0][1];
    cache[0][2] = arr[0][2];

    for(i = 1; i < n; i++)
    {
        cache[i][0] = min(cache[i-1][1], cache[i-1][2]) + arr[i][0];
        cache[i][1] = min(cache[i-1][0], cache[i-1][2]) + arr[i][1];
        cache[i][2] = min(cache[i-1][0], cache[i-1][1]) + arr[i][2];
    }

    int result = 123456789;
    for(i = 0; i < 3; i++)
    {
        if(result > cache[n-1][i])
            result = cache[n-1][i];
    }

    cout << result << endl;
    return 0;
}
