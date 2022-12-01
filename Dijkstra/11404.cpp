//다익스트라 알고리즘의 응용이었음
//더 쉬운 방법으로 플로이드 와샬 알고리즘이 있다라는 것을 알게되었음
//다익스트라 : 한 정점에서 나머지 점들의 최단거리 
//플로이드 와샬 : 모든 정점에서 다른 모든 정점까지의 최단거리
//다익스트라를 모든 정점대상으로 하면 == 플로이드 와샬

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[101][101];


void resetArr()
{
    for(int i = 0 ; i < 101 ; i++)
    {
        for(int j = 0 ; j <101 ; j++)
        {
            arr[i][j] = 987654321;
        }
    }
}

int main()
{
    int n; cin >> n;
    int line; cin >> line;
    vector <pair<int,int>> v[101];    
    resetArr();
    
    for(int i = 0 ; i < line ; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({end,cost});
    }
    
    for(int j = 1 ; j <= n ; j++)
    {
        priority_queue <pair<int,int>> pq;
        pq.push({0, j});
        arr[j][j] = 0;
        while(!pq.empty())
        {
            int cost = -pq.top().first;
            int now = pq.top().second;
            pq.pop();
            for(int i = 0 ; i < v[now].size(); i++)
            {
                int cost2 = v[now][i].second + cost;
                if(cost2 < arr[j][v[now][i].first])
                {
                    arr[j][v[now][i].first] = cost2;
                    pq.push({-cost2,v[now][i].first});
                }
            }
        }    
    }

    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(arr[i][j] == 987654321)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << arr[i][j] << ' ';
            }
            
        }
        cout << '\n';
    }
    
}
