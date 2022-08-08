//두가지 풀이법이 있음
//너무 허무하게 오타로 인한 실수가 있어 두가지 방법으로 풀게 되었음

//일반 bfs 풀이
#include <iostream>
#include <queue>
using namespace std;

bool visited[103][103];

char arr[103][103];
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> m >> n;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    priority_queue < pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater <pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    
    while(!pq.empty())
    {
        int count = pq.top().first; 
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        visited[x][y] = true;
        
        if(x == (n-1) && y == (m-1))
        {
            cout << count;
            return 0;
        }

        for(int i = 0 ; i < 4 ; i++)
        {
            int x2 = x + movex[i];
            int y2 = y + movey[i];
            if(x2 >= 0 && x2 < m && y2 >= 0 && y2 < m && !visited[x2][y2])
            {
                visited[x2][y2] = true;
                if(arr[x2][y2] == '1')
                {
                    pq.push({count+1,{x2,y2}});
                }
                else
                {
                    pq.push({count,{x2,y2}});
                }
            }
        }
    }
}


//다익스트라 풀이
#include <iostream>
#include <queue>
using namespace std;

int dist[103][103];
char arr[103][103];
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m;
    cin >> m >> n;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            dist[i][j] = 100000000;
            cin >> arr[i][j];
        }
    }
    
    queue <pair<int,int>> pq;
    pq.push({0,0});
    dist[0][0] = 0;
    
    while(!pq.empty())
    {
        int x = pq.front().first;
        int y = pq.front().second;
        pq.pop();

        for(int i = 0 ; i < 4 ; i++)
        {
            int x2 = x + movex[i];
            int y2 = y + movey[i];
            if(x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
            {
                continue;
            }

            if(arr[x2][y2] == '1' && (dist[x2][y2] > (dist[x][y] + 1)))
            {
                dist[x2][y2] = dist[x][y] + 1;
                pq.push({x2,y2});
            } 
            else if(arr[x2][y2] == '0' && (dist[x2][y2] > dist[x][y]))
            {
                dist[x2][y2] = dist[x][y];
                pq.push({x2,y2});
            }
        }
    }
    
    cout << dist[n-1][m-1];
}
