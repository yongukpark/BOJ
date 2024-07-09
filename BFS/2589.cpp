// 최단거리 중 최장거리를 구하는 문제 였음
// BFS와 BruteForce를 합하여 푸는 전형적인 문제였음

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int row, col; 
char arr[53][53];
bool visited[53][53];
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};
int maxi = 0;

void backTracking(int a, int b)
{
    queue<pair<int,int>>q;
    queue<int>count;
    q.push({a,b});
    count.push(0);
    visited[a][b] = true;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int c = count.front();
        q.pop(); count.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int xx = movex[i] + x;
            int yy = movey[i] + y;

            if(xx >= row || yy >= col || xx < 0 || yy < 0) continue;
            if(arr[xx][yy] == 'W' || visited[xx][yy]) continue;

            visited[xx][yy] = true;
            q.push({xx,yy});
            count.push(c+1);
            if(maxi < c+1)
            {
                maxi = c+1;
            }
        }
    }

}

void clear()
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            visited[i][j] = false;
        }
    }
}

void backTracking_wrapper()
{
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            if(arr[i][j] == 'L')
            {
                clear();
                backTracking(i,j);
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cin >> arr[i][j];
        }
    }
    backTracking_wrapper();
    cout << maxi;
}
