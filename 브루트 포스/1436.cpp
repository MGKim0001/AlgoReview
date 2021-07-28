// 영화감독 숌
// 브루트 포스 문제이기 때문에 구할 수 있는 모든 수를 구한다
// 0 부터 모든 숫자를 돌면서 666이 들어간 모든 경우의 수를 구한다
// 만약 n 번째 영화의 숫자가 구해지면 출력하고 종료한다

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int temp, count, flag, i;
    count = i = 0;
    while(++i)
    {
        temp = i, flag = 0;
        while(temp)
        {
            if(temp%1000 == 666)
                flag = 1;
            temp /= 10;
        }

        if(flag)
        {
            count++;
            if(count == n)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
