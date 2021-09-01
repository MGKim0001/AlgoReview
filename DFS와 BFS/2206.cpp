// 벽 부수고 이동하기
// 기본적인 bfs 문제지만 막혀있는 칸을 1칸 무시할 수 있다는 점이 다르다

#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001][2];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

int bfs()
{
  queue<pair<pair<int, int>, pair<int, int>>> q;
  q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
  visited[0][0][0] = 1;

  while(!q.empty())
  {
    pair<pair<int, int>, pair<int, int>> curr = q.front();
    q.pop();

    int cr = curr.first.first;
    int cc = curr.first.second;
    int wall = curr.second.first;
    int count = curr.second.second;

    if(cr >= n-1 && cc >= m-1) return count;

    int i;
    for(i = 0; i < 4; i++)
    {
      int nr = cr + dr[i];
      int nc = cc + dc[i];

      if(nr >= 0 && nr < n && nc >= 0 && nc < m)
      {
        if(map[nr][nc] && wall == 0)
        {
          visited[nr][nc][wall+1] = 1;
          q.push(make_pair(make_pair(nr, nc), make_pair(wall+1, count+1)));
        }
        else if(!map[nr][nc] && !visited[nr][nc][wall])
        {
          visited[nr][nc][wall] = 1;
          q.push(make_pair(make_pair(nr, nc), make_pair(wall, count+1)));
        }
      }
    }
  }
  return -1;
}

int main()
{
  cin >> n >> m;

  int i, j;
  string str;
  for(i = 0; i < n; i++)
  {
    cin >> str;

    j = 0;
    for(char c : str)
    {
      int e = c - '\0';
      c = c - 48;
      map[i][j] = c;
      j += 1;
    }
  }

  int ans = bfs();
  cout << ans << '\n';
  return 0;
}
