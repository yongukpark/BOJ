//난이도 쉽고 예외사항도 크게 없어서 어렵지 않았음

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char arr[603][603];
bool visited[603][603];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    int goalx, goaly;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
            visited[i][j] = false;
            if(arr[i][j] == 'I')
            {
                goalx = i;
                goaly = j;
            }
        }
    }

    queue <pair<int,int>> q;
    q.push({goalx,goaly});
    visited[goalx][goaly] = true;

    int movex[4] = {0,0,-1,1};
    int movey[4] = {-1,1,0,0};

    int res = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(arr[x][y] == 'P')
        {
            res += 1;
        }
        if(arr[x][y] == 'X')
        {
            continue;
        }


        for(int i = 0 ; i < 4 ; i++)
        {
            if(x+movex[i] >= 0 && x + movex[i] < n && y + movey[i] >= 0 && y + movey[i] < m)
            {
                if(!visited[x+movex[i]][y+movey[i]])
                {
                    q.push({x+movex[i],y+movey[i]});
                    visited[x+movex[i]][y+movey[i]] = true;
                }    
            }
         }
    }

    if(!res)
    {
        cout << "TT";
    }
    else
    {
        cout << res;
    }

    return 0;
}
