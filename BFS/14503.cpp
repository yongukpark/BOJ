//방향전환하는 부분에서 신경을 쓸 필요가 있는 문제였음

#include <iostream>
using namespace std;
int n,m;
int arr[53][53];
int res = 0;
int movex[4] = {-1,0,1,0};
int movey[4] = {0,1,0,-1};

void dfs(int x, int y, int d)
{
    if(arr[x][y] == 0)
    {
        arr[x][y] = 2;
        res++;
    }
    
    for(int i = 0 ; i < 4 ;i++)
    {
        int nd = (d+3-i)%4;
        int nx = x + movex[nd];
        int ny = y + movey[nd];

        if(arr[nx][ny] == 0)
        {
            dfs(nx,ny,nd);
        }
    }
    
    int nd = (d+2)%4;
    int nx = x + movex[nd];
    int ny = y + movey[nd];
    
    if(arr[nx][ny] == 1)
    {
        cout << res;
        exit(0);
    }
    dfs(nx,ny,d);
}

int main()
{
    int x,y,d;
    cin >> n >> m >> x >> y >> d;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    dfs(x,y,d);
}
