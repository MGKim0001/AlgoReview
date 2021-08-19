// 웜바이러스
// 그래프가 연결되어 있는지 확인하는 문제다
// dfs를 돌면서 연결된 요소를 확인한다

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int graph[101][101];
int visited[101];
int infected;

void bfs()
{
  queue<int> q;
  q.push(1);

  int i;
  while(!q.empty())
  {
    int curr = q.front();
    q.pop();

    visited[curr] = 1;

    for(i = 1; i <= n; i++)
    {
      if(!visited[i] && (graph[curr][i] || graph[i][curr]))
      {
        visited[i] = 1;
        infected += 1;
        q.push(i);
      }
    }
  }
}

int main()
{
  infected = 0;
  cin >> n >> m;

  int i, b, e;
  for(i = 0; i < m; i++)
  {
    cin >> b >> e;
    graph[b][e] = 1;
  }

  bfs();
  cout << infected << '\n';
  return 0;
}
