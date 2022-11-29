#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int arr[100003];

    int n,m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    
    int sum = 0;
    for(int i = 0 ; i < m ; i++)
    {
        sum += arr[i];
    }
    int res;
    res = sum;
    for(int i = m ; i < n ; i++)
    {
        sum = sum + arr[i] - arr[i-m];
        res = max(res,sum);
    }
    cout << res;
}
