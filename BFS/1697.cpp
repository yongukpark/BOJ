//코드 구성 및 구현에 있어서는 일반적인 BFS라 어려움이 없었음
//다만 범위를 설정하는 부분에 있어서 실수가 있어 런타임에러를 발생시킴

#include <iostream>
#include <queue>
using namespace std;

int visited[200000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0 ; i < 200000; i++)
    {
        visited[i] = 999999;
    }
    
    int n, k;
    cin >> n >> k;
    
    queue <pair<int,int>> q;
    q.push({n,0});
    visited[n+100000] = 0;
    
    while(!q.empty())
    {
        int num = q.front().first;
        int count = q.front().second;
        q.pop();
        if(num-1 >=0 && visited[num-1+100000] >= count+1)
        {
            q.push({num-1, count+1});
            visited[num-1+100000] = count+1;
        }
        if(num+1 <= 200000 && visited[num+1+100000] >= count+1)
        {
            q.push({num+1, count+1});
            visited[num+1+100000] = count+1;
        }
        if(num*2 <= 200000 && visited[num*2+100000] >= count+1)
        {
            q.push({num*2, count+1});
            visited[num*2+100000] = count+1;
        }
        if(num == k)
        {
            cout << count << '\n';
            int res = 1;
            while(!q.empty())
            {
                if(q.front().first == k)
                {
                    res++;
                }
                q.pop();
            }
            cout << res;
            return 0;
        }
    }
}
