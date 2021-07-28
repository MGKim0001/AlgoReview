// 잃어버린 괄호
// 그리디 알고리즘 문제로 +와 - 만으로 이루어져 있기 때문에
// 큰 수 를 작은 수에다 빼줘야 한다
// 처음 '-'가 나온 이후 부터 모든 수를 빼주면 된다
// 그 뒤에 나오는 수는 그냥 빼나 다른 수에 더해서 빼나 똑같기 때문이다
// .at() 대신 []를 사용해서 '\0' 까지 읽어올 수 있었다

#include <iostream>
#include <string>

using namespace std;

int main()
{
  string formula;
  cin >> formula;

  int i;
  int sum = 0;
  string p = "";
  bool minus = false;
  for(i = 0; i <= formula.size(); i++)
  {
    if(formula[i] == '-' || formula[i] == '+' || formula[i] == '\0')
    {
      if(minus)
      {
        int n = stoi(p);
        sum -= n;
      }
      else
      {
        int n = stoi(p);
        sum += n;
      }
      p = "";

      if(formula[i] == '-')
      {
        minus = true;
      }
      continue;
    }

    p += formula[i];
  }

  cout << sum << endl;
  return 0;
}
