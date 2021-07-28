// 좌표 압축
// 문제 이해가 힘들었다
// 좌표의 대체값 = 좌표에 있던 원래 수보다 작은 숫자의 갯수

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int n1, int n2)
{
  return n1 > n2;
}

int main()
{
  int n;
  cin >> n;
  vector<int> vv(n);
  vector<pair<int, int>> nums;

  int i;
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    vv[i] = e;
  }

  vector<int> temp = vv;
  sort(temp.begin(), temp.end());
  temp.resize(unique(temp.begin(), temp.end()) - temp.begin());

  for(int v : vv)
  {
    int num = lower_bound(temp.begin(), temp.end(), v) - temp.begin();
    cout << num << " ";
  }

  return 0;
}
