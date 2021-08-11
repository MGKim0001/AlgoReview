// 가장 긴 증가하는 부분 수열 2
// 결과가 되는 v에 처음에는 넣을 수 있는 가장 큰 수를 넣는다
// 그 다음 수열에서 수를 하나씩 읽어오면서 v의 마지막 요소보다 큰지 확인한다
// 크다면 v에 넣고 아니라면 v안에서 수열의 수보다 작지 않은 수 중 가장 앞에 있는 인덱스를 구한다
// 그 다음 그 위치에 수열의 수를 추가한다
// 보다 작은 수를 계속해서 추가해가는 것으로 가장 긴 부분수열을 얻을 수 있게 된다

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<long long> v = {987654321};
  int i, j;
  for(i = 0; i < n; i++)
  {
    long long a;
    cin >> a;

    if(a > v.back())
    {
      v.push_back(a);
    }
    else
    {
      int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
      v[idx] = a;
    }
  }

  int ans = v.size();
  cout << ans << '\n';
  return 0;
}
