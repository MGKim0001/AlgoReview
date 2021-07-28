// 분해합
// 브루트 포스 문제
// 브루트 포스 문제이기 때문에 n 부터 0까지 돌면서 조건에 만족하는 생성자를 찾는다
// 문자를 숫자로 바꾸는 부분과 ans를 찾는 부분에서 에러가 있었다 if(sum == n && ans > sum)

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 9999;
    for(int i = n; i > 0; i--)
    {
        string str = to_string(i);
        int sum = i;
        for(int j = 0; j < str.length(); j++)
        {
            sum += str.at(j)-'0';
        }
        if(sum == n)
            ans = i;
    }

    if(ans == 9999)
        ans = 0;

    cout << ans << endl;
    return 0;
}
