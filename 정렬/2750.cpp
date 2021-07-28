// 수 정렬하기
// O(n^2) 정렬들을 구현하라
// Selection Sort - 선택 정렬 - 가장 작은 값을 연속으로 찾는다
// Bouble Sort - 버블 정렬 - 인접한 두 수를 비교해서 큰 값을 뒤로 보내는 것을 반복한다
// Insertion Sort - 삽입 정렬 - 간단히 자신보다 작은 숫자가 나올 때까지 swap을 반복한다
// Shell Sort - 셀 정렬 - 삽입 정렬과 병합 정렬을 합한 정렬 알고리즘이다

#include <iostream>
#define MAXIMUM 1001

using namespace std;

int n;
int input[MAXIMUM];

void selectionSort(int uns[])
{
  for(int i = 0; i < n; i++)
  {
    int temp = i;
    for(int j = i+1; j < n; j++)
    {
      if(uns[temp] >= uns[j])
      {
        temp = j;
      }
    }
    swap(uns[temp], uns[i]);
  }
}

void boubleSort(int uns[])
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 1; j < n-i; j++)
    {
      if(uns[j-1] > uns[j])
      {
        swap(uns[j-1], uns[j]);
      }
    }
  }
}

void insertionSort(int uns[])
{
  for(int i = 1; i < n; i++)
  {
    int key = uns[i];
    int j = i-1;
    for(; j >= 0 && key < uns[j]; j--)
    {
      swap(uns[j], uns[j+1]);
    }
    uns[j+1] = key;
  }
}

void gap_insertion_sort(int uns[], int first, int last, int gap)
{
  for(int i = first+gap; i <= last; i += gap)
  {
    int key = uns[i];
    int j = i-gap;
    for(; j >= first && key < uns[j]; j -= gap)
    {
      swap(uns[j], uns[j+gap]);
    }
    uns[j+gap] = key;
  }
}

void shellSort(int uns[])
{
  int i, gap;

  for(gap = n/2; gap > 0; gap /= 2)
  {
    if((gap%2) == 0)
    {
      gap++;
    }

    for(i = 0; i < gap; i++)
    {
      gap_insertion_sort(uns, i, n-1, gap);
    }
  }
}

int main()
{
  cin >> n;
  int i;
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;
    input[i] = e;
  }

  //selectionSort(input);
  //boubleSort(input);
  //insertionSort(input);
  shellSort(input);

  for(int i = 0; i < n; i++)
  {
    cout << input[i];
  }

  return 0;
}
