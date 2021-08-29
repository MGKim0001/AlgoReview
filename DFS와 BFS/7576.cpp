// 토마토
// bfs를 사용해 익은 토마토를 순차적으로 입력해준다

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001];
int cache[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
  cin >> m >> n;

  queue<pair<int, int>> q;
  int i, j, max = 0;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      cin >> map[i][j];

      if(map[i][j] == 1)
      {
        q.push(make_pair(i, j));
      }

      if(map[i][j] || map[i][j] == -1)
      {
        visited[i][j] = 1;
      }
      else
      {
        visited[i][j] = 0;
      }
    }
  }

  while(!q.empty())
  {
    pair<int, int> curr = q.front();
    q.pop();

    for(i = 0; i < 4; i++)
    {
      int ny = curr.first + dy[i];
      int nx = curr.second + dx[i];

      if(ny >= 0 && ny < n && nx >= 0 && nx < m && !map[ny][nx] && !visited[ny][nx])
      {
        visited[ny][nx] = 1;
        q.push(make_pair(ny, nx));

        cache[ny][nx] = cache[curr.first][curr.second] + 1;
        if(max < cache[ny][nx])
        {
            max = cache[ny][nx];
        }
      }
    }
  }

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      if(!visited[i][j])
      {
        max = -1;
      }
    }
  }

  cout << max << '\n';
  return 0;
}
