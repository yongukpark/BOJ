//구현은 쉽지만 생각하는데에 하루종일 걸린 문제임
//생긴게 LIS 같이 생겼었지만 이를 알아차리지 못하고 인터넷의 힘을 빌렸음
//오름차순으로 정렬된 아이들은 건들이지 않고 그렇지 않은 아이들만 이동시키는게 최소의 값이 었음
//즉 "전체 아이 - LIS"의 값이 결과값임 
#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[202];
    int dp[202];
    
    int num;
    cin >> num;
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> arr[i];
    }
    
    dp[1] = 1;
    for(int i = 2 ; i <= num ; i++)
    {
        dp[i] = 1;
        for(int j = 1 ; j < i ; j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= num ; i++)
    {
        res = max(dp[i],res);
    }
    cout << num - res;
}


