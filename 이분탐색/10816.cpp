// 숫자 카드 2
// upper_bound와 lower_bound를 사용해서 해결했다

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  vector<int> v;
  int i, e;

  cin >> n;
  for(i = 0; i < n; i++)
  {
    cin >> e;
    v.push_back(e);
  }

  sort(v.begin(), v.end());

  cin >> m;
  for(i = 0; i < m; i++)
  {
    cin >> e;
    auto up = upper_bound(v.begin(), v.end(), e);
    auto down = lower_bound(v.begin(), v.end(), e);
    int num = up - down;
    printf("%d ", num);
  }

  return 0;
}
