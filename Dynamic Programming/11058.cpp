//수준 높은 문제였다고 생각함
//dp를 어떻게 만들어야할지에 대해 꽤 오래 고민한 것 같음

#include <iostream>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    long long dp[103];
    int num; cin>> num;
    
    dp[0] = 0;
    
    for(int i = 1 ; i <= num ; i++)
    {
        dp[i] = dp[i-1]+1;
        for(int j = 3 ; j <= i ; j++)
        {
            dp[i] = max(dp[i - j]*(j-1),dp[i]);
        }
    }
    cout << dp[num];
}
