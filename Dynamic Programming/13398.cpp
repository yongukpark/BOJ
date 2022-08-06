//난이도에 비해 굉장히 쉬운것 같았음
//주의할점은 결과값을 초기값으로 배열의 첫값을 넣어야함

#include <iostream>
#include <cmath>
using namespace std;

int dp[100001][2];   
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    
    int res = -1000000000;
    int num;
    cin >> num;
    for(int i = 1 ; i <= num ; i++)
    {
        int a;
        cin >> a;
        if(i == 1)
        {
            dp[1][0] = a;
            dp[1][1] = 0;
            res = a;
            continue;
        }
        
        dp[i][0] = max(dp[i-1][0] + a , a);
        dp[i][1] = max(dp[i-1][1] + a, dp[i-1][0]);
        res = max(res,dp[i][0]);
        res = max(res,dp[i][1]);
    }
    cout << res;
}
