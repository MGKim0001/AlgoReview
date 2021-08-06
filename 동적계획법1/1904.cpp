// 01타일
// fn = fn-1 + fn-2 라는 법칙을 따라 가능한 경우를 저장하면 된다
// 이런 법칙이 생기는 이유는 간단하다
// fn-1안에 있는 숫자들의 앞뒤에 fn-2에 있는 숫자들을 붙여 만들어지는 것이 fn이기 때문이다

#include <iostream>
#define DIV 15746
#define MAX 1000001
using namespace std;

int n;
int cache[MAX];

void tiles()
{
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        cache[i] = cache[i-1] + cache[i-2];
        cache[i] = cache[i] % DIV;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    tiles();
    cout << cache[n] << endl;

    return 0;
}
