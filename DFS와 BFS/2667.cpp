// 단지번호붙이기
// DFS를 사용해서 연결되어있는 요소의 수를 계산해 출력한다

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int map[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int visited[26][26];

int dfs(int x, int y)
{
  int k, count = 0;
  visited[x][y] = 1;
  count += 1;

  for(k = 0; k < 4; k++)
  {
      int nx = x + dx[k];
      int ny = y + dy[k];

      if(nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny])
      {
        if(!visited[nx][ny])
        {
          count += dfs(nx, ny);
        }
      }
  }

  return count;
}

int main()
{
  cin >> n;

  string line;
  int i, j;
  for(i = 0; i < n; i++)
  {
    cin >> line;

    for(j = 0; j < line.size(); j++)
    {
      int e = line.at(j) - '\0';
      e -= 48;
      map[i][j] = e;
    }
  }

  vector<int> houses;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      if(map[i][j] && !visited[i][j])
      {
        int ans = dfs(i, j);
        houses.push_back(ans);
      }
    }
  }

  sort(houses.begin(), houses.end());
  
  cout << houses.size() << '\n';
  for(i = 0; i < houses.size(); i++)
  {
    cout << houses[i] << '\n';
  }

  return 0;
}
