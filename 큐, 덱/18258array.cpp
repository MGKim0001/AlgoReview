// 큐 2
// 큐를 구현하는 문제다

#include <iostream>
#include <queue>
#include <cmath>

#define MAX_SIZE 2000001
using namespace std;

int getSize(int front, int end)
{
  int ret = 0;
  if(end >= front)
  {
    ret = end - front;
  }
  else
  {
    ret = MAX_SIZE - front + end;
  }
  return ret;
}

int main()
{
  int n;
  cin >> n;

  int queue[MAX_SIZE];
  int ans[n] = {-9999,};

  int i;
  int front_index = 0;
  int end_index = 0;
  for(i = 0; i < n; i++)
  {
    string cmd;
    cin >> cmd;

    int value;
    if(!cmd.compare("push"))
    {
      cin >> value;
      queue[end_index] = value;

      end_index++;
      if(end_index >= MAX_SIZE)
      {
        end_index = 0;
      }

      ans[i] = -9999;
    }
    else if(!cmd.compare("pop"))
    {
      if(getSize(front_index, end_index) == 0)
      {
        ans[i] = -1;
      }
      else
      {
        value = queue[front_index];
        ans[i] = value;

        front_index++;
        if(front_index >= MAX_SIZE)
        {
          front_index = 0;
        }
      }
    }
    else if(!cmd.compare("size"))
    {
      value = getSize(front_index, end_index);
      ans[i] = value;
    }
    else if(!cmd.compare("empty"))
    {
      if(getSize(front_index, end_index) == 0)
      {
        ans[i] = 1;
      }
      else
      {
        ans[i] = 0;
      }
    }
    else if(!cmd.compare("front"))
    {
      if(getSize(front_index, end_index) == 0)
      {
        ans[i] = -1;
      }
      else
      {
        ans[i] = queue[front_index];
      }
    }
    else if(!cmd.compare("back"))
    {
      if(getSize(front_index, end_index) == 0)
      {
        ans[i] = -1;
      }
      else
      {
        if(end_index == 0)
        {
          ans[i] = queue[MAX_SIZE-1];
        }
        else
        {
          ans[i] = queue[end_index-1];
        }
      }
    }
  }

  for(i = 0; i < n; i++)
  {
    if(ans[i] != -9999)
    {
      printf("%d\n", ans[i]);
    }
  }

  return 0;
}
