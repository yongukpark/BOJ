//이 문제는 bfs로 간단하게 풀 수 있었지만 기본적으로 dp문제로 출제된 문제임 
//dp로 풀 경우 이러한 형식으로 풀수 있음
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

 

