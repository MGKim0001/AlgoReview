// 유기농 배추
// dfs를 사용해서 몇개의 요소가 연결되어 있는지 확인한다

#include <iostream>

using namespace std;

int t, m, n, c;
int map[51][51];
int visited[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int dfs(int x, int y)
{
    if(visited[y][x]) return 0;
    if(!visited[y][x]) visited[y][x] = 1;

    int i;
    for(i = 0; i < 4; i++)
    {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if(nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx])
      {
        dfs(nx, ny);
      }
    }

    return 1;
}

int main()
{
  cin >> t;

  int i, j, x, y;
  for(i = 0; i < t; i++)
  {
    cin >> m >> n >> c;
    for(j = 0; j < c; j++)
    {
      cin >> x >> y;
      map[y][x] = 1;
      visited[y][x] = 0;
    }

    int l, k, ans = 0;
    for(l = 0; l < m; l++)
    {
      for(k = 0; k < n; k++)
      {
        if(map[k][l])
        {
            ans += dfs(l, k);
        }
      }
    }

    printf("%d\n", ans);
  }


  return 0;
}
