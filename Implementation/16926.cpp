//아이디어는 떠올리는게 쉬우나 구현하는게 조금 어려웠던 문제였음

#include <iostream>
#include <cmath>
using namespace std;

int arr[301][301];

int n,m,r;

void spin(int count)
{
    if(count == 0)
    {
        return;
    }
    
    for(int i = 0 ; i < min(n,m)/2 ; i++)
    {
        int left = i;
        int right = i;
        int tmp = arr[left][right];
        while(left < n - i - 1)
        {
            left++;
            int t = arr[left][right];
            arr[left][right] = tmp;
            tmp = t;
        }
        while(right < m - i - 1)
        {
            right++;
            int t = arr[left][right];
            arr[left][right] = tmp;
            tmp = t;
        }
        while(left >= 1 + i)
        {
            left--;
            int t = arr[left][right];
            arr[left][right] = tmp;
            tmp = t;
        }
        while(right >= 1 + i)
        {
            right--;
            int t = arr[left][right];
            arr[left][right] = tmp;
            tmp = t;
        }
    }
    
    
    spin(count - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m >> r;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    

    spin(r);
    
    
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout <<  arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
