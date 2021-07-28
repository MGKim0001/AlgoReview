// 이항계수
// 이항계수 팩토리얼을 for 문으로 구현한다

#include <iostream>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  int up = n;
  int i, dividened = 1;
  for(i = k+1; i <= n; i++)
  {
    dividened *= i;
  }

  int down = n-k;
  int divider = 1;
  for(i = 1; i <= down; i++)
  {
    divider *= i;
  }

  int result = dividened/divider;
  cout << result << endl;

  return 0;
}
