// 펙토리얼
// 재귀 문제, 재귀 함수를 n번 부르는 것으로 해결
// 시간 초과 1회 - line10) n == 1에서 n <= 1로 바꾸는 것으로 해결
// 해설) n이 0인 경우를 해결하지 않았기 때문에 재귀 함수가 종료되지 않음

#include <iostream>
using namespace std;

int factorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }

    int fac = n * factorial(n-1);
    return fac;
}

int main()
{
    int n, ret;
    cin >> n;
    ret = factorial(n);
    cout << ret << endl;
    return 0;
}
