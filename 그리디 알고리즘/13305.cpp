// 주유소
// 그리디 알고리즘 문제로 이전 주유 가격과 지금 주유 가격을 비교해서
// 더 작은 수를 더해 주는 방식으로 풀면 된다


#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<long long> dis(n);
  vector<long long> prices(n);

  int i;
  for(i = 0; i < n-1; i++)
  {
    long long d;
    cin >> d;
    dis[i] = d;
  }
  for(i = 0; i < n; i++)
  {
    long long p;
    cin >> p;
    prices[i] = p;
  }

  long long sum = dis[0] * prices[0];
  long long prev_price = prices[0];
  for(i = 1; i < n-1; i++)
  {
    if(prev_price < prices[i])
    {
      sum += dis[i] * prev_price;
    }
    else
    {
      sum += dis[i] * prices[i];
      prev_price = prices[i];
    }
  }

  cout << sum << endl;

  return 0;
}
