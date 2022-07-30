//이것또한 유명한 dp문제이기에 푸는데에 수월했음
//다만 longlong을 사용하지 않아 시행착오를 
#include <iostream>
using namespace std;
long long dp[100001][4];    


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    int testCase; cin >> testCase;
    for(int i = 0 ; i < testCase ; i++)
    {
        int num; cin >> num;
        for(int i = 4 ; i <= num ; i++)
        {
            dp[i][1] = (dp[i-1][2] + dp[i-1][3]) %1000000009;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3]) %1000000009;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2]) %1000000009;
        }
        
        long long res = dp[num][1]+dp[num][2]+dp[num][3];
        cout << res%1000000009 << '\n';
    }
}

