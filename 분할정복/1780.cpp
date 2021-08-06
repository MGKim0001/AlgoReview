// 종이의 개수
// 색종이 만들기 문제에서 -1을 처리해주는 부분만 추가하면 된다

#include <iostream>
#define MAX_SIZE 2187

using namespace std;

void divide(int arr[][MAX_SIZE], int n, int x, int y, int* count)
{
  int i, j;
  bool c1 = false;
  bool c2 = false;
  bool c3 = false;

  for(i = y; i < y+n; i++)
  {
    for(j = x; j < x+n; j++)
    {
      if(arr[i][j] == 1)
      {
          c1 = true;
      }
      else if(arr[i][j] == 0)
      {
          c2 = true;
      }
      else if(arr[i][j] == -1)
      {
          c3 = true;
      }
    }
  }

  if(!c1 && !c2 && c3)
  {
    count[0] += 1;
  }
  else if(!c1 && c2 && !c3)
  {
    count[1] += 1;
  }
  else if(c1 && !c2 && !c3)
  {
    count[2] += 1;
  }
  else
  {
    int offset = n/3;

    divide(arr, offset, x, y, count);
    divide(arr, offset, x+offset, y, count);
    divide(arr, offset, x+(2*offset), y, count);
    divide(arr, offset, x, y+offset, count);
    divide(arr, offset, x, y+(2*offset), count);
    divide(arr, offset, x+offset, y+offset, count);
    divide(arr, offset, x+(2*offset), y+(2*offset), count);
    divide(arr, offset, x+offset, y+(2*offset), count);
    divide(arr, offset, x+(2*offset), y+offset, count);
  }
  return;
}

int main()
{
  int n;
  cin >> n;

  int arr[n][MAX_SIZE];
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

  int count[3] = {0,};
  divide(arr, n, 0, 0, count);
  cout << count[0] << endl;
  cout << count[1] << endl;
  cout << count[2] << endl;
  return 0;
}
