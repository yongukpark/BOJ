//다 좋았지만 testcase가 1인것을 고려하지 못했음
//다음코드에서 testcase가 1이면 v안에는 아무것도 들어있지 않게되지만 while문에서 v[0]에 접근시도함(OutOfBounds)

#include <iostream>
#include <vector>
using namespace std;

bool prime[4000003];
vector <int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num; cin >> num;
    if(num == 1)
    {
        cout << 0;
        return 0;
    }
    for(int i = 2 ; i * i <= num ; i++)
    {
        for(int j = i * i ; j <= num ; j += i)
        {
            prime[j] = true;
        }
    }
    
    for(int i = 2 ; i <= num ; i++)
    {
        if(!prime[i])
        {
            v.push_back(i);
        }
    }
    
    int sum = 2;
    int left = 0;
    int right = 0;
    int res = 0;
    while(v[right] <= num)
    {
        if(sum < num)
        {
            if(right + 1 == v.size())
            {
                break;
            }
            right++;
            sum += v[right];
        }
        else if(sum == num)
        {
            res++;
            sum-=v[left];
            left++;
        }
        else
        {
            sum-=v[left];
            left++;
        }
    }
    cout << res;
}
