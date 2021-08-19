// DFS와 BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, v;
int graph[1001][10001];
int visited[1001];

void bfs(int begin)
{
  queue<int> q;
  q.push(begin);

  int i;
  while(!q.empty())
  {
    int curr = q.front();
    q.pop();

    cout << curr << ' ';
    visited[curr] = 1;

    for(i = 1; i <= n; i++)
    {
      if(!visited[i] && (graph[curr][i] || graph[i][curr]))
      {
        visited[i] = 1;
        q.push(i);
      }
    }
  }
}

void dfs(int curr)
{
  visited[curr] = 1;
  cout << curr << ' ';

  int i;
  for(i = 1; i <= n; i++)
  {
    if(!visited[i] && (graph[curr][i] || graph[i][curr]))
    {
      visited[i] = 1;
      dfs(i);
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> v;

  int i, j, b, e;
  for(i = 0; i < m; i++)
  {
    cin >> b >> e;
    graph[b][e] = 1;
  }

  dfs(v);
  for(i = 1; i <= n; i++)
  {
    visited[i] = 0;
  }
  cout << '\n';

  bfs(v);

  return 0;
}
