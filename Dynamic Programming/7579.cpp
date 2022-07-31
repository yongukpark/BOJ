//개인적으로 너무 어려웠음
//일반적인 dp문제와 조금 다른 면이 없지않았고 답안을 보았음에도 너무 헷갈린 문제였음
//문제가 최대메모리, 메모리, 가치 이렇게 주어졌고 이 경우 보통 메모리를 dp에 사용하겠지만 여기서는 메모리를 dp에 넣게되면 시간초과가 나기에 가치를 dp에 넣어야함
//가치를 넣게되면 각 원소의 가치당 최대메모리가 각각의 셀에 들어가게되고 나중에 앞에서부터 반복문을 돌리며 가장 먼저 최대메모리를 넘은 가치를 찾아 그것을 답으로 출력함
//생각의 전환이 필요한 문제였다고 생각되어 많이 어려웠음

#include <iostream>
#include <cmath>
using namespace std;
int dp[103][10003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    int m[103];
    int c[103];
    
    int num, mem;
    cin >> num >> mem;
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> m[i];
    }
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> c[i];
    }
    
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 0 ; j <= 10000 ; j++)
        {
            if(c[i] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - c[i]] + m[i]);
            }
        }
    }
    
    for(int i = 0 ; i <= 10000 ; i++)
    {
        if(dp[num][i] >= mem)
        {
            cout << i;
            return 0;
        }
    }
}
