## 다익스트라 알고리즘
* 기본적으로 최단 경로를 구하는 알고리즘
* 모든 정점에서 정점까지의 경로의 최단거리를 모두 찾는 것임 / 반복적으로 탐색해서 매번 최단 경로를 갱신하여 찾음
* 단 음의 가중치를 가지는 간선이 없어야함
* 다익스트라 알고리즘은 배열을 사용하면 O(N^2) 우선순위큐를 사용하면 O(ElogV)로 구현할 수 있음 

## 방법
1. 출발 노드 지정
2. 최단 거리 테이블 초기화 (무한대로)
3. 출발 노드를 방문 표시한후 인접한 노드의 값을 그 사이의 가중치로 갱신
4. 인접한 노드들 중 가중치가 가장 낮은 노드를 방문하여 3번과 같은 방법을 사용하지만 이때 이때까지 누적된 가중치를 더해야함
    * 1-2 : 3 / 1-3 : 4 / 1-4 : 5 /일때 다음 노드로 2를 선택함 
    * 또한 2를 선택하고 3,4로 가게 될 경우 2-3,2-4의 가중치에 1-2의 가중치를 더해야함
    * 이렇게 만들어진 1-3/1-4가중치와 기존의 1-3/1-4 가중치를 비교하여 더 낮은 값으로 갱신함

## 구현 (<a href = "./1753.cpp">1753</a>)
```cpp
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
```
