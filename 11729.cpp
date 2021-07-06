// 하노이의 탑
// 재귀 문제 - 하노이의 탑에 대한 이해가 필요하다
// 옮기는 방식이 항상 일정하기 때문에 옮기는 횟수도 일정하다 (2^n - 1)
// start 시작지점, to 목표, by 거치는 지점
// start - to 로 옮기고
// start - by 로 옮긴다
// by - to 로 옮기는 것을 계속해서 반복하면 끝
// 작은 원반 n-1개를 start에서 by로 이동 후
// 큰 원반 n개를 start에서 to로 이동 시킨다고 생각하면 된다

#include <iostream>
using namespace std;

void hanoi(int num, int start, int to, int by)
{
    if(num == 1)
        printf("%d %d\n", start, to);
    else
    {
        hanoi(num-1, start, by, to);
        printf("%d %d\n", start, to);
        hanoi(num-1, by, to, start);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << (1<<n) - 1 << endl;
    hanoi(n, 1, 3, 2);
    return 0;
}
