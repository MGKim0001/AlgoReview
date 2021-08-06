// 이항계수 3
// 분할정복을 이용해 해결하는 문제다
// 페르마의 소정리를 이용하는 방법과 확장된 유클리드 호제법을 이용하는 방법이 있다
// 페르마의 소정리의 경우 A = N!, B = K!(N-K)!, P = MOD 라고 할 때,
// B^(P-2) ~ B^(-1)(%P) 이기 때문에 B^(-1)을 B^(P-2)로 대치 할 수 있다는 점이 핵심이다
// 결과는 A*B^(-1)%P = ((A%P)*(B^(-1)%P))%P = (A%P)(B^(P-2)%P)%P 가 된다

// 확장된 유클리드 호제법의 경우 B^(-1)을 10000000007이 소수라는 점을 이용해서 구한다
// 정수 M과 소수 p의 최대공약수는 언제나 1이기 때문에 Mx * py = 1이다
// 이 식에 %p를 취하게 되면 Mx%p ~ 1%p가 된다
// 이때 M을 B^(-1)이라고 하면 B^(-1)%p ~ x%p가 된다
// 이를 기존의 식에 대입하면 A%p*x%p를 구하는 것으로 답을 구할 수 있게 된다
// x는 확장된 유클리드 호제법을 이용하여 구할 수 있다

#include <iostream>
#define MOD 1000000007

using namespace std;

long long pow(long long a, long long b)
{
  if(b == 0)
  {
    return 1;
  }
  if(b%2 > 0)
  {
    return (pow(a, b-1) * a)%MOD;
  }

  long long half = pow(a, b/2)%MOD;
  return (half*half)%MOD;
}

int main()
{
  long long n, k;
  cin >> n >> k;

  long long a = 1, b = 1;
  long long i;
  // A = N!
  for(i = 1; i <= n; i++)
  {
    a *= i;
    a %= MOD;
  }
  // B = K!
  for(i = 1; i <= k; i++)
  {
    b *= i;
    b %= MOD;
  }
  // B => B*(N-K)!
  for(i = 1; i <= n-k; i++)
  {
    b *= i;
    b %= MOD;
  }

  long long b2 = pow(b, MOD-2);
  long long ans = a*b2;
  ans %= MOD;
  cout << ans << '\n';
  return 0;
}
