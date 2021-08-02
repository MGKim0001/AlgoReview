// 괄호
// 스택에 괄호를 넣고 빼는 것을 반복하면 된다

#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int n;
  cin >> n;

  string ans[n] = {"", };
  int i;
  for(i = 0; i < n; i++)
  {
    stack<char> s;
    string str;
    cin >> str;

    ans[i] = "YES";

    for(char c : str)
    {
      if(c == '(')
      {
        s.push(c);
      }

      if(c == ')')
      {
        if(s.empty())
        {
          ans[i] = "NO";
        }
        else
        {
          s.pop();
        }
      }
    }
    if(!s.empty())
    {
      ans[i] = "NO";
    }
  }

  for(i = 0; i < n; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}
