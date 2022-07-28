//dp문제인줄 알고 풀었지만 bfs로도 충분히 풀 수 있는 문제였음
#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num;
    int arr[17][17];

    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            cin >> arr[i][j];
        }
    }
    queue <pair<int,int>> q;
    queue <int> typeQ;
    q.push({0,1});
    typeQ.push(0);
    int count = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int type = typeQ.front();
        q.pop();
        typeQ.pop();
        
        if(x == num-1 && y == num-1)
        {
            count++;
        }
        if(type == 0)
        {
            int x2 = x;
            int y2 = y + 1;
            if(x2 < num && y2 < num && arr[x2][y2] == 0 )
            {
                q.push({x2,y2});
                typeQ.push(0);
            }
            x2 = x + 1;
            y2 = y + 1;
            if(x2 < num && y2 < num && arr[x2][y2] == 0 && arr[x2-1][y2] == 0 && arr[x2][y2-1] == 0)
            {
                q.push({x2,y2});
                typeQ.push(2);
            }
        }
        else if(type == 1)
        {
            int x2 = x + 1;
            int y2 = y ;
            if(x2 < num && y2 < num && arr[x2][y2] == 0)
            {
                q.push({x2,y2});
                typeQ.push(1);
            }
            x2 = x + 1;
            y2 = y + 1;
            if(x2 < num && y2 < num && arr[x2][y2] == 0 && arr[x2-1][y2] == 0 && arr[x2][y2-1] == 0)
            {
                q.push({x2,y2});
                typeQ.push(2);
            }
        }
        else if(type == 2)
        {
            int x2 = x + 1;
            int y2 = y;
            if(x2 < num && y2 < num && arr[x2][y2] == 0)
            {
                q.push({x2,y2});
                typeQ.push(1);
            }
            x2 = x;
            y2 = y + 1;
            if(x2 < num && y2 < num && arr[x2][y2] == 0)
            {
                q.push({x2,y2});
                typeQ.push(0);
            }
            x2 = x + 1;
            y2 = y + 1;
            if(x2 < num && y2 < num && arr[x2][y2] == 0 && arr[x2-1][y2] == 0 && arr[x2][y2-1] == 0)
            {
                q.push({x2,y2});
                typeQ.push(2);
            }
        }
    }
    cout << count;
}

 

