//이전에 푼 문제와 비슷하여 풀이방법이 쉽게 생각났음
//dp는 많이 풀수록 유리한 것 같음
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num; cin >> num;
    int arr[1003];
    int dp[1003];
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    for(int i = 2 ; i <= num ; i++)
    {
        dp[i] = arr[i];
        for(int j = 1 ; j < i ; j++)
        {
            dp[i] = min(dp[i],dp[j]+arr[i-j]);
        }
    }
    cout << dp[num];
}


