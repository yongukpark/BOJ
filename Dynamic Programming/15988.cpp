//범위만 신경쓰면 어려울 것 없는 문제였음
//비슷한 유형의 문제를 많이 본적 있음
#include <iostream>

using namespace std;
long long dp[1000001];
int main()
{
    int testCase; cin>> testCase;
    for(int i = 0 ; i <testCase ;i++)
    {
        int num; cin>> num;
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for(int i = 4 ; i <= num ; i++)
        {
            dp[i] = (dp[i-1]+dp[i-2]+dp[i-3])%1000000009;
        }
            cout << dp[num] << '\n';
    }

}
