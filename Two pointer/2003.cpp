#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int arr[10003];
    int num , goal;
    cin >> num >> goal;
    
    arr[0] = 0;
    for(int i = 1 ; i <= num ; i++)
    {
        int a;
        cin >> a;
        arr[i] = arr[i-1] + a;
    }
    
    int res = 0;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = i + 1 ; j <= num ; j++)
        {
            if(arr[j] - arr[i] == goal)
            {
                res++;
            }
        }
    }
    cout << res;
}
