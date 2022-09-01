//문자열이 짧아야하고 문자마다 우선순위가 있다라는 것을 생각하여 논리적으로 잘 구현해야함
//또한 - 연산은 쓸수없다라는 것도 인지해야함 ( 원인)
//또한 / 연산을 쓰고 *를 쓸수없다라는 것도 인지해야함 (무한루프 원인)

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int start,e;
    cin >> start >> e;
    if(start == e)
    {
        cout << 0;
        return 0;
    }
    queue<pair<string,int>> q;

    q.push({"",start});
    
    while(!q.empty())
    {
        string s = q.front().first;
        int n = q.front().second;
        q.pop();
        if(n == e)
        {
            cout << s;
            return 0;
        }
        
        if(n <= sqrt(1000000000) && n != 1)
        {
            q.push({s+"*",n*n});
        }
        
        if(n * 2 <= 1000000000)
        {
            q.push({s+"+",n*2});
        }
        
        if(s == "")
        {
            q.push({"/",1});
        }
        
    }
    cout << -1;
    return 0;
}
