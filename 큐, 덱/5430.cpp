// AC

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void printForward(deque<string> dq)
{
  string temp;
  if(!dq.empty())
  {
    temp = dq.back();
    dq.pop_back();
  }

  cout << '[';
  while(!dq.empty())
  {
    cout << dq.front() << ',';
    dq.pop_front();
  }
  cout << temp << "]\n";
}

void printBackward(deque<string> dq)
{
  string temp;
  if(!dq.empty())
  {
    temp = dq.front();
    dq.pop_front();
  }

  cout << '[';
  while(!dq.empty())
  {
    cout << dq.back() << ',';
    dq.pop_back();
  }
  cout << temp << "]\n";
}

int main()
{
  int n;
  cin >> n;

  int i, j;
  for(i = 0; i < n; i++)
  {
    string str, input;
    deque<string> dq;
    int size;
    int error_flag = 0;
    int rotate = 0;

    cin >> str;
    cin >> size;
    cin >> input;

    string e = "";
    for(char c : input)
    {
      int num = c - '\0';
      if(num >= 48 && num <= 57)
      {
        e += c;
      }
      else if(e != "")
      {
        dq.push_back(e);
        e = "";
      }
    }

    for(char c : str)
    {
      if(c == 'R')
      {
        rotate = rotate == 1 ? 0 : 1;
      }
      if(c == 'D')
      {
        if(dq.empty())
        {
          error_flag = 1;
          break;
        }

        if(rotate)
        {
          dq.pop_back();
        }
        else
        {
          dq.pop_front();
        }
      }
    }

    if(error_flag)
    {
      cout << "error\n";
    }
    else
    {
      if(rotate)
      {
        printBackward(dq);
      }
      else
      {
        printForward(dq);
      }
    }
  }
  return 0;
}
