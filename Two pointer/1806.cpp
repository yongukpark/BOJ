//일반저긍로 처음과 끝에서 시작하는 투포인터 문제를 많이 접했었는데 같은 곳에서 점점 나가면서 하는 투포인터는 새로웠음
#include <iostream>
#include <cmath>
using namespace std;
int arr[100003];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    int num , goal;
    cin >> num >> goal;
    
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
        
    }
    
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int res = 1000000000;
    while(left <= right && right < num)
    {
        if(sum < goal)
        {
            right++;
            sum += arr[right];
        }
        else if(sum == goal)
        {
            res = min(res, right-left + 1);
            right++;
            sum += arr[right];
        }
        else
        {
            res = min(res, right-left + 1);
            sum -= arr[left];
            left++;
        }
    }
    if(res == 1000000000)
    {
        cout << 0;
    }
    else
    {
        cout << res;
    }
}



