//비슷한 유형의 문제를 앞서 풀어봤기에 어렵지 않게 풀수 있었음
//dp는 정말 다양한 유형의 문제를 풀며 시각을 넓히는게 중요한 것 같음
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[53];
    int dp[53][1003];
    int num,start,maxi;
    cin >> num >> start >> maxi;
    for(int i = 1 ; i <= num ; i++) //input
    {
        cin >> arr[i];
    }
    
    for(int i = 1 ; i <= num ; i++) //initialization dp
    {
        for(int j = 0 ; j <= maxi ; j++)
        {
            dp[i][j] = 0;
        }
    }
    
    dp[0][start] = 1;
    
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 0 ; j <= maxi ; j++)
        {
            if(dp[i-1][j] == 1)
            {
                if(j+arr[i] <= maxi)
                {
                    dp[i][j+arr[i]] = 1;
                }
                if(j-arr[i] >= 0)
                {
                    dp[i][j-arr[i]] = 1;
                }
            }
        }
    }
    
    for(int i = maxi ; i >= 0 ; i--)
    {
        if(dp[num][i] == 1)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;

}

