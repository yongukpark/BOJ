//4색정리의 원리를 이용하여 정육각형에서는 3색정리가 적용된다라는 것을 알아야 풀수 있는 문제였음
//4색정리 : 4가지 색깔만 사용하더라도 세계지도를 구분하여 색칠할 수 있음

#include <iostream>
using namespace std;

int n,k;
char input[53][53];
int arr[53][53];
int movex[6] = {-1,-1,0,1,1,0};
int movey[6] = {0,1,1,0,-1,-1};
int res = 0;
void dfs(int x, int y, int c)
{
    arr[x][y] = c;
    res = max(res,1);
    
    for(int j = 0 ; j < 6 ; j++)
    {
        int x2 = x + movex[j];
        int y2 = y + movey[j];
        if(x2 < 0 || y2 < 0 || x2 >= n || y2 >= n)
        {
            continue;
        }
        if(input[x2][y2] == '-')
        {
            continue;
        }
        if(arr[x2][y2] == -1)
        {
            dfs(x2,y2,1-c);
            res = max(res,2);
        }
        else if(arr[x2][y2] == c)
        {
            cout << 3;
            exit(0);
        }
    }
}

int main()
{

    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ;j++)
        {
            cin >> input[i][j];
            arr[i][j] = -1;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(input[i][j] == 'X' && arr[i][j] == -1)
            {
               dfs(i,j,1); 
            }
        }
    }
    cout << res;
}
