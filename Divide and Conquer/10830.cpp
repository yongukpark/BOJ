//분할정복 알고리즘은 많이 접하지 않아서 어렵게 풀었음
//분할정복에 대한 이해가 부족하다고 생각함
//큰 수의 제곱을 푸는 방법에 대해 알았음

#include <iostream>
using namespace std;
int n;
int tmp[5][5];
int arr[5][5];
int res[5][5];

void matricsSqrt(int arr1[5][5] , int arr2[5][5])
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            tmp[i][j] = 0;
            for(int k = 0 ; k < n ; k++)
            {
                tmp[i][j] += (arr1[i][k]*arr2[k][j]); 
            }
            tmp[i][j]%=1000;
        }
    } 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            arr1[i][j] = tmp[i][j];
            
        }
    }
}

int main()
{
    

    long long count; 
    cin >> n >> count;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ;j++)
        {
            cin >> arr[i][j];
            res[i][i] = 1;
        }
    }
    
    while(count)
    {
        if(count%2 == 1)
        {
            matricsSqrt(res, arr);
        }

        matricsSqrt(arr,arr);
        count/=2;
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ;j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
        
    }
}
