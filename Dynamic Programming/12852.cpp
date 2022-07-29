//워낙 많이 나온 유형이라 어렵지 않게 풀수 있었음
#include <iostream>
#include <cmath>
using namespace std;

int dp[1000003];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4 ; i <= num ; i++)
    {
        dp[i] = dp[i-1]+1;
        if(i%2==0)
        {
            dp[i] = min(dp[i],dp[i/2]+1);
        }
        if(i%3==0)
        {
            dp[i] = min(dp[i],dp[i/3]+1);
        }
    }
    cout << dp[num] << '\n';
    
    int count = dp[num]-1;
    cout << num << ' ';
    while(num != 1)
    {
        if(num%3 == 0 && dp[num/3] == count)
        {
            cout << num/3 << ' ';
            num = num/3;
            count--;
            continue;
        }
        if(num%2 == 0 && dp[num/2] == count)
        {
            cout << num/2 << ' ';
            num = num/2;
            count--;
            continue;
        }
        cout << num - 1 << ' ';
        num -= 1;
        count --;
        
    }
    
}
