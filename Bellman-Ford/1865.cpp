//이 문제는 벨만포드에 대해 이해도가 있는사람만이 풀수있는문제 같음
//단순히 벨만포드를 구현할줄 아는것을 넘어 의미를 알고 그것을 문제에 적용 시킬 수 있어야함
//벨만포드에서 한 정점을 지정을 해주고 그 정점으로 부터 계산을 하였지만 이 문제 같은 경우는 정점이 지정되지 않았음
//따라서 음의 사이클이 234에 형성되고 1이 고립되어있는 상황에서 1을 정점으로 잡은 후 기존 벨만포드에 있는 'dist[i] != INF'를 넣게되면 음의 사이클은 존재하지만 찾지 못하는 상황이 생김
//또한 이 문제는 최단거리를 구하는것이 아니라 음의 사이클의 유무를 판단하기에 정확한 거리를 구할 필요가 없고 거리가 줄어드는지 늘어나는지만 판단하면 되었음
//즉 초기값을 INF로 잡는 것이 아니라 아무 숫자가 모두 가능했음 오히려 INF는 불가능함(INF+a를 하게되면 overflow가 나기때문)
//벨만포드를 조금 더 공부해야겠다는 생각이 들었고 벨만포드를 이해하는데 매우 도움되는 문제였음

#include <iostream>
#include <vector>
using namespace std;


int arr[501];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int testCase; cin >> testCase;
    for(int i = 0 ; i < testCase ; i++)
    {
        vector<pair<pair<int,int>,int>> v;
        int n,m,w;
        int start,end,weight;
        cin >> n >> m >> w;
        for(int i = 1 ; i <= n ; i++)
        {
            arr[i] = -1;
        }
        for(int j = 0 ; j < m ; j++)
        {
            cin >> start >> end >> weight;
            v.push_back({{start,end},weight});
            v.push_back({{end,start},weight});
        }
        for(int j = 0 ; j < w ; j++)
        {
            cin >> start >> end >> weight;
            v.push_back({{start,end},-weight});
        }
        
        bool flg = true;
        arr[1] = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            for(int k = 0 ; k < v.size() ; k++)
            {
                int w = arr[v[k].first.first] + v[k].second;
                if( w < arr[v[k].first.second])
                {
                    arr[v[k].first.second] = w;
                    if(j == n)
                    {
                        flg = false;
                    }
                }
            }
        }
        if(flg)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }
}
