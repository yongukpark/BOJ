//뭔가 변수가 지저분하게 많지만 AC를 받음
//뒤늦게 생각해보면 fixx, fixy를 계속 넘겨주기보다 전역변수로 설정하는게 좋았다는 생각이 듬

#include <iostream>
#include <cmath>
using namespace std;

int n,m;
char arr[51][51];
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};
bool visited[51][51];

void input();
void dfs(int,int,int,int,char, int);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    input();
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            visited[i][j] = true;
            dfs(i, j, i, j, arr[i][j], 1);
            visited[i][j] = false;
        }
    }
    cout << "No";
}

void dfs(int fixx, int fixy, int x, int y, char c, int count)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        int x2 = x + movex[i];
        int y2 = y + movey[i];
        if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m && arr[x2][y2] == c)
        {
            if(x2 == fixx && y2 == fixy && count >= 4)
            {
                cout << "Yes";
                exit(0);
            }
            if(visited[x2][y2])
            {
               continue; 
            }
            visited[x2][y2] = true;
            dfs(fixx,fixy,x2,y2,c,count+1);
            visited[x2][y2] = false;
        }
    }
    return;
}

void input()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }
}
