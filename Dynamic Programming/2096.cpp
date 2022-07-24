//문제는 푸는데는 어려움이 없었음
//허나 범위는 100000인데 총 메모리가 4mb인점을 고려해야하는데 한번 놓쳤음
//4mb면 int형(4byte) 1000000 이므로 전부다 입력받는것 조차 힘들다고 생각이되어 배열은 총 3*3개만 사용하여 해결함
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    
    int ii1,ii2,ii3;
    cin >> ii1 >> ii2 >> ii3;
    int dp[3];
    int dp2[3];
    dp[0] = ii1;
    dp[1] = ii2;
    dp[2] = ii3;
    dp2[0] = ii1;
    dp2[1] = ii2;
    dp2[2] = ii3;
    
    for(int i = 2 ; i <= num ; i++)
    {
        int i1,i2,i3;
        cin >> i1 >> i2 >> i3;
        int a,b,c;
        int d,e,f;
        a = max(dp[0],dp[1]) + i1;
        b = max({dp[0],dp[1],dp[2]}) + i2;
        c = max(dp[1],dp[2]) + i3;
        
        d = min(dp2[0],dp2[1]) + i1;
        e = min({dp2[0],dp2[1],dp2[2]}) + i2;
        f = min(dp2[1],dp2[2]) + i3;
        dp[0] = a;
        dp[1] = b;
        dp[2] = c;
        dp2[0] = d;
        dp2[1] = e;
        dp2[2] = f;
    }
    
    cout << max({dp[0],dp[1],dp[2]}) << ' ' << min({dp2[0],dp2[1],dp2[2]});
    
}
