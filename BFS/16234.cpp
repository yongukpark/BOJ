// 비교적 간단한? 문제였다.
// 함수를 사용했더라면 조금 더 깔끔하게 풀 수 있었을텐데 그 점이 아쉽다.

#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
using namespace std;

int arr[53][53];
bool visited[53][53];
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};

int main()
{
    int n,l,r;
    cin >> n >> l >> r;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> arr[i][j];
        }
    }

    queue<pair<int,int>>q;
    queue<pair<int,int>>save;


    int countDay = 0;
    while(true)
    {
        int flg = false;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                visited[i][j] = false;
            }
        }

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {

                if(visited[i][j]) continue;
                
                int res = arr[i][j];
                q.push({i,j});
                save.push({i,j});
                visited[i][j] = true;
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k = 0 ; k < 4 ; k++)
                    {
                        int xx = x + movex[k];
                        int yy = y + movey[k];
                        if(xx < 0 || yy < 0 || xx >= n || yy >= n || visited[xx][yy]) continue;
                        if(abs(arr[xx][yy] - arr[x][y]) > r || abs(arr[xx][yy] - arr[x][y]) < l) continue;

                        visited[xx][yy] = true;
                        q.push({xx,yy});
                        save.push({xx,yy});
                        res += arr[xx][yy];
                    }
                }
                if(save.size() != 1)
                {
                    flg = true;
                }
                res = res / save.size(); 
                while(!save.empty())
                {
                    arr[save.front().first][save.front().second] = res;
                    save.pop();
                }
            }
        }

        if(!flg)
        {
            cout << countDay << '\n'; return 0;
        }
        countDay++;
    }
}
