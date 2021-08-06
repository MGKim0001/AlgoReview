// 피보나치 수 6
// {{1, 1}, {1, 0}} 행렬을 n-1번 제곱하면 된다

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
        res[i][j] %= 1000000007;
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long n;
  cin >> n;

  matrix a = {{1, 1}, {1, 0}};
  matrix ans = (pow(a, n-1));
  cout << (ans[1][0] + ans[1][1])%1000000007;
  return 0;
}
