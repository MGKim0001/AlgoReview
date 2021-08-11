// 수 찾기
// 이분탐색으로 배열 내에 있는 수를 찾으면 된다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(int num, int *arr, int n)
{
  int l = 0, r = n-1;
  int mid;

  while(l <= r)
  {
    mid = (l+r)/2;

    if(num == arr[mid])
    {
      return 1;
    }

    if(num < arr[mid])
    {
      r = mid-1;
    }
    else if(num > arr[mid])
    {
      l = mid+1;
    }
  }

  return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n;

  int arr[n];
  int i;
  for(i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr, arr+n);

  cin >> m;
  for(i = 0; i < m; i++)
  {
    int e;
    cin >> e;
    int ret = binSearch(e, arr, n);
    printf("%d\n", ret);
  }
  return 0;
}
