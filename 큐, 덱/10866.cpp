// 덱

#include <iostream>
#include <deque>

#define MAX_SIZE 10001

using namespace std;

int main()
{
  int n;
  cin >> n;

  deque<int> dq;

  int i;
  for(i = 0; i < n; i++)
  {
    string str;
    cin >> str;

    int value;
    if(!str.compare("push_front"))
    {
      cin >> value;
      dq.push_front(value);
    }
    else if(!str.compare("push_back"))
    {
      cin >> value;
      dq.push_back(value);
    }
    else if(!str.compare("pop_front"))
    {
      if(dq.empty())
      {
        cout << "-1\n";
      }
      else
      {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    }
    else if(!str.compare("pop_back"))
    {
      if(dq.empty())
      {
        cout << "-1\n";
      }
      else
      {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    }
    else if(!str.compare("size"))
    {
      cout << dq.size() << '\n';
    }
    else if(!str.compare("empty"))
    {
      cout << dq.empty() << '\n';
    }
    else if(!str.compare("front"))
    {
      if(dq.empty())
      {
        cout << "-1\n";
      }
      else
      {
        cout << dq.front() << '\n';
      }
    }
    else if(!str.compare("back"))
    {
      if(dq.empty())
      {
        cout << "-1\n";
      }
      else
      {
        cout << dq.back() << '\n';
      }
    }
  }
  return 0;
}
