// 양팔저울
// dfs를 사용해서 세 가지 경우에 대해 검사해 주었다
// 구슬을 왼쪽에 놓고 추를 오른쪽에 놓는다고 할 때
// 첫번째 경우는 추가 더해지는 경우 (오른쪽에 추를 놓는 경우)
// 두번째 경우는 구슬의 무게와 추의 무게가 같아지는 경우 (저울이 수평에 위치하는 경우)
// 세번째 경우는 구슬과 추를 함께 놓는 경우 (왼쪽에 추를 놓는 경우)
// 이 세 가지 경우를 각각 추의 개수와 무게를 중심으로 구해주었다

#include <iostream>

using namespace std;

int n, k, bead;
int weights[31];
int visits[31][15001];

void dfs(int cnt, int res)
{
  if(cnt > n) return;
  if(visits[cnt][res] == true) return;

  visits[cnt][res] = true;

  dfs(cnt+1, res+weights[cnt]);
  dfs(cnt+1, res);
  dfs(cnt+1, abs(res-weights[cnt]));
}

int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  int i;
  for(i = 0; i < n; i++)
  {
    cin >> weights[i];
  }

  dfs(0, 0);

  cin >> k;
  for(i = 0; i < k; i++)
  {
    cin >> bead;

    if(bead > 15000) printf("N ");
    else if(visits[n][bead]) printf("Y ");
    else printf("N ");
  }

  return 0;
}
