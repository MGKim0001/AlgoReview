// 쿼드트리

#include <iostream>
#define MAX_SIZE 66
using namespace std;

void compress(int arr[][MAX_SIZE], int n, int x, int y)
{
  if(n == 1)
  {
    cout << arr[y][x];
    return;
  }

  int i, j;
  bool wc = true, bc = true;
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
    cout << 0;
  }
  else if(wc)
  {
    cout << 1;
  }
  else
  {
    cout << "(";
    compress(arr, n/2, x, y);
    compress(arr, n/2, x+n/2, y);
    compress(arr, n/2, x, y+n/2);
    compress(arr, n/2, x+n/2, y+n/2);
    cout << ")";
  }
  return;
}

int main()
{
  int n;
  cin >> n;

  int arr[MAX_SIZE][MAX_SIZE];
  int i, j;
  string s;
  for(i = 0; i < n; i++)
  {
    cin >> s;
    j = 0;
    for(char c : s)
    {
      int e = c - '\0' - 48;
      arr[i][j] = e;
      j++;
    }
  }

  compress(arr, n, 0, 0);

  return 0;
}
