//무난한 다익스트라 문제였음
//점점 다익스트라에 대해 적응 되고 있다라는 걸 느끼게 된 문제이기도 함

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector<pair<int,int>>v[1001];
vector<pair<int,int>>arr(1001);
int main()
{

    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    int a,b; cin >> a >> b;
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i].first = 0;
        arr[i].second = 987654321;
    }
    arr[a].second = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({a,0});
    
    while(!pq.empty())
    {
        int position = pq.top().first;
        int weight = -pq.top().second;
        pq.pop();
        if(weight > arr[position].second)
        {
            continue;
        }
        for(int i = 0 ; i < v[position].size() ; i++)
        {
            if(arr[v[position][i].first].second > v[position][i].second+weight)
            {
                arr[v[position][i].first].second = v[position][i].second+weight;
                arr[v[position][i].first].first = position;
                pq.push({v[position][i].first,-(v[position][i].second+weight)});
                
            }
        }
    }
    cout << arr[b].second << '\n';
    int count = 0;
    int posi = b;
    stack <int> s;
    while(1)
    {
        s.push(posi);
        count++;
        posi = arr[posi].first;
        if(posi == a)
        {
            s.push(a);
            count++;
            break;
        }
    }
    cout << count<<'\n';
    while(!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}
