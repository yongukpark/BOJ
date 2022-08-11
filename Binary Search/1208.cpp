//meet in the middle 기법을 처음사용해 보는 문제여서 어려운 것 같았음
//lower_bound, upper_bound 등의 라이브러리 함수를 잘 활용하면 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[41];
int num, goal;
vector<int> v1,v2;

void bf(int start, int end, int sum, int type)
{
    if(start == end)
    {
        if(type == 1)
        {
            v1.push_back(sum);
        }
        else
        {
            v2.push_back(sum);
        }
        return;
    }
    
    bf(start + 1 , end , sum , type);
    bf(start + 1 , end , sum + arr[start] , type);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    cin >> num >> goal;
    
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
    }
    
    bf(0, num/2 , 0, 1);
    bf(num/2 , num , 0 , 2);
    
    long long res = 0;
    sort(v1.begin(), v1.end());
    for(int i = 0 ; i < v2.size() ; i++)
    {
        int head = goal - v2[i];
        int a = lower_bound(v1.begin(), v1.end(), head) - v1.begin();
        int b = upper_bound(v1.begin(), v1.end(), head) - v1.begin();

        res += b - a;
    }
    
    if(goal == 0 && res != 0)
    {
        res--;
    }
    
    cout << res;   
}
