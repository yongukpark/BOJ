//기본적인 다익스트라 문제라 큰 어려움은 없었음

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int,int>> v[1003];
int arr[1003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({c,b}); // 가중치, 도착노드
        
    }
    
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = 987654321;
    }
    
    int start, end;
    cin >> start >> end;
    
    priority_queue <pair<int,int>> pq;
    
    pq.push({0,start});
    arr[start] = 0;
    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(cost > arr[now]) continue;
        
        for(int i = 0 ; i < v[now].size() ; i++)
        {
            int val = v[now][i].first + cost;
            int next = v[now][i].second;
            if(val < arr[next])
            {
                arr[next] = val;
                pq.push({-val,next});
            }
        }
    }
    cout << arr[end];
}
