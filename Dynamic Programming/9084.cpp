//생각하는데 오래걸렸지만 직접 생각해낸것에 만족함
//중복되는 값들을 어떻게 제거해야하는지에 대해 오래 
#include <iostream>
#include <cmath>
using namespace std;
int dp[23][10003];
int arr[23];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    int testCase; cin >> testCase;
    for(int i = 0 ; i <testCase ; i++)
    {
        int num; cin >> num;
        
        for(int j = 1 ; j <= num ; j++)
        {
            cin >> arr[j];
        }
        
        int goal; cin >> goal;

        for(int j = 1 ; j <= num ; j++)
        {
            for(int k = 1 ; k <= goal ; k++)
            {
                if(arr[j] == k)
                {
                    dp[j][k] = dp[j-1][k] + 1;
                }
                else if(arr[j] > k)
                {
                    dp[j][k] = dp[j-1][k];
                }
                else
                {
                    dp[j][k] = dp[j-1][k] + dp[j][k-arr[j]];
                }
            }
        }
        cout << dp[num][goal] << '\n';
    }
}
