//진짜 운 좋게 맞춘것 같음
//논리적인 방법을 찾는것이 조금 어려웠던 문제였던 것 같지만 운좋게 아이디어를 쉽게 떠올렸고 구현도 크게 어렵지 않았음

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

char arr[1001][1001];
int dp[1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int row, col;
    cin >> row >> col;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == '1')
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i = 1 ; i < row ; i++)
    {
        for(int j = 1 ; j < col ; j++)
        {
            if(arr[i][j] == '1' && arr[i][j-1] == '1' && arr[i-1][j] == '1')
            {
                dp[i][j] = min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}) + 1;
            }
        }
    }
    
    int res = 0;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            res = max(res,dp[i][j]);
        }
    }
    cout << pow(res,2);
}
