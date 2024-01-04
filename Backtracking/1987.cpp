//기본적인 백트래킹 문제였지만 하나의 예외처리 때문에 많이 틀렸음
//2년전에 못푼문제를 2년 후에 풀어서 기분이 매우 좋다

#include <iostream>
#include <string>
using namespace std;

int row, col;
string s[21];
bool visited[26];
int maxi = 0;

void reset_visited()
{
    for(int i = 0 ; i < 26 ; i++)
    {
        visited[i] = false;
    }
}


void move(int x, int y, int cnt)
{
    if(visited[s[x][y]-'A'])
    {
        maxi = max(maxi, cnt);
        return;
    }

    visited[s[x][y]-'A'] = true;
    if(x+1 < row) move(x+1,y,cnt+1);
    if(y+1 < col) move(x,y+1,cnt+1);
    if(x-1 >= 0) move(x-1,y,cnt+1);
    if(y-1 >= 0) move(x,y-1,cnt+1);
    visited[s[x][y]-'A'] = false;
    
    return;
}

int main()
{
    
     cin >> row >> col;
    
    for(int i = 0 ; i < row ; i++)
    {
        cin >> s[i];
    }
    reset_visited();
    move(0,0,0);
    if(maxi == 0)
    {
        cout << 1;
        return 0;
    }
    cout << maxi;
}
