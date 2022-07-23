//어떻게 풀어야하느지 감은 왔지만 어떻게 구현해야할지 생각하는데 조금 어려움을 겪음
//생각해내서 풀었지만 틀렸었고 인터넷으로 구현에 대한 힌트를 얻음
//원리는 나와 같았지만 구현하는 방식이 달라 그 사이 어딘가에서 답이 틀린 것 같음
//이런유형의 dp문제를 많이 본 것 같아 이 방식은 한번더 짚고 넘어갈 필요가 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[100001][2];
int dp[100001][2];  

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  
    
    int testCase;
    cin >> testCase;
    for(int j = 0 ; j < testCase ; j++)
    {
        int num; cin >> num;
        for(int i = 0 ; i < num ; i++)
        {
            cin >> arr[i][0];  
        }
        for(int i = 0 ; i < num ; i++)
        {
            cin >> arr[i][1];
        }
        
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = arr[0][0];
        dp[1][1] = arr[0][1];
        
        for(int i = 2 ; i <= num ; i++)
        {
            dp[i][0] = arr[i-1][0] + max(dp[i-1][1] , dp[i-2][1]);
            dp[i][1] = arr[i-1][1] + max(dp[i-1][0] , dp[i-2][0]);
        }
        cout << max(dp[num][0],dp[num][1]) << '\n';
    }
}
