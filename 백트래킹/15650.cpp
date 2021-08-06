// N과 M(2)
// 수열 내부의 순서가 오름차순이기 때문에 조합 방식으로 풀었다

#include <iostream>
using namespace std;

int n, m;
int cArr[9] = {0,};
bool visit[9];

void combination(int depth, int next)
{
    if(depth == m)
    {
        for(int a = 0; a < m; a++)
            cout << cArr[a] << ' ';
        cout << '\n';
        return;
    }

    for(int i = next; i <= n; i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            cArr[depth] = i;
            combination(depth+1, i+1);
            visit[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    combination(0, 1);
    return 0;
}
