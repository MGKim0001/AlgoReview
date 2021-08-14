// 파일 합치기
// 파일을 합치는 방법 중 가장 비용이 적게 드는 방법을 찾는 문제다
// O(N^3)으로 푸는 방법과 O(N^2)으로 푸는 방법이 있다
// 앞뒤에 있는 파일하고만 합칠 수 있다

// O(N^3)
// 파일을 나누어가면서 더할 수 있는 최소값을 구하는 것이기 때문에
// 시작점과 끝점 그리고 그 중간점을 정해주어야 한다
// dp[시작점][사이즈] 이렇게 동적계획법을 진행해가면서 각 시작점과 사이즈 별로 최소값을 저장한다
// 부분합을 더해주는 이유는 start 부터 end 까지의 최소값을 구한 뒤
// 0부터 start까지의 합을 더해야줘야 하기 때문이다

// O(N^2)
// N^3 시간이 걸리는 해법을 Knuth Optimization을 통해 최적화 해준다
// Knuth Optimization을 사용할 수 있는 해답은 몇 가지 조건이 갖추어 졌을 때다
// 먼저 부분의 합을 구하는 문제일 때 가능하며 (dp[i][j] = dp[st][mid] + dp[mid+1][en] + psum[st][en])
// 그리고 여러가지 표현법이 있을 수 있지만 결국 부분합 (psum)이 증가할 때 가능하다

// 위와같은 조건이 갖추어 진다면 중간값의 범위를 시작점부터 끝점까지의 범위에서
// [st][en-1] <= [st][en] <= [st+1][en] 까지의 법위로 좁힐 수 있게 된다
// 이 범위는 사실상 상수 범위이기 때문에 O(N^2)안에 실행항 수 있게 된다
// 이때 주의해야할 점은 점화식이 dp[st][mid] + dp[mid][en]로 바뀐다는 점이다
// 또한 size는 2부터 start는 0부터 시작해야 한다

#include <iostream>

using namespace std;

void nko(int sum[], int k)
{
	int dp[501][501];
	int kth[501][501];

	int j;
	for(j = 1; j <= k; j++)
	{
		kth[j-1][j] = j;
	}

	int start, size, mid;
	for(size = 2; size <= k; size++)
	{
		for(start = 0; start+size <= k; start++)
		{
			int end = start+size;
			dp[start][end] = 987654321;

			for(mid = kth[start][end-1]; mid <= kth[start+1][end]; mid++)
			{
				int temp = dp[start][mid] + dp[mid][end] + sum[end] - sum[start];

				if(dp[start][end] > temp)
				{
					dp[start][end] = temp;
					kth[start][end] = mid;
				}
			}
		}
	}

	cout << dp[0][k] << '\n';
}

void nthrid(int sum[], int k)
{
	int dp[501][501];

	int start, size, mid;
	for(size = 1; size <= k; size++)
	{
		for(start = 1; start+size <= k; start++)
		{
			int end = start+size;
			dp[start][end] = 987654321;

			for(mid = start; mid <= end; mid++)
			{
				dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid+1][end] + sum[end] - sum[start-1]);
			}
		}
	}

	cout << dp[1][k] << '\n';
}

int main()
{

	int sum[501];

	int n, k;
	cin >> n;

	int i, j;
	for(i = 0; i < n; i++)
	{
		cin >> k;

		for(j = 1; j <= k; j++)
		{
			int e;
			cin >> e;
			sum[j] = sum[j-1] + e;
		}

		// nthrid(sum, k);
		nko(sum, k);
	}
	return 0;
}
