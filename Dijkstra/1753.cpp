//가중치를 기준으로 정렬하여야하는데 아무생각없이 가중치를 pair의 second로 썼음
//그래서 시간초과가 계속나서 

#include <iostream>
#include <vector> 
#include <utility>
#include <queue>
using namespace std;

vector <pair<int,int>> v[20003];
int arr[20003];

void dij(int start)
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    arr[start] = 0;
    while(!pq.empty())
    {
        int now = pq.top().second;
        int val = -pq.top().first; //음수로 해야 더 작은 간선이 우선시됨 / pq를 오름차순으로 해도됨
        pq.pop();
        
        for(int i = 0 ; i < v[now].size() ; i++)
        {
            int cost = val + v[now][i].second;
            
            if(cost < arr[v[now][i].first])
            {
                arr[v[now][i].first] = cost;
                pq.push({-cost, v[now][i].first});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int V,e;
    cin >> V >> e;
    int start;
    cin >> start;
    for(int i = 0 ; i < e ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    
    for(int i = 1 ; i <= V ; i++)
    {
        arr[i] = 987654312;
    }
    
    dij(start);
    
    for(int i = 1 ; i <= V ; i++)
    {
        if(arr[i] == 987654312)
        {
            cout << "INF";
        }
        else
        {
            cout << arr[i];
        }
        cout << '\n';
    }
}
