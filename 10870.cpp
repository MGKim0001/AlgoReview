// 피보나치 수열
// 재귀 문제 - 재귀 함수 점화식 F(n) = F(n-1) + F(n-2)
// 런타임 에러 1회, 컴파일 에러 1회, 오답 3회

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if(n <= 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n, fib;
    cin >> n;

    fib = fibonacci(n);
    cout << fib << endl;
    return 0;
}
