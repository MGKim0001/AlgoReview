// 제로
// 스택 문제로 넣고 빼기를 반복하면 된다

#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int n;
  cin >> n;

  stack<int> s;
  int i;
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;

    if(e == 0)
    {
      s.pop();
    }
    else
    {
      s.push(e);
    }
  }

  int sum = 0;
  while(!s.empty())
  {
    sum += s.top();
    s.pop();
  }
  cout << sum << endl;
  return 0;
}
