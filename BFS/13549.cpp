//이문제의 핵심은 1칸씩 이동과 순간이동은 시간이 다르다는 것임
//그렇기에 priority queue를 사용하여 시간이 낮은 순서로 계속 pop해야함
//또한 중요한 것이 while문 안을 구현할때 a*2를 먼저 비교를 해주어야함
//반례로 1 2 에서 a+1이 먼저 들어가고 visited를 false로 만들어 계속 틀렸었음

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool visited[200001];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,n});
    visited[n] = true;
    
    while(!q.empty())
    {
        int a = q.top().second;
        int c = q.top().first;
        q.pop();
        
        if(a == m)
        {
            cout << c;
            break;
        }
        
        if(a*2 <= 200000 && !visited[a*2])
        {
            visited[a*2] = true;
            q.push({c,a*2});
        }
        
        if(a+1 <= 200000 && !visited[a+1])
        {
            visited[a+1] = true;
            q.push({c+1,a+1});
        }
        
        if(a-1 >= 0 && !visited[a-1])
        {
            visited[a-1] = true;
            q.push({c+1,a-1});
        }
        

        
    }

}
