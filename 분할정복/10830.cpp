// 행렬 제곱
// 행렬 곱셈을 사용하여 제곱을 구한다
// 제곱을 구할 때는 제곱번 만큼 작업을 수행하지 않고 반씩 나눠서 수행한다

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator * (matrix m1, matrix m2)
{
    if(m1[0].size() != m2.size())
    {
      matrix nullm (1, vector<long long> (1));
      return nullm;
    }

    long long rows = m1.size();
    long long cols = m2[0].size();
    long long mids = m1[0].size();

    matrix res(rows, vector<long long> (cols));

    long long i, j, k;
    for(i = 0; i < rows; i++)
    {
      for(j = 0; j < cols; j++)
      {
        for(k = 0; k < mids; k++)
        {
          res[i][j] += m1[i][k] * m2[k][j];
        }
        res[i][j] %= 1000;
      }
    }

    return res;
}

matrix pow(matrix m, long long power)
{
  long long size = m.size();
  matrix res(size, vector<long long> (size));

  long long i;
  for(i = 0; i < size; i++)
  {
    res[i][i] = 1;
  }

  while(power > 0)
  {
    if(power%2)
    {
      res = res*m;
    }

    power /= 2;
    m = m*m;
  }

  return res;
}

int main()
{
  long long n, b;
  cin >> n >> b;

  matrix m1(n, vector<long long> (n));
  long long i, j;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      cin >> m1[i][j];
    }
  }

  matrix m2 = pow(m1, b);
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      cout << m2[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
