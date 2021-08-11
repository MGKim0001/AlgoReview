// k번째 수
// N이 5일때
// A                  B
// (1 2   3  4  5)    (1 2 2 3 3 4 4 4 5 5  6  6  8  8  9 10 10 12 12 15 15 16 20 20 25)
// (2 4   6  8 10)    (0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24)
// (3 6   9 12 15)
// (4 8  12 16 20)
// (5 10 15 20 25)
// B[k]의 수를 찾는 최적화 문제를 결정 문제로 바꿔야 한다
// 처음 시작 수를 0, 마지막 수를 (N-1)^2이라고 했을 때, B[k]는 이 가운데 어느 수가 된다
// 범위를 구한다고 했을 때, 어떤 수 m 보다 작거나 같은 수의 개수는
// 배열의 각 행에서 세어봤을 때 m을 각 행의 길이로 나눈 것이 된다
// m이 k보다 큰지 작은지 여부를 구하는 것으로 범위를 조정하고 마지막에 k를 구한다

#include <iostream>

using namespace std;

long long getK(long long n, long long k)
{
  long long ans = 0;
  long long l = 1;
  long long h = n*n;

  while(l <= h)
  {
    long long mid = (l+h)/2;

    int i;
    long long count = 0;
    for(i = 1; i <= n; i++)
    {
      count += min(n, mid/i);
    }

    if(count < k)
    {
      l = mid+1;
    }
    else
    {
      ans = mid;
      h = mid-1;
    }
  }

  return ans;
}

int main()
{
  long long n, k;
  cin >> n >> k;

  long long ans = getK(n, k);
  cout << ans << endl;
  return 0;
}
