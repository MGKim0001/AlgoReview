// 약수
// 정렬한 다음 양 끝 수를 곱하면 된다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int i;
  vector<long long> vv(n);
  for(i = 0; i < n; i++)
  {
    long long e;
    cin >> e;
    vv[i] = e;
  }

  sort(vv.begin(), vv.end());
  long long num = vv[0] * vv[vv.size()-1];
  cout << num << endl;
  return 0;
}
