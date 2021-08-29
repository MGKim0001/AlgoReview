// 토마토
// 2차원 토마토 문제를 3차원으로 옮긴 문제다

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n, h;
int map[101][101][101];
int visited[101][101][101];
int cache[101][101][101];

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, -1, 0, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
  cin >> m >> n >> h;

  queue<vector<int>> q;
  int i, j, k, max = 0;
  for(k = 0; k < h; k++)
  {
    for(i = 0; i < n; i++)
    {
      for(j = 0; j < m; j++)
      {
        cin >> map[i][j][k];

        if(map[i][j][k] == 1)
        {
          vector<int> v(3);
          v[0] = i;
          v[1] = j;
          v[2] = k;
          q.push(v);
        }

        if(map[i][j][k] || map[i][j][k] == -1)
        {
          visited[i][j][k] = 1;
        }
      }
    }
  }

  while(!q.empty())
  {
    vector<int> curr = q.front();
    q.pop();

    for(i = 0; i < 6; i++)
    {
      int ny = curr[0] + dy[i];
      int nx = curr[1] + dx[i];
      int nz = curr[2] + dz[i];

      if(ny >= 0 && ny < n && nx >= 0 && nx < m && nz >= 0 && nz < h
          && !map[ny][nx][nz] && !visited[ny][nx][nz])
      {
        vector<int> nv(3);
        nv[0] = ny;
        nv[1] = nx;
        nv[2] = nz;

        visited[ny][nx][nz] = 1;
        q.push(nv);

        cache[ny][nx][nz] = cache[curr[0]][curr[1]][curr[2]] + 1;
        if(max < cache[ny][nx][nz])
        {
            max = cache[ny][nx][nz];
        }
      }
    }
  }

  for(k = 0; k < h; k++)
  {
    for(i = 0; i < n; i++)
    {
      for(j = 0; j < m; j++)
      {
        if(!visited[i][j][k])
        {
          max = -1;
        }
      }
    }
  }

  cout << max << '\n';
  return 0;
}
