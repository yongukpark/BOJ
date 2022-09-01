//1967문제와 매우유사하고 다른점이라하면 입력말고는 없음

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

vector <pair<int,int>> v[100003];
long long arr[100003];
int num;

int dij(int a)
{
    
    for(int i = 1 ; i <= num ; i++)
    {
        arr[i] = 99987654321;
    }
    
    priority_queue <pair<long long,int>> q;
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
    long long maxiNum = 0;
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
    for(int i = 1 ; i <= num ; i++)
    {
        int k; cin >> k;
        while(1)
        {
            int a,b;
            cin >> a;
            if(a == -1)
            {
                break;
            }
            cin >> b;
            v[k].push_back({a,b});
            v[a].push_back({k,b});
        }
    }
    
    for(int i = 1 ; i <= num ; i++)
    {
        arr[i] = 99987654321;
    }
    
    cout << arr[dij(dij(1))];
}
