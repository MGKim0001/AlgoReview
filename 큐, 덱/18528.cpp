// 큐2
// 배열로 구현 시 크기가 저장하는 크기가 너무 커져서 실행할 수 없다

#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(0);
  cin.sync_with_stdio(false);

  int n;
  cin >> n;

  int i;
  queue<int> q;
  for(i = 0; i < n; i++)
  {
    string cmd;
    cin >> cmd;

    int value;
    if(!cmd.compare("push"))
    {
      cin >> value;
      q.push(value);
    }
    else if(!cmd.compare("pop"))
    {
      if (q.size() == 0)
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << q.front() << '\n';
        q.pop();
      }
    }
    else if(!cmd.compare("size"))
    {
      cout << q.size() << '\n';
    }
    else if(!cmd.compare("empty"))
    {
      cout << q.empty() << '\n';
    }
    else if(!cmd.compare("front"))
    {
      if(q.empty())
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << q.front() << '\n';
      }
    }
    else if(!cmd.compare("back"))
    {
      if(q.empty())
      {
        cout << -1 << '\n';
      }
      else
      {
        cout << q.back() << '\n';
      }
    }
  }

  return 0;
}
