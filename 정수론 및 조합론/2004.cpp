// 조합 0의 개수
// 약수 중 2와 5의 갯수를 세면 된다

#include <iostream>

using namespace std;

pair<long long, long long> getDivNum(int num)
{
  long long  countTwo = 0, countFive = 0;
  long long  div;
  for(div = 2; div <= num; div*=2)
  {
    countTwo += num/div;
  }

  for(div = 5; div <= num; div*=5)
  {
    countFive += num/div;
  }

  return make_pair(countTwo, countFive);
}

int main()
{
  long long n, m;
  cin >> n >> m;

  pair<long long, long long>  countN = getDivNum(n);
  pair<long long, long long>  countM = getDivNum(m);
  pair<long long, long long>  countNM = getDivNum(n-m);
  long long two = countN.first - countM.first - countNM.first;
  long long five = countN.second - countM.second - countNM.second;
  long long  ans = two < five ? two : five;
  cout << ans << endl;

  return 0;
}
