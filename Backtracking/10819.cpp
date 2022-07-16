//간단함
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int num;
int arr[9];

bool visited[9];
int order[9];

int res = 0;

int distance()
{
    int tempRes = 0;
    for(int i = 0 ; i < num - 1 ; i++)
    {
        tempRes += abs(arr[order[i]]-arr[order[i+1]]);
    }
    return tempRes;
}

void backTracking(int count)
{
    if(count == num)
    {
        res = max(res,distance());
    }
    
    for(int i = 0 ; i < num ; i++)
    {
        if(visited[i])
        {
            continue;
        }
        visited[i] = true;
        order[count] = i;
        backTracking(count + 1);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    for(int i = 0 ;  i < num ; i++)
    {
        cin >> arr[i];
    }
    
    backTracking(0);
    cout << res;
}

