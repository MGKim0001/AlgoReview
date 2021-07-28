// 검문
// 주어진 N개의 수에 대해 나눴을 때 나머지가 같은 수 M을 모두 찾는 문제

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
  while(b != 0)
  {
    int r = a%b;
    a = b;
    b = r;
  }

  return a;
}

int main()
{
  int n;
  cin >> n;

  int i, j;
  vector<int> vv(n);
  vector<int> ans;
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    vv[i] = e;
  }

  sort(vv.begin(), vv.end());

  int g = vv[1] - vv[0];
  for(i = 2; i < vv.size(); i++)
  {
    g = gcd(g, vv[i]-vv[i-1]);
  }

  for(i = 2; i*i <= g; i++)
  {
    if(g%i == 0)
    {
      ans.push_back(i);
      ans.push_back(g/i);
    }
  }
  ans.push_back(g);

  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());

  for(i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
