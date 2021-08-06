// N과 M(4)
// 수열 내부 요소가 중복될 수 없기 때문에 조합을 사용하여 풀었디

#include <iostream>
#include <vector>
using namespace std;

vector<int> pvc;
int n, m;

void dfc(int next)
{
    if(pvc.size() == m)
    {
        for(auto a : pvc)
            cout << a << ' ';
        cout << '\n';
        return;
    }

    for(int i = next; i <= n; i++)
    {
        pvc.push_back(i);
        dfc(i);
        pvc.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    dfc(1);
    return 0;
}
