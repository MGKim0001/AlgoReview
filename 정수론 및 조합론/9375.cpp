// 패션왕 신혜빈
// 조합 문제로 모든 의상을 한번씩 입을 수 있고 종류가 다른 의상은 겹쳐서 입을 수 있다
// 조합 = 옷의 갯수 + 종류별 옷의 수를 전부 곱한 값

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int i, j;
  vector<int> ans(n);
  for(i = 0; i < n; i++)
  {
    int total;
    cin >> total;

    map<string, int> clothes;
    vector<string> kinds;
    for(j = 0; j < total; j++)
    {
      string name, kind;
      cin >> name >> kind;

      if(find(kinds.begin(), kinds.end(), kind) == kinds.end())
      {
        kinds.push_back(kind);
      }
      if(clothes.find(kind) != clothes.end())
      {
        clothes[kind] += 1;
      }
      else
      {
        clothes.insert(make_pair(kind, 1));
      }
    }

    int ret = 1;
    for(string k : kinds)
    {
      ret *= clothes[k]+1;
    }
    ans[i] = ret-1;
  }

  for(i = 0; i < n; i++)
  {
    cout << ans[i] << endl;
  }
  return 0;
}
