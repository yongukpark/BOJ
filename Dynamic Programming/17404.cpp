//난이도에 비해 생각보다 점화식이나 구현난이도가 쉬웠다고 생각함
//각각 시작을 R,G,B 일 경우 3가지 모두 해본 후 그중 가장 최솟값만 찾으면 되는 문제였음

#include <iostream>
using namespace std;

int arr[1003][3];
int dp[1003][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int num; cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    
    dp[0][0] = arr[0][0];
    dp[0][1] = 10001;
    dp[0][2] = 10001;
    
    for(int i = 1 ; i < num; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    
    int res = min(dp[num-1][1] , dp[num-1][2]);
    
    dp[0][0] = 10001;
    dp[0][1] = arr[0][1];
    dp[0][2] = 10001;
    
    for(int i = 1 ; i < num; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }

    int tmp = min(dp[num-1][0] , dp[num-1][2]);
    res = min(tmp,res);
    
    dp[0][0] = 10001;
    dp[0][1] = 10001;
    dp[0][2] = arr[0][2];
    
    for(int i = 1 ; i < num; i++)
    {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    
    tmp = min(dp[num-1][0] , dp[num-1][1]);
    res = min(tmp,res);
    
    cout << res;
}
