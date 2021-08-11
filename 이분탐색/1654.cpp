  // 렌선 자르기
// 최적화 문제를 결정 문제로 바꿔서 푸는 문제다
// parametic search라고도 한다
// 최적화 문제로 풀면 자를 수 있는 길이 중 n개의 렌선을 만들 수 있는 최대의 길이가 된다
// 결정 문제로 풀면 일정 길이로 렌선을 자를 수 있느냐가 될 것이다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long cut(vector<long long> v, int n, int k, long long max)
{
  long long ans = 0;
  long long l = 1;
  long long h = max;

  while(l <= h)
  {
    long long mid = (l+h)/2;

    int i, count = 0;
    for(i = 0; i < n; i++)
    {
      count += v[i]/mid;
    }

    if(count >= k)
    {
      if(ans < mid)
      {
        ans = mid;
      }

      l = mid+1;
    }
    else
    {
      h = mid-1;
    }
  }

  return ans;
}

int main()
{
  int n, k;
  cin >> n >> k;

  vector<long long> v(n);
  int i;
  long long max = -1;
  for(i = 0; i < n; i++)
  {
    cin >> v[i];

    if(v[i] > max)
    {
      max = v[i];
    }
  }

  sort(v.begin(), v.end());

  long long ans = cut(v, n, k, max);
  cout << ans << '\n';
  return 0;
}
