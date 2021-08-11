// 절댓값 힙
// 절댓값 힙을 구현한다

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<long long, long long> pi;

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  priority_queue<pi, vector<pi>, greater<pi>> pq;
  int i;
  for(i = 0; i < n; i++)
  {
    long long e;
    cin >> e;

    if(e == 0)
    {
      if(pq.empty())
      {
        cout << "0\n";
      }
      else
      {
        long long ret = pq.top().second;
        pq.pop();
        cout << ret << '\n';
      }
    }
    else
    {
      pq.push(make_pair(abs(e), e));
    }
  }
  return 0;
}
