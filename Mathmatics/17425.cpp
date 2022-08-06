//수학적 개념은 쉽지만 알고리즘과 함께 생각하니 아이디어가 떠오르지 않았음

#include <iostream> 
using namespace std;

long long s[1000001];
long long dp[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 1 ; i <= 1000000 ; i++)
    {
        for(int j = 1 ; j * i <= 1000000 ; j++)
        {
            dp[i*j] += i;
        }
    }
    
    for(int i = 1 ; i <= 1000000 ; i++)
    {
        s[i] = s[i-1] + dp[i];
    }
    
    int testCase; cin >> testCase;
    for(int i = 0 ; i < testCase ; i++)
    {
        int a;
        cin >> a;
        cout << s[a] << '\n';
    }
}
