// 스타트와 링크
// dfs를 사용해서 각 팀의 분배를 노드로 하는 트리를 만들어 해결한다
// 스타트와 링크 팀을 따로 저장해서 계산하는 부분을 파악하는 것이 중요했다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, minimum = 123456789;
vector<int> start;
vector<int> link;
vector<vector<int>> scores (20, vector<int> (20, 0));

void input()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int e;
            cin >> e;
            scores[i][j] = e;
        }
    }

    return;
}

int calc()
{
    int result = 0;
    int start_team = 0, link_team = 0;

    int i, j;
    for(i = 0; i < start.size(); i++)
    {
        for(j = i+1; j < start.size(); j++)
        {
            int f = start[i];
            int s = start[j];
            start_team += scores[f][s] + scores[s][f];
        }
    }

    for(i = 0; i < link.size(); i++)
    {
        for(j = i+1; j < link.size(); j++)
        {
            int f = link[i];
            int s = link[j];
            link_team += scores[f][s] + scores[s][f];
        }
    }

    result = abs(start_team - link_team);
    return result;
}

void dfs(int depth)
{
    if(depth == n)
    {
        if(start.size() == n/2 && link.size() == n/2)
        {
            int result = calc();

            if(result < minimum)
                minimum = result;
        }
        return;
    }

    start.push_back(depth);
    dfs(depth+1);
    start.pop_back();

    link.push_back(depth);
    dfs(depth+1);
    link.pop_back();
}

int main()
{
    input();
    dfs(0);
    cout << minimum << endl;
    return 0;
}
