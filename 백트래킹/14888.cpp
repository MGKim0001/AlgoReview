// 연산자 끼워넣기
// dfs를 사용하여 연산자를 노드로 하는 트리를 만들어 해결했다

#include <iostream>
#include <vector>

#define MAX 123456789

using namespace std;

vector<int> nums;
vector<int> syms_list;
vector<int> visits;
int n, total_syms = 0, maximum = -9999, minimum = MAX;

void input()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        nums.push_back(e);
    }

    for(int j = 0; j < 4; j++)
    {
        int s;
        cin >> s;
        total_syms += s;

        for(int m = 0; m < s; m++)
        {
            syms_list.push_back(j);
        }
    }

    for(int i = 0; i < total_syms; i++)
        visits.push_back(0);
}

void dfs(int v, int depth, int res, int len)
{
    int result = 0;

    if(len == total_syms)
    {
        if(res > maximum)
            maximum = res;
        if(res < minimum)
            minimum = res;
    }
    else
    {
        for(int i = 0; i < total_syms; i++)
        {
            if(!visits[i])
            {
                if(syms_list[i] == 0)
                    result = res + nums[depth];
                else if(syms_list[i] == 1)
                    result = res - nums[depth];
                else if(syms_list[i] == 2)
                    result = res * nums[depth];
                else if(syms_list[i] == 3)
                    result = res / nums[depth];

                visits[i] = 1;
                dfs(i, depth+1, result, len+1);
            }
        }
    }

    visits[v] = 0;
}

int main()
{
    input();
    dfs(0, 1, nums[0], 0);
    cout << maximum << endl;
    cout << minimum << endl;
    return 0;
}
