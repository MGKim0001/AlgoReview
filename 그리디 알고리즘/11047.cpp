// 동전 0
// 그리디 알고리즘은 브루트 포스와는 달리 모든 경우의 수를 구하지 않으며
// 앞에서 부터 하나씩 만들어 나가다 보면 답이 구해진다는 특징이 있다
// 동전을 가치가 큰 순서부터 k와 비교하면서 k보다 같거나 작으면 나눈다

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int i;
  vector<int> coins(n);

  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    coins[i] = e;
  }

  int count = 0;
  for(i = n-1; i >= 0; i--)
  {
    if(k >= coins[i])
    {
        int div = k/coins[i];
        k -= div*coins[i];
        count += div;
    }
  }

  cout << count << endl;

  return 0;
}
