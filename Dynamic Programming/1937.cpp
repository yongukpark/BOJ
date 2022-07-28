//dp는 생각하는게 끝이 없는 것 같음
//일단 보기에는 간단한 dfs문제 같지만 우리가 흔히 아는 방법으로 풀 경우 O(N^4)으로 시간초과를 불러일으킴
//인터넷을 참조하였고 bfs문제처럼 최소 몇일을 살수있는가를 기록하는 것이 아니라 일반적인 dfs문제처럼 최대 얼마나 살수 있는지를 구해야함
//그렇게하면 이 점을 다시 돌아왔을 때 재탐색이 아니라 그냥 최대인 값과 비교만하여 dp를 갱신해줄 수 있음
//핵심은 dfs를 통해 dp에 값을 넣을 때 살수있는 최대의 일수를 기입하는 것임
#include <iostream>
#include <cmath>
using namespace std;

int num;
int arr[501][501];
int dp[501][501];
int moveX[4] = {-1,1,0,0};
int moveY[4] = {0,0,-1,1};

int dfs(int x, int y)
{
    if(dp[x][y] != 1)
    {
        return dp[x][y];
    }
    
    for(int i = 0 ; i < 4; i++)
    {
        int x1 = x + moveX[i];
        int y1 = y + moveY[i];
        if(x1 < 0 || y1 < 0 || x1 >= num || y1 >= num)
        {
            continue;
        }
        
        if(arr[x1][y1] > arr[x][y])
        {
            dp[x][y] = max(dp[x][y],dfs(x1,y1)+1);
        }
    }
    return dp[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            cin >> arr[i][j];
            dp[i][j] = 1;
        }
    }
    
    int res = 0;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            if(dfs(i,j) > res)
            {
                res = dfs(i,j);
            }
        }
    } 
    cout << res;
}

 

