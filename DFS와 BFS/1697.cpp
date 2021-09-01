// 숨바꼭질
// 이동할 수 있는 경우는 세 가지가 있다
// X-1, X+1, 2*X
// 각 경우에 대해 BFS를 돌면서 최소값을 구해주면 된다

#include <iostream>
#include <queue>
#define MAX 100001

using namespace std;

int n, k;
int visited[MAX];

int bfs()
{
  queue<pair<int, int>> q;
  q.push(make_pair(n, 0));
  visited[n] = 1;

  while(!q.empty())
  {
      pair<int, int> curr = q.front();
      q.pop();

      if(curr.first == k)
      {
        return curr.second;
      }

      if(curr.first-1 >= 0 && !visited[curr.first-1])
      {
        q.push(make_pair(curr.first-1, curr.second+1));
        visited[curr.first-1] = 1;
      }
      if(curr.first+1 < MAX && !visited[curr.first+1])
      {
        q.push(make_pair(curr.first+1, curr.second+1));
        visited[curr.first+1] = 1;
      }
      if(curr.first*2 < MAX && !visited[curr.first*2])
      {
        q.push(make_pair(curr.first*2, curr.second+1));
        visited[curr.first*2] = 1;
      }
  }

  return -1;
}

int main()
{
  cin >> n >> k;
  int ans = bfs();
  cout << ans << '\n';
  return 0;
}
