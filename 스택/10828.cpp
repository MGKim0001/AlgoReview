// 스택

#include <iostream>
#include <vector>

#define MAX_SIZE 10001

using namespace std;

typedef struct Stack
{
  int space[MAX_SIZE];
  int index;
} stack;

void push(Stack* s, int value)
{
  if(s->index < MAX_SIZE)
  {
    s->index++;
    s->space[s->index] = value;
  }
}

int pop(Stack* s)
{
  int ret = -1;
  if(s->index >= 0)
  {
    ret = s->space[s->index];
    s->index--;
  }
  return ret;
}

int size(Stack* s)
{
  return s->index+1;
}

int top(Stack* s)
{
  //cout << "top: " << s->index << " " << s->space[s->index] << endl;

  int ret = -1;
  if(s->index >= 0)
  {
    ret = s->space[s->index];
  }
  return ret;
}

int isEmpty(Stack* s)
{
  return s->index >= 0 ? 0 : 1;
}

int main()
{
  int n;
  cin >> n;

  stack st;
  st.index = -1;
  int outs[n] = {-9999, };

  int i;
  for(i = 0; i < n; i++)
  {
    string comd;
    cin >> comd;

    int val;
    if(!comd.compare("push"))
    {
      cin >> val;
      push(&st, val);
      outs[i] = -9999;
    }
    else if(!comd.compare("top"))
    {
      val = top(&st);
      outs[i] = val;
    }
    else if(!comd.compare("pop"))
    {
      val = pop(&st);
      outs[i] = val;
    }
    else if(!comd.compare("empty"))
    {
      val = isEmpty(&st);
      outs[i] = val;
    }
    else if(!comd.compare("size"))
    {
      val = size(&st);
      outs[i] = val;
    }
  }

  for(i = 0; i < n; i++)
  {
    if(outs[i] != -9999)
    {
      cout << outs[i] << endl;
    }
  }

  return 0;
}
