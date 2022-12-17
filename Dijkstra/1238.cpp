//다익스트라 두번 하면 되는 문제였음
//크게 어려운 부분은 없었고 굳이 찾자면 start, end점을 바꾸어 도착지->출발지로의 경로를 하나 더 구해야하는 
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int arr[1003];
    int arr2[1003];
    vector<pair<int,int>>v[1003];
    vector<pair<int,int>>vv[1003];
    int n,m,x;
    cin >> n >> m >> x;
    
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = 987654321;
        arr2[i] = 987654321;
    }
    
    for(int i = 0 ; i < m ; i++)
    {
        int s,e,w;
        cin >> s >> e >> w;
        v[e].push_back({s,w});
        vv[s].push_back({e,w});
    }
    
    priority_queue<pair<int,int>> pq;
    
    pq.push({x,0});
    arr[x] = 0;
    while(!pq.empty())
    {
        int posi = pq.top().first;
        int weight = -pq.top().second;
        pq.pop();
        
        if(weight > arr[posi])
        {
            continue;
        }
        
        for(int i = 0 ; i < v[posi].size() ; i++)
        {
            if(arr[v[posi][i].first] > weight + v[posi][i].second)
            {
                arr[v[posi][i].first] = weight + v[posi][i].second;
                pq.push({v[posi][i].first,-(weight + v[posi][i].second)});
            }
        }
    }
    
    pq.push({x,0});
    arr2[x] = 0;
    while(!pq.empty())
    {
        int posi = pq.top().first;
        int weight = -pq.top().second;
        pq.pop();
        
        if(weight > arr2[posi])
        {
            continue;
        }
        
        for(int i = 0 ; i < vv[posi].size() ; i++)
        {
            if(arr2[vv[posi][i].first] > weight + vv[posi][i].second)
            {
                arr2[vv[posi][i].first] = weight + vv[posi][i].second;
                pq.push({vv[posi][i].first,-(weight + vv[posi][i].second)});
            }
        }
    }
    
    int maxi = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(arr[i]+arr2[i] > maxi)
        {
            maxi = arr[i]+arr2[i];
        }
    }
    cout << maxi;
}
