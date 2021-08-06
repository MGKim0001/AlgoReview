// 색종이 만들기
// 쿼드트리의 기본 문제로 재귀함수를 통해
// 정사각형이 되는 0과 1이 몇 개 인지 세어주면 된다

#include <iostream>

using namespace std;

void divide(int arr[][129], int n, int x, int y, pair<int, int>* count)
{
  int i, j;
  bool wc = true;
  bool bc = true;

  for(i = y; i < y+n; i++)
  {
    for(j = x; j < x+n; j++)
    {
      if(arr[i][j] == 1)
      {
          bc = false;
      }
      else
      {
          wc = false;
      }

      if(!bc && !wc)
      {
        break;
      }
    }

    if(!bc && !wc)
    {
      break;
    }
  }

  if(bc)
  {
    count->first += 1;
  }
  else if(wc)
  {
    count->second += 1;
  }
  else
  {
    divide(arr, n/2, x, y, count);
    divide(arr, n/2, x+n/2, y, count);
    divide(arr, n/2, x, y+n/2, count);
    divide(arr, n/2, x+n/2, y+n/2, count);
  }
}

int main()
{
  int n;
  cin >> n;

  int arr[129][129];
  int i, j;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++)
    {
      int e;
      cin >> e;
      arr[i][j] = e;
    }
  }

  pair<int, int> count = make_pair(0, 0);
  divide(arr, n, 0, 0, &count);
  cout << count.first << endl;
  cout << count.second << endl;
  return 0;
}
