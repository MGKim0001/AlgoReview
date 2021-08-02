// 오큰수
// 오큰수란 어떤 수 보다 크면서 가장 왼쪽에 있는 수를 말한다

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int i;
  vector<int> v(n);
  vector<int> ans(n, -1);
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    v[i] = e;
  }

  stack<int> s;
  for(i = 0; i < n; i++)
  {
    while(!s.empty() && v[s.top()] < v[i])
    {
      ans[s.top()] = v[i];
      s.pop();
    }
    s.push(i);
  }

  for(i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}
