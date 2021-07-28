// ATM
// 간단한 그리디 알고리즘 문제로 정렬 뒤 더한다

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int i;
  vector<int> people(n);
  vector<int> times(n);
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    people[i] = e;
  }

  sort(people.begin(), people.end());

  int sum = 0;
  for(i = 0; i < n; i++)
  {
    sum = sum + people[i];
    times[i] = sum;
  }
  
  sum = 0;
  for(i = 0; i < n; i++)
  {
    sum += times[i];
  }

  cout << sum << endl;
  return 0;
}
