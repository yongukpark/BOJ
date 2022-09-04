//test case가 100만 이기에 기본적인 LIS 문제처럼 n^2을 이용하여 풀면 시간초과가남
//때문에 binarysearch를 이용하여 nlogn의 시간복잡도를 이용하여 해결해야하는 문제였음

#include <iostream>
using namespace std;
int arr[1000003];
int dp[1000003];

int binarySearch(int start, int end, int goal)
{
    int mid;
    while(start < end)
    {
        mid = (start + end)/2;
        if(dp[mid] < goal)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];   
    }
    
    dp[0] = arr[0];
    int flg = 0;
    int i = 1;
    while(i < num)
    {
        if(dp[flg] < arr[i])
        {
            flg++;
            dp[flg] = arr[i];
        }
        else
        {
            int pos = binarySearch(0,flg,arr[i]);
            dp[pos] = arr[i];
        }
        i++;
    }
    cout << flg + 1; 
}
