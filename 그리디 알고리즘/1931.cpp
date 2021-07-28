// 회의실 배정
// 그리디 알고리즘 문제로 끝나는 시간과 시작하는 시간을 비교해서
// 시작하는 시간 > 끝나는 시간이면 사용가능한 방 카운트를 1 증가시킨다
// 만약 주어진 시간표가 정렬되어 있지 않다면 끝나는 시간 순으로 정렬한다
// 끝나는 시간이 같다면 시작하는 시간순으로 정렬한다
// 시작하는 시간순으로 정렬 된다면 시작 시간과 끝나는 시간이 같은 경우는 무시해도 된다
// 다음 시작 시간이 어처피 더 크기 때문이다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
  return p1.second < p2.second;
}

int main()
{
  int n;
  cin >> n;

  int i;
  vector<pair<int, int>> times(n);
  for(i = 0; i < n; i++)
  {
    int begin, end;
    cin >> begin >> end;
    times[i] = make_pair(begin, end);
  }

  sort(times.begin(), times.end());
  sort(times.begin(), times.end(), cmp);

  int count = 1;
  int prev = 0;
  for(i = 1; i < n; i++)
  {
    if(times[i].first >= times[prev].second)
    {
      count++;
      prev = i;
    }
  }

  cout << count << endl;
  return 0;
}
