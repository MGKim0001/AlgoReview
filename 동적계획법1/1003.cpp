// 피보나치 함수
// 0와 1이 호출되는 수를 각각 저장한 뒤 출력한다

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> fibozero (100, 0);
vector<int> fiboone (100, 0);

int fibozc(int n)
{
    if(n == 0)
    {
        fibozero[n] = 1;
    }
    if(n == 1)
    {
        return 0;
    }
    if(fibozero[n] == 0)
    {
        fibozero[n] = fibozc(n-1) + fibozc(n-2);
    }
    return fibozero[n];
}

int fibooc(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        fiboone[n] = 1;
    }
    if(fiboone[n] == 0)
    {
        fiboone[n] = fibooc(n-1) + fibooc(n-2);
    }
    return fiboone[n];
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int e, res1, res2;
        cin >> e;
        res1 = fibozc(e);
        res2 = fibooc(e);
        cout << res1 << ' ' << res2 << endl;
    }
    return 0;
}
