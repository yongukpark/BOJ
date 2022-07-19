//오랜만에 dfs를 해서 조금 구현하는데 어려운 감이 없지않아 있었음
//맨위 가스관에서부터 왼오, 오, 아래오 순서로 탐색을 하게되면 중간에 겹칠수도 만날수도 없다라는 사실을 알면 문제가 편했음
//
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int r,c;
bool arr[10001][501];
int moveX[3] = {-1,0,1};
int moveY[3] = {1,1,1};

bool dfs(int x, int y)
{
    arr[x][y] = true;
    
    if(y == c-1)
    {
        return true;
    }
    
    for(int i = 0 ; i <3 ; i++)
    {
        
        int x1 = x + moveX[i];
        int y1 = y + moveY[i];
        
        if(x1 < 0 || y1 < 0 || x1 >= r || y1 >= c)
        {
            continue;
        }
        
        if(arr[x1][y1])
        {
            continue;
        }
        
        if(dfs(x1,y1))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> r>> c;
    
    for(int i = 0 ; i <r ; i++)
    {
        for(int j = 0 ; j <c ; j++)
        {
            char c;
            cin >> c;
            if(c=='.')
            {
                arr[i][j] = false;
            }
            else
            {
                arr[i][j] = true;
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0 ; i < r ; i++)
    {
        if(dfs(i,0))
        {
            arr[i][0] = true;
            cnt++;
        }
    }
    cout <<cnt;
}


