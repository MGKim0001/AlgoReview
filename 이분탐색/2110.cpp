// 공유기 설치
// 최적화 문제를 결정문제로 바꾼다
// 가장 인접한 두 공유기 사이의 최대 거리를 찾는 최적화 문제를
// 일정 거리 사이에 공유기를 설치할 수 있는 지 확인하는 결정문제로 바꾼다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getDist(vector<long long> v, int n, int c)
{
  long long ans = 0;
  long long l = 1;
  long long h = v[n-1] - v[0];

  while(l <= h)
  {
    long long mid = (l+h)/2;

    int i, count = 1;
    long long start = v[0];
    for(i = 0; i < n; i++)
    {
      long long dist = v[i] - start;
      if(mid <= dist)
      {
        count += 1;
        start = v[i];
      }
    }

    if(count >= c)
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
  int n, c;
  cin >> n >> c;

  vector<long long> v(n);
  int i;
  for(i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  long long ans = getDist(v, n, c);
  cout << ans << '\n';
  return 0;
}
