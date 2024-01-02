//예외처리할게 너무 많았음
//메모리 초과도 났고 문제에서 -1로 표기하라는 사항을 아예 무시해버려서 틀림

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[1003][1003];
int res[1003][1003];
bool visited[1003][1003];

void res_reset()
{
    for(int i = 0 ; i <= 1000 ; i++)
    {
        for(int j = 0 ; j <= 1000 ; j++)
        {
            res[i][j] = 0;
            visited[i][j] = false;
        }
    }
}



void res_show(int n, int m)
{

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(arr[i][j] == 1 && res[i][j] == 0)
            {
                cout << -1 << ' ';
            }
            else
            {
                cout << res[i][j] << ' ';
            }     
        }
        cout << '\n';
    }
}

int main()
{
    res_reset();

    int n,m; 
    cin >> n >> m;
    
    int goalx, goaly;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 2)
            {
                goalx = i;
                goaly = j;
            }
        }
    }

    queue <pair<int,int>> q; 
    queue <int> cnt;
    q.push({goalx, goaly});
    visited[goalx][goaly] = true;
    cnt.push(0);
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int count = cnt.front();
        cnt.pop();
        

        if(arr[x][y] == 0)
        {
            continue;
        }
        else
        {
            if(res[x][y] == 0)
            {
                res[x][y] = count;
            }   
        }

        if(x - 1 >= 0 && !visited[x-1][y]) 
        {
            visited[x-1][y] = true;
            q.push({x-1,y});
            cnt.push(count+1);
        }
        if(x + 1 < n && !visited[x+1][y])   
        {
            visited[x+1][y] = true;
            q.push({x+1,y});
            cnt.push(count+1);
        }
        if(y - 1 >= 0 && !visited[x][y-1]) 
        {
            visited[x][y-1] = true;
            q.push({x,y-1});
            cnt.push(count+1);
        }
        if(y + 1 < m && !visited[x][y+1]) 
        {
            visited[x][y+1] = true;
            q.push({x,y+1});
            cnt.push(count+1);
        }
    }


    res_show(n,m);
}
