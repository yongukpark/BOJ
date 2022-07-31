//난이도에 비해 쉬웠던 것 같음
//다른 dp에 비해 아이디어 떠올리는 것도 
#include <iostream>
#include <cmath>
using namespace std;

int dp[33][16000];
int arr[33];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int num1; cin >> num1;
    for(int i = 1 ; i <= num1 ; i++)
    {
        cin >> arr[i];
    }
    
    dp[1][arr[1]] = 1;
    for(int i = 2 ; i <= num1 ; i++)
    {
        dp[i][arr[i]] = 1; 
        for(int j = 1 ; j <= 15000 ; j++)
        {
            if(dp[i-1][j] == 1)
            {
                dp[i][abs(j-arr[i])] = 1;
                dp[i][j+arr[i]] = 1;
                dp[i][j] = 1;
            }
        }
    }
    int num2; cin >> num2;
    for(int i = 0 ; i < num2 ; i++)
    {
        int a;
        cin >> a;
        if(dp[num1][a])
        {
            cout << "Y"<<'\n';
        }
        else
        {
            cout << "N" << '\n';
        }
    }
}
