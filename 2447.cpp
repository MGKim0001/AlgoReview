// 별찍기 10
// 재귀 문제 - n은 정사각형의 크기 (n*n)
// 2차 for 문을 돌면서 내부의 모든 좌표 (i,j)를 탐색
// 내부에서 재귀함수를 다시 돌려준다
// 사각형의 말단 부분 (n == 1)인 경우 에만 출력하고 나머지는 n/3만 반복해준다
// n/3은 (i,j)가 몇 번째 사각형에 들어가 있는지 확인해 준다
// 수학적인 계산이 필요한 문제

#include <iostream>
using namespace std;

void star(int n, int i, int j)
{
    if((i/n)%3 == 1 && (j/n)%3 == 1){
        cout << ' ';
    }
    else
    {
        if(n/3 == 0)
            cout << '*';
        else
            star(n/3, i, j);
    }
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            star(n, i, j);
        }
        cout << '\n';
    }

    return 0;
}
