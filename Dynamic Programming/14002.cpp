//DP는 진짜 너무 어려운 것 같고 아직 많이 부족하다는 것을 느낌
//가장 긴 수열에 대한 문제를 이전에 풀었음에도 불구하고 접근법이 쉽게 떠오르지 않았음
//인터넷을 보고 풀었지만 이문제는 출력이 핵심인 것 같음 출력하는 부분이 쉽게 떠오르지 않았고 출력하는 방법또한 신기했음
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int arr[1001];
    int dp[1001];
    
    int num; cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }
    
   
    int maxiIndex = 1;
    for(int i = 1 ; i < num ; i++)
    {
        for(int j = 0 ; j < i ; j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
            maxiIndex = max(maxiIndex,dp[i]);
        }
    }
    
    cout << maxiIndex << '\n';
    stack <int> s;
    for(int i = num - 1; i >= 0; i--)
    {
        if(maxiIndex == 0)
        {
            break;
        }
        if(dp[i] == maxiIndex)
        {
            s.push(arr[i]);
            maxiIndex--;
        }
    }
    while(!s.empty())
    {
        cout << s.top() << ' ';s.pop();
    }
}
