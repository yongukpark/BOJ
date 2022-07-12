//정렬 문제라기 보다는 기본적인 투포인터 문제엿음

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[100003];
    
    int num; cin  >> num;
    for(int i = 0 ; i < num ; i ++)
    {
        cin >> arr[i];    
    }
    
    int x; cin >> x;
    
    sort(arr, arr+num);
    
    int count = 0;
    int left=0,right=num-1;
    while(left < right)
    {
        int sum = arr[left]+arr[right];
        if(sum > x){
            right--;
        }
        else if(sum < x){
            left++;
        }
        else{
            count++;
            left++;
        }
    }
    cout << count;
}
