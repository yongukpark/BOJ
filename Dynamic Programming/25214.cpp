//IUPC문제임
//예제를 보고 DP라는 힌트를 얻어 풀었음 
//DP문제라는 것을 안 이후에는 문제풀기가 
#include <iostream>
#include <cmath>
using namespace std;

int arr[200001];
int dp[200001];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num; cin >> num;
    int mini;
    cin >> mini;
    arr[0] = mini;
    dp[0] = 0;
    cout << dp[0] <<' ';
    for(int i = 1 ; i < num ; i++)
    {
        cin >> arr[i];
        if(arr[i] < mini)
        {
            mini = arr[i];
            dp[i] = dp[i-1];
        }
        else{
            dp[i] = max(dp[i-1],arr[i]-mini);
        }
        cout << dp[i] << ' ';
    }
}

