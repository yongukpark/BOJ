//bfs 문제 같았지만 그냥 구현으로 풀어냈음
//자료의 크기가 50밖에 되지않아 O(N^4)까지 허용된다는 것을 생각하여 쉽게 풀었던 것 같음

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    bool check[53];
    vector<int>v[53];
    
    int n,m; cin >> n >> m;
    int truthNum; cin >> truthNum;
    
    for(int i = 0 ; i <= n ; i++)
    {
        check[i] = false;
    }
    
    for(int i = 0 ; i < truthNum ; i++)
    {
        int a;
        cin >> a;
        check[a] = true;
    }
    

    
    for(int i = 0 ; i < m ; i++)
    {
        int partyNum; cin >> partyNum;
        v[i].push_back(partyNum);
        for(int j = 0 ; j < partyNum  ; j++)
        {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            for(int k = 1 ; k <= v[j][0] ; k++)
            {
                if(check[v[j][k]])
                {
                    for(int t = 1 ; t <= v[j][0] ; t++)
                    {
                        check[v[j][t]] = true;
                    }
                    v[j][0] = 0;
                    break;
                }
            }
        }
    }
    int total = 0 ;
    for(int i = 0 ; i < m ; i++)
    {
        if(v[i][0])
        {
            total++;
        }
    }
    cout << total;
}
