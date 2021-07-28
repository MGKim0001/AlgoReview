// 배수와 약수
// 기본적인 정수론 문제로 두 수가 주어졌을 때 서로 배수와 약수인지 구하는 문제다
// 첫번째 숫자가 두번째 숫자로 나누어 지면 -> 두번째 숫자의 배수
// 두번째 숫자가 첫번째 숫자로 나누어 지면 -> 두번째 숫자의 약수

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int a, b;
  vector<int> first;
  vector<int> second;
  while(a != 0 || b != 0)
  {
    cin >> a >> b;
    if(a == 0 && b == 0)
    {
      break;
    }

    first.push_back(a);
    second.push_back(b);
  }

  int i;
  for(i = 0; i < first.size(); i++)
  {
    int n1 = first[i];
    int n2 = second[i];

    if(n1 == 0 || n2 == 0)
    {
      cout << "neither" << endl;
    }
    else
    {
      if(n1%n2 == 0)
      {
        cout << "multiple" << endl;
      }
      else if(n2%n1 == 0)
      {
        cout << "factor" << endl;
      }
      else
      {
        cout << "neither" << endl;
      }
    }
  }

  return 0;
}
