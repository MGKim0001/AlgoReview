// 최소공배수
// 유클리드 호제법으로 구한다

#include <iostream>
#include <vector>

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
  int n;
  cin >> n;

  int i;
  vector<pair<int, int>> vv(n);
  for(i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    vv[i] = make_pair(a, b);
  }
  for(i = 0; i < n; i++)
  {
    int g = gcd(vv[i].first, vv[i].second);
    int l = lcm(vv[i].first, vv[i].second, g);
    printf("%d\n", l);
  }

  return 0;
}
