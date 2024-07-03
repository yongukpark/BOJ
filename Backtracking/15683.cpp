//간단한 백트래킹 문제였음 다만 구현에 있어 복잡한 부분이 없지 않아 있었지만 문제만 잘읽으면 큰 예외처리할 것도 없었음
//stack을 사용하여 지나간 길을 저장해놓는 형식이 신의한수였던 것 같음

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int n,m;
int arr[9][9];
int black = 1000;
int movex[4] = {-1,0,1,0};
int movey[4] = {0,1,0,-1};

vector <pair<int,int>> cctv;

void count_black()
{
    int cnt = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(arr[i][j] == 0)
            {
                cnt ++;
            }
        }
    }
    if(cnt < black)
    {
        black = cnt;
    }
}

void draw(stack<pair<int,int>> &s, int xx, int yy, int i)
{
    while(1)
    {
        xx = xx + movex[i];
        yy = yy + movey[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m || arr[xx][yy] == 6)
        {
            break;
        }
        if(arr[xx][yy] == 0)
        {
            arr[xx][yy] = 9;
            s.push({xx,yy});
        }
        
    }
}

void backTracking(int idx)
{
    if(idx == cctv.size())
    {
        count_black();
        return;
    }
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    stack <pair<int,int>>s;
    switch(arr[x][y])
    {
    case 1:
        for(int i = 0 ; i < 4 ; i++)
        {
            int xx = x;
            int yy = y;
            draw(s,xx,yy,i);
            backTracking(idx+1);
            while(!s.empty())
            {
                arr[s.top().first][s.top().second] = 0;
                s.pop();
            }
        }
        break;
    case 2:
        for(int i = 0 ; i < 2 ; i++)
        {
            int xx = x;
            int yy = y;
            draw(s,xx,yy,i);
            draw(s,xx,yy,i+2);
            backTracking(idx+1);
            while(!s.empty())
            {
                arr[s.top().first][s.top().second] = 0;
                s.pop();
            }
        }
        break;
    case 3:
        for(int i = 0 ; i < 4 ; i++)
        {
            int xx = x;
            int yy = y;
            draw(s,xx,yy,i);
            draw(s,xx,yy,(i+1)%4);
            backTracking(idx+1);
            while(!s.empty())
            {
                arr[s.top().first][s.top().second] = 0;
                s.pop();
            }
        }
        break;
    case 4:
        for(int i = 0 ; i < 4 ; i++)
        {
            int xx = x;
            int yy = y;
            draw(s,xx,yy,i);
            draw(s,xx,yy,(i+1)%4);
            draw(s,xx,yy,(i+2)%4);
            backTracking(idx+1);
            while(!s.empty())
            {
                arr[s.top().first][s.top().second] = 0;
                s.pop();
            }
        }
        break;
    case 5:
        int xx = x;
        int yy = y;
        draw(s,xx,yy,0);
        draw(s,xx,yy,1);
        draw(s,xx,yy,2);
        draw(s,xx,yy,3);
        backTracking(idx+1);
        while(!s.empty())
        {
            arr[s.top().first][s.top().second] = 0;
            s.pop();
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] > 0 && arr[i][j] < 6)
            {
                cctv.push_back({i,j});
            }
        }
    }
    backTracking(0);

    cout << black;
}
