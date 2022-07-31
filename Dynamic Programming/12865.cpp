//배낭 문제 
#include <iostream>
#include <cmath>
using namespace std;

int dp[103][100003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int w[103];
    int v[103];
    
    int num, weight;
    cin >> num >> weight;
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> w[i] >> v[i];
    }
    
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= weight ; j++)
        {
            if(w[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j-w[i]] + v[i] , dp[i-1][j]);
            }
        }
    }
    cout << dp[num][weight];
}
