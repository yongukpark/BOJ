// a <= 500 b <=6000 |c|<=10000이어서
// 당연히 60,000,000 이 범위일줄 알았지만 벨만포드라는 특성을 고려해 노드 개수인 a를 안곱해줌으로써 출력초과가 남
// 벨만포드는 정확한 거리를 구할 수는 있지만 주목적이 그것인 알고리즘이 아니기에 이러한 것에 주의해야함

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    vector <pair<pair<int,int>,int>> v;
    vector <long long> arr(503);
    int n,m; cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        v.push_back({{a,b},c});
    }
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = 987654321;
    }
    bool flg = true;
    arr[1] = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(arr[v[j].first.first] == 987654321)
            {
                continue;
            }
            if(arr[v[j].first.first] + v[j].second < arr[v[j].first.second])
            {
                if(i == n)
                {
                    flg = false;
                }
                arr[v[j].first.second] = arr[v[j].first.first] + v[j].second;
            }
        }
    }
    if(!flg)
    {
        cout << -1;
        return 0;
    }
    for(int i = 2 ; i <= n ;i++)
    {
        if(arr[i] == 987654321)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << arr[i] << '\n';
        }
    }
}
