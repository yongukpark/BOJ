//코드 자체가 너무 복잡함, 함수 사용의 중요성을 다시한번 느낀 문제
//다른 사람들의 코드도 보았지만 다들 많은 함수를 사용한 것 같았음
//그것 이외에는 예외도 크게 없는 BFS 문제임

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int arr[105][105];
int tmp[105][105];
bool visited[105][105];
int row,col;
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};


void input();
void bfs();
bool check();
void cheese_melting();
void tmp_to_arr();
void reset_visited();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    input();

    int cnt = 0;
    while(1)
    {
        if(check())
        {
            cout << cnt;
            return 0;
        }

        reset_visited();
        bfs();
        cheese_melting();
        tmp_to_arr();

        cnt++;
    }

}

void reset_visited()
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            visited[i][j] = false;
        }
    }
}

void input()
{
    cin >> row >> col;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cin >> arr[i][j];
        }
    }
}
void bfs()
{
    queue <pair<int,int>> q;
    q.push({0,0});

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0  ; i < 4 ; i++)
        {
            if(x+movex[i] >= 0 && x+movex[i] < row && y+movey[i] >=0 && y+movey[i] < col)
            {
                if(arr[x+movex[i]][y+movey[i]] != 1 && !visited[x+movex[i]][y+movey[i]])
                {
                    visited[x+movex[i]][y+movey[i]] = true;
                    arr[x+movex[i]][y+movey[i]] = -1;
                    q.push({x+movex[i],y+movey[i]});
                }
            }
        }
    }
}
bool check()
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(arr[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}
void cheese_melting()
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(arr[i][j] == 1)
            {
                int cnt = 0;
                for(int k = 0 ; k < 4 ; k++)
                {
                    int x = i + movex[k];
                    int y = j + movey[k];
                    if(arr[x][y] == -1)
                    {
                        cnt++;
                    }
                }
                if(cnt >= 2)
                {
                    tmp[i][j] = -1;
                }
            }
        }
    } 
}
void tmp_to_arr()
{
    for(int i = 0 ; i  < row ; i++)
    {
        for(int j = 0 ; j < col ;j++)
        {
            if(tmp[i][j] == -1)
            {
                arr[i][j] = -1;
            }
        }
    }    
}
