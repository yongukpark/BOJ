//bfs도 가능하고 dp도 가능한 문제임
//실전이었다면 상관없지만 연습이기에 dp로 하는 법도 알아두면 좋을 것 같음
#include <iostream>
using namespace std;

int dp[3][17][17]; //0가로 1세로 2대각선
int arr[17][17];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= num ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 2 ; i <= num ; i++)
    {
        if(arr[1][i] == 0)
        {
            dp[0][1][i] = 1;
        }
    }
    for(int i = 2 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= num ; j++)
        {
            if(arr[i][j]!=1)
            {
                dp[0][i][j] = dp[0][i][j-1] + dp[2][i][j-1];
                dp[1][i][j] = dp[1][i-1][j] + dp[2][i-1][j];
                if(arr[i-1][j] == 0 && arr[i][j-1]==0)
                {
                    dp[2][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1]; + dp[2][i-1][j-1];
                }
            }
        }
    }
    
    cout << dp[0][num][num] + dp[1][num][num] + dp[2][num][num];
}

 

