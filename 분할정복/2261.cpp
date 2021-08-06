// 가장 가까운 두 점
// 분할정복 방식을 사용하여 x축 좌표를 중심으로 검사하는 영역을 분할해나간다
// 가운데 지점을 중심으로 좌표를 좌, 우로 나눈 다음 좌우 각각 가장 가까이 있는 좌표를 구한다
// 좌우에서 구한 가장 가까이 있는 자표 중 작은 것이 제일 가까운 좌표가 된다
// 그 다음 가운데 있는 좌표를 검사해 준다
// 가운데 있는 좌표를 검사할 때는 y축 좌표를 중심으로 검사해준다
// 제일 가까운 좌표를 기준으로 더 가까이 있는 y축 좌표가 있으면 가장 가까운 좌표를 갱신해 준다

// 라인 스위핑 알고리즘으로 해결할 경우
// 초기 거리를 설정하고 그 거리보다 멀리있는 좌표는 제외하는 식으로 풀어나갈 수 있다

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool xcmp(pair<int, int> p1, pair<int, int> p2)
{
  return p1.first < p2.first;
}

bool ycmp(pair<int, int> p1, pair<int, int> p2)
{
  return p1.second < p2.second;
}

int getMin(int a, int b)
{
  return a < b ? a : b;
}

int dist(pair<int, int> p1, pair<int, int> p2)
{
  int xdiff = p2.first - p1.first;
  int ydiff = p2.second - p1.second;
  int ret = xdiff*xdiff + ydiff*ydiff;
  return ret;
}

int bruteDist(vector<pair<int, int>> ps, int start, int end)
{
  int ret = 987654321;
  int i, j;
  for(i = start; i < end; i++)
  {
    for(j = i+1; j <= end; j++)
    {
      int d = dist(ps[i], ps[j]);
      ret = getMin(d, ret);
    }
  }
  return ret;
}

int getMiddleDist(vector<pair<int, int>> ps, int start, int end, int mid, int minDist)
{
  int ret = minDist;
  int xDist;
  vector<pair<int, int>> list;

  int i, j;
  int midx = ps[mid].first;
  for(i = start; i <= end; i++)
  {
    xDist = ps[i].first - midx;
    if(xDist*xDist < minDist)
    {
      list.push_back(ps[i]);
    }
  }

  sort(list.begin(), list.end(), ycmp);

  int yDist;
  for(i = start; i < list.size()-1; i++)
  {
    for(j = i+1; j < list.size(); j++)
    {
      yDist = list[i].second - list[j].second;
      if(yDist*yDist < minDist)
      {
        ret = getMin(dist(list[i], list[j]), ret);
      }
      else
      {
        break;
      }
    }
  }

  return ret;
}

int getMinDist(vector<pair<int, int>> ps, int start, int end)
{
  if(end - start < 3)
  {
    return bruteDist(ps, start, end);
  }

  int mid = (start + end)/2;
  int leftDist = getMinDist(ps, start, mid);
  int rightDist = getMinDist(ps, mid+1, end);
  int minDist = getMin(leftDist, rightDist);
  int band = getMiddleDist(ps, start, end, mid, minDist);
  return getMin(minDist, band);
}

int getMinSwipe(vector<pair<int, int>> ps, int n)
{
  set<pair<int, int>> s;
  s.insert({ps[0].second, ps[0].first});
  s.insert({ps[1].second, ps[1].first});

  int minDist = dist(ps[0], ps[1]);
  int idx = 0;

  for(int i = 2; i < n; i++)
  {
    while(idx < i)
    {
      int d = ps[i].first - ps[idx].first;
      if(d*d <= minDist)
      {
        break;
      }
      else
      {
        s.erase({ps[idx].second, ps[idx].first});
        idx++;
      }
    }

    auto start = s.lower_bound({ps[i].second - sqrt(minDist), 987654321});
    auto end = s.lower_bound({ps[i].second + sqrt(minDist), 987654321});
    for(auto it = start; it != end; it++)
    {
      //{it.Y, it->X}
      pair<int, int> point = make_pair(it->second, it->first);
      minDist = getMin(minDist, dist(point, ps[i]));
    }
    s.insert({ps[i].second, ps[i].first});
  }

  return minDist;
}

int main()
{
  int n;
  cin >> n;

  vector<pair<int, int>> ps;
  int i;
  for(i = 0; i < n; i++)
  {
    pair<int, int> p;
    cin >> p.first >> p.second;
    ps.push_back(p);
  }

  sort(ps.begin(), ps.end(), xcmp);

  int ans;
  // ans = getMinDist(ps, 0, n-1);
  ans = getMinSwipe(ps, n);
  cout << ans << endl;
  return 0;
}
