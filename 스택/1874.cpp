// 수열
// 주어진 수열의 숫자가 나올 때까지 push 연산을 반복한 뒤
// pop 연산으로 숫자를 출력한다
// 끝까지 push 연산을 진행해도 주어진 숫자가 나오지 않으면 false

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> vv(n+2);
  vector<char> ans;

  int i;
  for(i = 1; i <= n; i++)
  {
    int e;
    cin >> e;
    vv[i] = e;
  }

  stack<int> s;
  int index = 1;
  int no_flag = 0;
  for(i = 1; i <= n; i++)
  {
    s.push(i);
    ans.push_back('+');

    int top = s.top();

    for(; index <= n && vv[index] == top; index++)
    {
      ans.push_back('-');
      s.pop();

      if(!s.empty())
      {
        top = s.top();
      }
    }
  }

  if(s.empty())
  {
    for(i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << "\n";
    }
  }
  else
  {
    cout << "NO" << "\n";
  }

  return 0;
}
