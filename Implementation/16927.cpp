//문제의 아이디어는 떠올리기 쉬웠으나 중간에 count의 값을 설정하는 과정에서 너무 어리석게 계산을 했음

#include <iostream>
#include <cmath>
using namespace std;

int arr[301][301];

int n,m,r;

void spin()
{
    int depth = min(n,m)/2;
    
    for(int i = 0 ; i < depth ; i++)
    {
        int count = r%(2*(n+m)-4-8*i);
        
        for(int j = 0 ; j < count ; j++)
        {   
            int tmp = arr[i][i];
            for(int k = i ; k < m - i - 1 ; k++)
            {
                arr[i][k] = arr[i][k+1];
            }
            for(int k = i ; k < n - i - 1 ; k++)
            {
                arr[k][m-i-1] = arr[k+1][m-i-1];
            }
            for(int k = m - i - 1 ; k > i ; k--)
            {
                arr[n-i-1][k] = arr[n-i-1][k-1];
            }
            for(int k = n - i - 1 ; k > i + 1; k--)
            {
                arr[k][i] = arr[k-1][i];
            }
            arr[i + 1][i] = tmp;
        }
    }
    
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
    

    spin();
    
    
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout <<  arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
