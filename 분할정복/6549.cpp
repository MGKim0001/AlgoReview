// 히스토그램에서 가장 큰 직사각형
// 분할정복과 스택을 이용하여 풀 수 있다
// 분할정복을 사용해서 풀 경우 히스토그램을 절반씩 나눠가면서 넓이를 구하는 방식으로 해결한다
// 스텍을 사용할 경우 가장 낮은 높이만을 스텍에 저장해 가면서 넓이를 구한다
// 분할정복을 사용할 경우 시간초과가 떠서 스텍을 사용하여서 풀었다

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long getMin(long long a, long long b)
{
  return a < b ? a : b;
}

long long getMax(long long a, long long b)
{
  return a > b ? a : b;
}

long long getMidArea(vector<long long> hs, long long l, long long r, long long m)
{
  long long height = hs[m];
  long long ret = hs[m];
  long long left = m;
  long long right = m;
  long long area = 0;

  while(l < left && right < r)
  {
    if(hs[left-1] < hs[right+1])
    {
      right++;
      height = getMin(height, hs[right]);
    }
    else
    {
      left--;
      height = getMin(height, hs[left]);
    }

    area = (right - left + 1)*height;
    ret = getMax(ret, area);
  }

  while(l < left)
  {
    left--;
    height = getMin(height, hs[left]);
    area = (right - left + 1)*height;
    ret = getMax(ret, area);
  }

  while(r > right)
  {
    right++;
    height = getMin(height, hs[right]);
    area = (right - left + 1)*height;
    ret = getMax(ret, area);
  }

  return ret;
}

long long getAreaDC(vector<long long> hs, long long l, long long r)
{
  if(l == r)
  {
    return hs[0];
  }

  long long mid = (l + r)/2;
  long long leftArea = getAreaDC(hs, l, mid);
  long long rightArea = getAreaDC(hs, mid+1, r);

  long long ret = getMax(leftArea, rightArea);
  ret = getMidArea(hs, l, r, mid);

  return ret;
}

long long getAreaS(long long len, vector<long long> hs)
{
  stack<long long> temp;

  long long ret = 0;
  long long i;
  for(i = 0; i < len; i++)
  {
      while(!temp.empty() && hs[temp.top()] >= hs[i])
      {
        long long height = hs[temp.top()];
        temp.pop();

        long long width = temp.empty() ? i : i - 1 - temp.top();
        ret = getMax(ret, width*height);
      }

      temp.push(i);
  }

  while(!temp.empty())
  {
    long long height = hs[temp.top()];
    temp.pop();

    long long width = temp.empty() ? i : i - 1 - temp.top();
    ret = getMax(ret, width*height);
  }

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n = 1;

  while(n != 0)
  {
    cin >> n;
    if(n == 0)
    {
      break;
    }

    vector<long long> heights(n);

    int i;
    for(i = 0; i < n; i++)
    {
      cin >> heights[i];
    }

    //long long area = getAreaDC(heights, 0, n-1);
    long long area = getAreaS(n, heights);
    cout << area << '\n';
  }

  return 0;
}
