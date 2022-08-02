#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int n,m;
int res[10];

void dfs(int count, int a)
{
    if(count == m)
    {
        for(int i = 0 ; i < m ; i++)
        {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int postNum = 0;
    for(int i = a ; i < n ; i++)
    {
        if(arr[i] == postNum)
        {
            continue;
        }
        res[count] = arr[i];
        postNum = arr[i];
        dfs(count + 1 , i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];   
    }
    
    sort(arr,arr+n);
    dfs(0,0);
}
