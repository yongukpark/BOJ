//피보나치 수열을 따르는 공식이었고 떠올리는데에는 쉬웠음
//하지만 예외처리나 구현하는 과정에서 조금 애를 
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s = "";
    cin >> s;
    
    if(s[0] == '0')
    {
        cout << 0;
        return 0;
    }
    
    int dp[5001];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 1 ; i < s.length() ; i++)
    {
        if(s[i] == '0')
        {
            if(s[i-1]=='1' || s[i-1] == '2')
            {
                dp[i+1] = dp[i-1]%1000000;
                continue;
            }
            else
            {
                cout<< 0;
                return 0;
            }
        }
        
        if(s[i-1] == '1')
        {
            dp[i+1] = (dp[i] + dp[i-1])%1000000;
            continue;
        }
        else if(s[i-1] == '2')
        {
            if(s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' ||s[i] == '5' ||s[i] == '6')
            {
                dp[i+1] = (dp[i] + dp[i-1])%1000000;
                continue;
            }
        }
        dp[i+1] = dp[i];
    }
    cout << dp[s.length()]%1000000;
}
