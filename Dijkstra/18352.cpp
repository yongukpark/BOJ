//이문제에는 간선의 가중치가 없지만 결국 가중치가 1로 고정된 다익스트라와 같다고 생각하여 다익스트라 알고리즘을 이용하여 풀었음

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int,int>> v[300003];
int arr[300003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k ,start;
    cin >> n >> m >> k >> start;
    for(int i = 0 ; i < m ; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({1,b}); // 가중치, 도착노드
        
    }
    
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = 987654321;
    }

    
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
    
    int count = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(arr[i]==k) 
        {
            cout << i << '\n'; 
            count++;
        }
        
    }
    if(count == 0)
    {
        cout << -1;
    }

}
