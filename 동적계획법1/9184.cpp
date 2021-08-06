// 신나는 함수 실행
// 함수가 사용되는 각 경우별로 저장한 뒤 출력한다

#include <iostream>
#include <vector>

using namespace std;

int res[21][21][21];

void init()
{
    for(int i = 0; i < 21; i++)
    {
        for(int j = 0; j < 21; j++)
        {
            for(int m = 0; m < 21; m++)
            {
                res[i][j][m] = 0;
            }
        }
    }
}

int w(int a, int b, int c)
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20)
    {
        return w(20, 20, 20);
    }
    else if(a < b && b < c)
    {
        if(!res[a][b][c-1])
            res[a][b][c-1] = w(a, b, c-1);
        if(!res[a][b-1][c-1])
            res[a][b-1][c-1] = w(a, b-1, c-1);
        if(!res[a][b-1][c])
            res[a][b-1][c] = w(a, b-1, c);

        if(!res[a][b][c])
            res[a][b][c] = res[a][b][c-1] + res[a][b-1][c-1] - res[a][b-1][c];
    }
    else
    {
        if(!res[a-1][b][c])
            res[a-1][b][c] = w(a-1, b, c);
        if(!res[a-1][b-1][c])
            res[a-1][b-1][c] = w(a-1, b-1, c);
        if(!res[a-1][b][c-1])
            res[a-1][b][c-1] = w(a-1, b, c-1);
        if(!res[a-1][b-1][c-1])
            res[a-1][b-1][c-1] = w(a-1, b-1, c-1);

        if(!res[a][b][c])
            res[a][b][c] = res[a-1][b][c] + res[a-1][b-1][c] + res[a-1][b][c-1] - res[a-1][b-1][c-1];
    }

    return res[a][b][c];
}

int main()
{
    int a = 0, b = 0, c = 0;
    init();

    while(1)
    {
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1)
            break;

        int result;
        result = w(a, b, c);

        cout << "w(" << a << ", " << b << ", " << c << ") = " << result << endl;
    }

    return 0;
}
