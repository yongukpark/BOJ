//시간 복잡도도 크게 고려할 것 없었기에 무난한 문제였다고 생각함

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<pair<int,int>> v[101];
    int arr[101] = {0,};
    int tmp[101] = {0,};
    int n,m,r; cin >> n >> m >> r;
    
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0 ; i < r;  i++)
    {
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    int max = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            tmp[j] = 987654321;
        }
        tmp[i] = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({i,0});
        while(!pq.empty())
        {
            int position = pq.top().first;
            int weight = -pq.top().second;
            pq.pop();
            
            if(weight > tmp[position])
            {
                continue;
            }
            
            for(int j = 0 ; j < v[position].size() ; j++)
            {
                if(tmp[v[position][j].first] > weight + v[position][j].second)
                {
                    tmp[v[position][j].first] = weight + v[position][j].second;
                    pq.push({v[position][j].first,-(weight + v[position][j].second)});
                }
            }
        }
        int res = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            if(tmp[j] <= m)
            {
                res += arr[j];
            }
        }
        if(res > max)
        {
            max = res;
        }
    }
    cout << max;
}
