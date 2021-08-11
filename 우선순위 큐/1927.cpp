// 최소 힙
// 최소힙을 구현한다

#include <iostream>
#include <vector>

using namespace std;

int arr[100001];
int heapsize;

void heapsort_in(int e)
{
  heapsize += 1;
  arr[heapsize] = e;

  int child = heapsize;
  int parent = child/2;
  while(child > 1 && arr[parent] > arr[child])
  {
    swap(arr[parent], arr[child]);
    child = parent;
    parent = child/2;
  }
}

int heapsort_out()
{
  int ret = arr[1];
  swap(arr[1], arr[heapsize]);
  heapsize -= 1;

  int parent = 1, child = 2;
  if(child+1 <= heapsize)
  {
    child = arr[child] < arr[child+1] ? child : child+1;
  }

  while(child <= heapsize && arr[child] < arr[parent])
  {
    swap(arr[parent], arr[child]);
    parent = child;
    child *= 2;

    if(child+1 <= heapsize)
    {
      child = arr[child] < arr[child+1] ? child : child+1;
    }
  }

  return ret;
}

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);

  heapsize = 0;

  int n;
  cin >> n;

  int i;
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;

    if(e == 0)
    {
      if(heapsize == 0)
      {
        cout << "0\n";
      }
      else
      {
        int ret = heapsort_out();
        cout << ret << '\n';
      }
    }
    else
    {
      heapsort_in(e);
    }
  }
  return 0;
}
