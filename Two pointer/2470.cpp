//기본적인 투포인터 문제임

#include <iostream>
#include <algorithm>
using namespace std;

int arr[100003];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num; cin >> num;
    for(int i = 0 ; i < num ; i++){
        cin >> arr[i];
    }
    sort(arr,arr+num);
    int less = abs(arr[0] + arr[num-1]);
    int a = arr[0],b = arr[num-1],left=0,right=num-1;
    while(left < right - 1)
    {
        if(arr[left] + arr[right] < 0)
        {
            left++;
        }
        else{
            right--;
        }
        if(abs(arr[left]+arr[right]) < less)
        {
            a = arr[left];
            b = arr[right];
            less = abs(arr[left]+arr[right]);
        }
    }
    cout << a << ' ' << b;
}
