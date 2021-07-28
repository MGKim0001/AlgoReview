// 단어 정렬하기
// 단어가 입력되면 배열에서 맞는 위치를 찾아가는 방법을 사용한다
// 단어의 순서 계산법은 길이 -> 알파벳 대조 순서로 한다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> vv;

bool compare(string s1, string s2)
{
  if(s1.size() == s2.size())
  {
    return s1 < s2;
  }
  else
  {
    return s1.size() < s2.size();
  }
}

int main()
{
  cin >> n;
  int i;
  for(i = 0; i < n; i++)
  {
    string e;
    cin >> e;
    vv.push_back(e);
  }

  sort(vv.begin(), vv.end(), compare);

  string temp;
  for(i = 0; i < n; i++)
  {
    if(temp == vv[i]) continue;
    cout << vv[i] << endl;
    temp = vv[i];
  }

  return 0;
}
