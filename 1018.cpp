// 체스판 다시 칠하기
// 브루트 포스 문제 이기 때문에 모든 경우의 수를 구한다
// WB와 BW를 구하고 싶은 이상적인 체스보드로 저장한다
// 2중 for 문을 돌면서 체스판의 모든 경우의 수를 구한다

#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

string board[50];

string WB[8] = {
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW"
};

string BW[8] = {
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB",
        "BWBWBWBW",
        "WBWBWBWB"
};

int count_w(int x, int y)
{
    int res = 0;
    int i, j;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != WB[i][j])
                res += 1;
        }
    }

    return res;
}

int count_b(int x, int y)
{
    int res = 0;
    int i, j;

    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if(board[x+i][y+j] != BW[i][j])
                res += 1;
        }
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int i, j;
    for(i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int ans = 9999;
    for(i = 0; i+8 <= n; i++)
    {
        for(j = 0; j+8 <= m; j++)
        {
            int count = min(count_w(i, j), count_b(i, j));

            if(ans > count)
                ans = count;
        }
    }

    cout << ans << endl;
    return 0;
}
