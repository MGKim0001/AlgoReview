// 링
// 첫번째 숫자 / 나머지 숫자 를 분수형으로 출력한다

#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
  while(b != 0)
  {
    int r = a%b;
    a = b;
    b = r;
  }
  return a;
}

int main()
{
  int n;
  cin >> n;

  int i;
  vector<int> vv(n);
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    vv[i] = e;
  }

  int first = vv[0];
  vector<string> vs(n-1);
  for(i = 1; i < n; i++)
  {
    string str = "";
    int div = first/vv[i];
    int mod = first%vv[i];

    if(mod == 0)
    {
      str = to_string(div) + "/1";
    }
    else
    {
      int g = gcd(first, vv[i]);
      int first_div = first/g;
      int second_div = vv[i]/g;
      str = to_string(first_div) + "/" + to_string(second_div);
    }

    vs[i-1] = str;
  }

  for(i = 0; i < n-1; i++)
  {
    cout << vs[i] << endl;
  }
  return 0;
}
