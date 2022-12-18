//dijkstra구문에서 변수이름을 잘못 입력하여서 루프를 많이 돌게되어 메모리 초과를 일으켰음
//어이없게 다른곳만 뜯어고치고 정작 잘못된 곳은 고치지 않아 많은 실수를 하였음
//변수명을 자기가 사용하기 편하게..가독성이 좋게..

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> v[801];
int arr[801];
int n,e; 
int res = 987654321;
priority_queue<pair<int,int>> pq;
void dijstra(int a)
{
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = 987654321;
    }
    arr[a] = 0;
    pq.push({a,0});
    while(!pq.empty())
    {
        int position = pq.top().first;
        int weight = -pq.top().second;
        pq.pop();
        if(weight > arr[position])
        {
            continue;
        }
        for(int i = 0 ; i < v[position].size(); i++)
        {
            int w = weight + v[position][i].second;
            if(arr[v[position][i].first] > w)
            {
                arr[v[position][i].first] = w;
                pq.push({v[position][i].first,-w});
            }
        }

        
    }
}

int main()
{
    cin >> n >> e;
    for(int i = 0 ; i < e ; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int a,b; cin >> a >> b;
    dijstra(1); //1-a,1-b
    int onetoa = arr[a]; 
    int onetob = arr[b];
    dijstra(a); //a-b,b-a
    int atob = arr[b];
    int btoa = arr[b];
    dijstra(n); //b-n,a-n
    int bton = arr[b];
    int aton = arr[a];
    
    res = min(res, onetoa + atob + bton);
    res = min(res, onetob + btoa + aton);
    if(res == 987654321 || atob == 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << res;
    }
}
