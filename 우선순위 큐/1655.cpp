// 가운데를 말해요
// 최대힙과 최소힙을 사용하여 문제를 해결한다
// 최대힙과 최소힙에 번갈아 가면서 값을 넣고
// 최대힙의 제일 위에 있는 값을 계속해서 출력하면 중간값이 출력된다

// 이 해법은 두가지 규칙 때문에 정답을 출력한다
// 첫번째 규직은 최대힙의 크기가 최소힙의 크기보다 항상 1 크다는 점이다
// 입력된 숫자를 절반으로 잘라서 작은 수는 최대힙에 저장되고 큰 수는 최소힙에 순서대로 저장된다
// 두번째 규칙 때문에 최대힙과 최소힙은 순서를 유지할 수 있다
// 입력된 최대힙의 값이 최소힙보다 크면 바꿔주는 것을 통해 절반씩 넣는 순서가 유지된다

#include <iostream>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  priority_queue<int> max_pq, min_pq;
  int i;
  for(i = 0; i < n; i++)
  {
    int e;
    cin >> e;

    if(max_pq.size() > min_pq.size())
    {
      min_pq.push(-e);
    }
    else
    {
      max_pq.push(e);
    }

    if(max_pq.empty() == false && min_pq.empty() == false)
    {
      if(max_pq.top() > -(min_pq.top()))
      {
        int max = max_pq.top();
        int min = -(min_pq.top());

        max_pq.pop();
        min_pq.pop();

        max_pq.push(min);
        min_pq.push(-max);
      }
    }

    printf("%d\n", max_pq.top());
  }
  return 0;
}
