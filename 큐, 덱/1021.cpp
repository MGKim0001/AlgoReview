// 회전하는 큐

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

void rotL(deque<int>* dq, int iter)
{
  int i;
  for(i = 0; i < iter; i++)
  {
    dq->push_back(dq->front());
    dq->pop_front();
  }
}

void rotR(deque<int>* dq, int iter)
{
  int i;
  for(i = 0; i < iter; i++)
  {
    dq->push_front(dq->back());
    dq->pop_back();
  }
}

int main()
{
  int dq_size, n;
  cin >> dq_size >> n;

  deque<int> dq;
  vector<int> vv(n);
  int i, j;
  for(i = 1; i <= dq_size; i++)
  {
    dq.push_back(i);
  }

  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    vv[i] = e;
  }

  int vv_index, ret = 0;
  for(vv_index = 0; vv_index < n; vv_index++)
  {
    int curr_index;
    for(j = 0; j < dq.size(); j++)
    {
      if(dq[j] == vv[vv_index])
      {
        curr_index = j;
      }
    }

    int leftRiter = curr_index;
    int rightRiter = dq.size() - curr_index;

    if(curr_index == 0)
    {
      dq.pop_front();
    }
    else if(leftRiter < rightRiter)
    {
      rotL(&dq, leftRiter);
      dq.pop_front();
      ret += leftRiter;
    }
    else
    {
      rotR(&dq, rightRiter);
      dq.pop_front();
      ret += rightRiter;
    }
  }

  cout << ret << endl;
  return 0;
}
