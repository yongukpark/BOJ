//처음에 시간초과가 났었지만 나의 실수였음
//그다음 75%에서 틀렸고 bool visied를 추가 안해서 틀린거였음
//validate check까지 했음에도 불구하고 bool배열을 쓰고 안쓰고에서 틀린 이유를 잘 모르겠음
//복잡하지만 
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int num, shop;
vector <pair<int,int>> v; //치킨집 좌표
vector <pair<int,int>> vChicken; //살릴 치킨집 좌표
vector <pair<int,int>> house;
int final = INT32_MAX;
bool visited[13];


void selectChicken(int a, int n) //살릴 치킨집 정하는 백트래킹
{
    if(n == shop)
    {
        int res = 0;
        for(int i = 0 ; i < house.size() ; i++)
        {
            int mini = INT32_MAX;
            int x = house[i].first;
            int y = house[i].second;
            for(int j = 0 ; j < vChicken.size() ; j++)
            {
                mini = min(mini, abs(x-vChicken[j].first) + abs(y-vChicken[j].second));
            }
            res += mini;
        }
        final = min(final,res);
        return;
    }
    
    
    for(int i = a ; i < v.size() ; i++)
    {
        if(visited[i])
        {
            continue;
        }
        visited[i] = true;
        vChicken.push_back(v[i]);
        selectChicken(i, n + 1);
        vChicken.pop_back();
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num >> shop;
    
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            int a;
            cin >> a;
            
            if(a == 2)
            {
                v.push_back({i,j});
            }
            else if(a == 1)
            {
                house.push_back({i,j});
            }
        }
    }
    
    selectChicken(0, 0);
    cout << final;
}

