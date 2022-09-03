//A섬과 B섬의 각각의 지점에서 '세로절댓값 + 가로절댓값 - 1'이 최단거리라는 것을 생각하면 쉽게 풀수있는 문제였음
//각 섬들을 dfs를 통해 나누었고 위의 계산을 할 지점들은 내륙이 아닌 해안의 값들만 가능하기에 이것또한 체크해주었음

#include <iostream>
#include <queue>
using namespace std;

int arr[103][103];
bool visited[103][103];
vector<pair<int,pair<int,int>>> v;
int movex[4] = {-1,1,0,0};
int movey[4] = {0,0,-1,1};
int n;
int check = 0;
void frag(int x, int y, int count)
{
    for(int i = 0 ; i < 4; i++)
    {
        int x2 = x + movex[i];
        int y2 = y + movey[i];
        if(x2 < 0 || y2 < 0 || x2 >= n || y2 >= n)
        {
            continue;
        }
        if(arr[x2][y2] == 1)
        {
            arr[x2][y2] = count;
            frag(x2,y2,count);
        }
        else if(arr[x2][y2] == 0 && !visited[x][y])
        {
            visited[x][y] = true;
            v.push_back({arr[x][y],{x,y}});
            check++;
        }
    }
    
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int count = 2;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[i][j] == 1)
            {
                arr[i][j] = count;
                frag(i,j,count);
                count++;
            }
        }
    }
    
    int minDistance = 100003;
    for(int i = 0 ; i < check - 1; i++)
    {
        int standard = v[i].first;
        int x = v[i].second.first;
        int y = v[i].second.second;
        for(int j = i + 1 ; j < check ; j++)
        {
            if(v[j].first != standard)
            {
                int distance = abs(x-v[j].second.first) + abs(y-v[j].second.second) -1;
                minDistance = min(distance , minDistance);
            }
        }
    }
    cout << minDistance;
}
