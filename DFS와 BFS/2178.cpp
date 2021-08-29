// 미로 탐색
// bfs를 사용해서 끝에 도달하는지 확인하면 된다

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[101][101];
int visited[101][101];
int cache[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
  cin >> n >> m;

  int i, j, count = 0;
  string e;
  queue<pair<int, int>> q;

  for(i = 0; i < n; i++)
  {
    cin >> e;
    j = 0;

    for(char c : e)
    {
      int num = c - '\0';
      num -= 48;

      map[i][j] = num;

      j += 1;
    }
  }

  q.push(make_pair(0, 0));
  cache[0][0] = 1;
  while(!q.empty())
  {
    pair<int, int> curr = q.front();
    q.pop();

    for(i = 0; i < 4; i++)
    {
      int ny = curr.first + dy[i];
      int nx = curr.second + dx[i];

      if(ny >= 0 && ny < n && nx >= 0 && nx < m && map[ny][nx] && !visited[ny][nx])
      {
        cache[ny][nx] = cache[curr.first][curr.second] + 1;
        visited[ny][nx] = 1;
        q.push(make_pair(ny, nx));
      }
    }
  }

  printf("%d\n", cache[n-1][m-1]);
  return 0;
}
