//초기 res값을 0으로 설정해서 음수를 처리못하는 경우를 발견함
//또한 배열을 bool로 만들면 true->false로 바꾸는 과정에서 겹치는 부분이 생기는데 이를 해결하기위해 int형 배열로 ++를 통해 값을 넣어줌
//무난한 백트래킹
#include <iostream>
#include <cmath>
using namespace std;

int visited[13][13];
int arr[13][13];
int n,m,k;
int res = -100000000;

void dfs(int num, int sum)
{
    if(num == k)
    {
        res = max(res,sum);
        return;
    }
    for(int i = 1 ; i <= ::n ; i++)
    {
        for(int j = 1 ; j <= ::m ; j++)
        {
            if(!visited[i][j])
            {
                visited[i][j]++;
                visited[i+1][j]++;
                visited[i][j-1]++;
                visited[i-1][j]++;
                visited[i][j+1]++;
                dfs(num+1,sum+arr[i][j]);
                visited[i][j]--;
                visited[i+1][j]--;
                visited[i][j-1]--;
                visited[i-1][j]--;
                visited[i][j+1]--;
            }
        }
    }
}
    
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    cin >> n >> m >> k;
    
    //입력
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    dfs(0,0);
    cout << res;
    
}
