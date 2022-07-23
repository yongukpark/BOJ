//가장 기본적인 dp문제였음
//bottom-up으로 간단하게 풀수 있음
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int arr[1001]; 
    int dp[1001];
    
    int num;
    cin >> num;
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> arr[i];
    }
    
    dp[0] = 0;
    dp[1] = arr[1];
    
    for(int i = 2 ; i <= num ; i++)
    {
        int maxi = arr[i];
        for(int j = 1 ; j < i ; j++)
        {
            maxi = max(maxi, dp[i-j] + dp[j]);
        }
        dp[i] = maxi;
    }
    cout << dp[num];
}
