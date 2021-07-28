// 수 정렬하기 2
// O(n log n) 시간복잡도를 가지는 정렬을 수행해야 한다
// Merger Sort - 병합 정렬 - 분할과 병합 두 단계로 나뉜다
// 분할 - 크기가 1이 될 때가지 나눈다
// 병합 - 큰 요소를 앞으로 작은 요소를 뒤로 보내면서 합한다

// Quick Sort - 퀵 정렬
// 분할 - pivot 값을 정하고 pivot 보다 작은 값은 앞으로, 큰 값은 뒤로 넣는다
// 병합 - 나뉜 순서대로 병합한다

// Heap Sort - 힙 정렬
// 완전 이진트리를 사용하여 넣는 순서대로 정렬한다

// 구현보다는 시간제한을 맞추는 것이 더 빡빡했던 문제
// cout 대신 printf를 사용해서 풀었다

#include <iostream>
#include <vector>
#include <algorithm>
#define MAXIMUM 1001

using namespace std;


int n;
int input[MAXIMUM];
int heap_size;

void merge(int uns[], int left, int mid, int right)
{
    int sorted[MAXIMUM];

    // 비교 후 작은 것 부터 넣는다.
    int i = left, j = mid+1, k = left;
    while(i <= mid && j <= right)
    {
      if(uns[i] <= uns[j])
      {
        sorted[k++] = uns[i++];
      }
      else
      {
        sorted[k++] = uns[j++];
      }
    }

    // 남은 요소 정리
    int l;
    if(i > mid)
    {
      for(l = j; l <= right; l++)
      {
        sorted[k++] = uns[l];
      }
    }
    else
    {
      for(l = i; l <= mid; l++)
      {
        sorted[k++] = uns[l];
      }
    }

    // 원래 배열로 옮겨 준다
    for(l = left; l <= right; l++)
    {
      uns[l] = sorted[l];
    }
}

void mergeSort(int uns[], int left, int right)
{
    int mid;
    if(left < right)
    {
      mid = (left + right)/2;
      mergeSort(uns, left, mid);
      mergeSort(uns, mid+1, right);
      merge(uns, left, mid, right);
    }
}

int partition(int uns[], int left, int right)
{
  int low = left+1, high = right, pivot = uns[left];

  do
  {
    do
    {
      low += 1;
    } while(low <= right && uns[low] < pivot);

    do {
      high -= 1;
    } while(high >= left && uns[high] > pivot);

    if(low < high)
    {
        swap(uns[low], uns[high]);
    }
  } while(low < high);

  swap(uns[left], uns[high]);
  return high;
}

void quickSort(int uns[], int left, int right)
{
  if(left < right)
  {
    int q = partition(uns, left, right);

    quickSort(uns, left, q-1);
    quickSort(uns, q+1, right);
  }
}

void heapSort_in(int num)
{
  int i = ++heap_size;

  while((i != 1) && num < input[i/2])
  {
    swap(input[i], input[i/2]);
    i = i/2;
  }
  input[i] = num;
}

int heapSort_out()
{
  int parent = 1, child = 2;
  int item = input[1];
  int temp = input[heap_size--];

  while(child <= heap_size)
  {
    if((child < heap_size) && input[child] > input[child+1])
    {
      child += 1;
    }

    if(temp <= input[child])
    {
      break;
    }

    swap(input[parent], input[child]);
    parent = child;
    child *= 2;
  }

  input[parent] = temp;
  return item;
}

void heapSort(int uns[])
{
    int i;
    int ret[n];

    heap_size = 0;

    for(i = 0; i < n; i++)
    {
      heapSort_in(uns[i]);
    }

    for(i = 0; i < n; i++)
    {
      ret[i] = heapSort_out();
    }

    for(i = 0; i < n; i++)
    {
      input[i] = ret[i];
    }

}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int i;
  cin >> n;
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    input[i] = e;
  }

  mergeSort(input, 0, n-1);
  //quickSort(input, 0, n-1);
  //heapSort(example);
  //sort_heap(vv.begin(), vv.end());

  //n = 10;
  //vector<int> vv = {10, 9, 7, 5, 1, 2, 3, 6, 8, 4};
  //qsort(vv, n, sizeof(int), compare);

  for(i = 0; i < n; i++)
  {
    cout << input[i] << "\n";
  }

  return 0;
}
