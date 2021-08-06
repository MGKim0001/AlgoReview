// N-Queen
// 퀸을 서로 공격하지 않게 놓을 수 있는 모든 방법을 찾는 문제다
// 재귀를 사용해서 이전에 놓았던 퀸의 위치를 저장하고 비교해서 모든 경우의 수를 구한다

#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

bool check(int level)
{
    for(int i = 0; i < level; i++)
        if(col[i] == col[level] || abs(col[level] - col[i]) == level - i)
            return false;
    return true;
}

void nqueen(int x)
{
    if(x == N)
        total++;
    else
    {
        for(int i = 0; i < N; i++)
        {
            col[x] = i;

            if(check(x))
                nqueen(x+1);
        }
    }
}
int main() {
    cin >> N;
    nqueen(0);
    cout << total << endl;
    return 0;
}
