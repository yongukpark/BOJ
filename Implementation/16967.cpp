#include <iostream>
using namespace std;

int arr[603][603];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,m,x,y; cin >> n >> m >> x >> y;
    for(int i = 0 ; i < n + x ; i++)
    {
        for(int j = 0 ; j < m + y ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = x ; i < n ; i++)
    {
        for(int j = y ; j < m ; j++)
        {
            arr[i][j] -= arr[i-x][j-y];
        }
    }
    
    for(int i = 0 ; i < n  ; i++)
    {
        for(int j = 0 ; j < m  ; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}





