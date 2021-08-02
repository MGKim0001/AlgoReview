// 요세푸스 순열

#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  queue<int> q;
  int ans[n];
  int ans_index = 0;
  int i;
  for(i = 1; i <= n; i++)
  {
    q.push(i);
  }

  int value;
  while(!q.empty())
  {
    for(int j = 1; j < k; j++)
    {
      value = q.front();
      q.pop();
      q.push(value);
    }

    value = q.front();
    q.pop();
    ans[ans_index] = value;
    ans_index++;
  }

  cout << '<';
  for(i = 0; i < ans_index-1; i++)
  {
    cout << ans[i] << ", ";
  }
  cout << ans[ans_index-1] << '>';

  return 0;
}
