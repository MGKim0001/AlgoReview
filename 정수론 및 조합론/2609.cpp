// 최대공약수와 최소공배수
// 유클리드 호제법을 이용해서 최대공약수를 구하고
// 최대공약수를 이용해서 최소공배수를 구한다
// 유클리드 호제법은 나머지를 계속해서 나눠가는 방식이다

#include <iostream>

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

int lcm(int a, int b, int c)
{
  return a*b/c;
}

int main()
{
  int a, b;
  cin >> a >> b;

  int g = gcd(a, b);
  int l = lcm(a, b, g);

  cout << g << endl;
  cout << l << endl;

  return 0;
}
