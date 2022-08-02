#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int n,m;
int res[10];

void dfs(int count)
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
    
    for(int i = 0 ; i < n ; i++)
    {
        res[count] = arr[i];
        dfs(count + 1);
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
    dfs(0);
}
