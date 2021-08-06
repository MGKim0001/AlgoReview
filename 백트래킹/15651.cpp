// N과 M(3)
// 수열 내부요소가 중복될 수 있기 때문에 가능한 조합을 모두 찾았다

#include <iostream>
#include <vector>
using namespace std;

vector<int> pvc;
int n, m;

void permutation()
{
    if(pvc.size() == m)
    {
        for(auto a : pvc)
            cout << a << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        pvc.push_back(i);
        permutation();
        pvc.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    permutation();
    return 0;
}
