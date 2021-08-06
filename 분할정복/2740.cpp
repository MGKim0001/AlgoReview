// 행렬 곱셈
// 슈르라센 알고리즘을 사용할 수도 있지만 그냥 곱해도 통과된다

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

    int i, j, k;
    for(i = 0; i < rows; i++)
    {
      for(j = 0; j < cols; j++)
      {
        for(k = 0; k < mids; k++)
        {
          res[i][j] += m1[i][k] * m2[k][j];
        }
      }
    }

    return res;
}

int main()
{
  long long r1, c1;
  cin >> r1 >> c1;

  matrix m1(r1, vector<long long> (c1));
  long long i, j;
  for(i = 0; i < r1; i++)
  {
    for(j = 0; j < c1; j++)
    {
      cin >> m1[i][j];
    }
  }

  long long r2, c2;
  cin >> r2 >> c2;

  matrix m2(r2, vector<long long> (c2));
  for(i = 0; i < r2; i++)
  {
    for(j = 0; j < c2; j++)
    {
      cin >> m2[i][j];
    }
  }

  matrix m3 = m1*m2;
  for(i = 0; i < r1; i++)
  {
    for(j = 0; j < c2; j++)
    {
      cout << m3[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
