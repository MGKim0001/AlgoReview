// 프린터 큐
// 큐의 응용이다

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(int a, int b)
{
  return a > b;
}

int main()
{
  int n;
  cin >> n;

  int i, j;
  for(i = 0; i < n; i++)
  {
    int size, th;
    cin >> size >> th;

    queue<pair<int, int>> que;
    vector<int> pri;
    queue<int> print;
    int max = 0;
    for(j = 0; j < size; j++)
    {
      int p;
      cin >> p;
      que.push(make_pair(j, p));
      pri.push_back(p);
    }

    sort(pri.begin(), pri.end(), cmp);

    int pindex = 0;
    while(!que.empty())
    {
      if(que.front().second == pri[pindex])
      {
        if(que.front().first == th)
        {
            break;
        }

        print.push(que.front().first);
        que.pop();
        pindex++;
      }
      else
      {
        que.push(que.front());
        que.pop();
      }
    }

    pindex += 1;
    cout << pindex << endl;
  }

  return 0;
}
