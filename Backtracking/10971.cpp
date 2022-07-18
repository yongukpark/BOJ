//간단했음 (외판원 순환문제)
#include <iostream>
#include <cmath>
using namespace std;

int arr[10][10];
int num;
int res = 100000000;
bool visited[10];
int start;

void backtracking(int s, int a, int now)
{
    if(a == num && arr[now][start])
    {
        res = min(res, s + arr[now][start]);
        return;
    }
    
    for(int i = 0 ; i < num ; i++)
    {
        if(!visited[i] && arr[now][i] != 0)
        {
            visited[i] = true;
            backtracking(s+arr[now][i] , a+1 , i);
            visited[i] = false;
        }
        
    }
}

void input()
{
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            cin >> arr[i][j];
        }
    } 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    for(int i = 0 ; i < num ; i++)
    {
        start = i;
        visited[i] = true;
        backtracking(0,1,i);
        visited[i] = false;
    }
    cout << res;
}
