// 카드
// 큐를 사용하여 해결한다

#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int n;
  cin >> n;

  queue<int> q;
  int i;
  for(i = 1; i <= n; i++)
  {
    q.push(i);
  }

  int value = 0;
  while(!q.empty())
  {
    value = q.front();
    q.pop();

    if(q.empty()) break;

    value = q.front();
    q.pop();
    q.push(value);
  }

  cout << value << '\n';

  return 0;
}
