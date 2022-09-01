//이 문제는 아이디어를 생각하는데에 어려움이 있었음
//결과적으로는 아무 정점에서 최대거리인 정점을 찾아 그 정점에서 최대거리인 정점을 찾으면 되는 문제임
//만약 정점의 개수가 0으로 주어진다면 오류가 나기에 그것에 대한 validate check만 필요로 했음
//구현은 일반적인 다익스트라 알고리즘과 차이가없음

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

vector <pair<int,int>> v[10003];
int arr[10003];
int num;

int dij(int a)
{
    
    for(int i = 1 ; i <= num ; i++)
    {
        arr[i] = 987654321;
    }
    
    priority_queue <pair<int,int>> q;
    q.push({0,a});
    
    arr[a] = 0;
    
    while(!q.empty())
    {
        int cost = -q.top().first;
        int now = q.top().second;
        q.pop();
        if(cost > arr[now]) continue;
        
        for(int i = 0 ; i < v[now].size() ; i++)
        {
            int value = v[now][i].second + cost;
            int next = v[now][i].first;
            if(arr[next] > value)
            {
                arr[next] = value;
                q.push({-value,next});
            }
        }
    }
    
    int maxiIndex;
    int maxiNum = 0;
    for(int i = 1 ; i <= num ; i++)
    {
        if(arr[i] > maxiNum )
        {
            maxiIndex = i;
            maxiNum = arr[i];
        }
    }
    return maxiIndex;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> num;
    
    if(num == 1)
    {
        cout << 0;
        return 0;
    }
    for(int i = 0 ; i < num - 1 ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c; //부모,자식,비용
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    for(int i = 1 ; i <= num ; i++)
    {
        arr[i] = 987654321;
    }
    
    cout << arr[dij(dij(1))];
}
