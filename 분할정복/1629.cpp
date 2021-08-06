// 곱셈
// 분할정복을 사용하여 거듭제곱을 빠르게 계산하는 문제다
// 제곱 부분은 재귀를 사용해 계산할 수 있지만
// 나머지 부분은 모듈러 연산을 사용해서 풀어야 한다

#include <iostream>

using namespace std;

long square(long a, long b, long c)
{
  if(b == 1)
  {
    return a%c;
  }

  long temp = square(a, b/2, c);

  if(b%2 == 1)
  {
    return (temp*temp%c)*a%c;
  }

  return (temp*temp)%c;
}

int main()
{
  long a, b, c;
  cin >> a >> b >> c;

  int sqr = square(a, b, c);
  cout << sqr << endl;
  return 0;
}
