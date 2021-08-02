// 균형잡힌 세상
// 스택에 괄호를 넣고 빼는 것을 반복하면 된다

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
  int i = 0;
  vector<string> ans;

  while(1)
  {
    char str[101] = {'\0', };
    cin.getline(str, 101);
    if(!strcmp(str, ".")) break;

    stack<char> s;
    ans.push_back("yes");

    for(char c : str)
    {
      if(c == '(' || c == '[')
      {
        s.push(c);
      }
      else if(c == ')')
      {
        if(!s.empty() && s.top() == '(')
        {
          s.pop();
        }
        else
        {
          ans[i] = "no";
          break;
        }
      }
      else if(c == ']')
      {
        if(!s.empty() && s.top() == '[')
        {
          s.pop();
        }
        else
        {
          ans[i] = "no";
          break;
        }
      }
    }
    if(!s.empty())
    {
      ans[i] = "no";
    }
    i++;
  }

  for(string str : ans)
  {
    cout << str << endl;
  }
  return 0;
}
