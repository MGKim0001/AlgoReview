// 팩토리얼 0의 개수
// 팩토리얼의 약수 중 2와 5가 늘어나면 0의 갯수도 증가한다

#include <iostream>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int countTwo = 0, countFive = 0;
  int i;
  for(i = 2; i <= n; i*=2)
  {
    countTwo += n/i;
  }

  for(i = 5; i <= n; i*=5)
  {
    countFive += n/i;
  }

  int ans = 0;
  if(countTwo > countFive)
  {
    ans = countFive;
  }
  else
  {
    ans = countTwo;
  }

  cout << ans << endl;
  return 0;
}
