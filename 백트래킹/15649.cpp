// N과 M(1)
// 수열 내부의 순서는 상관없기 때문에 순열 방식을 사용하여 풀었다

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> permu;
bool visit[10];

void permutation()
{
    if(permu.size() == m)
    {
        for(auto a : permu)
        {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!visit[i])
        {
            visit[i] = true;
            permu.push_back(i);
            permutation();
            permu.pop_back();
            visit[i] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    permutation();
    return 0;
}
