//pass-by-reference를 사용한 이유는 큰 이유없고 OnlineGDB가 컴파일시 전역변수를 컴파일 못하기에 그냥 한것임

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int num; 

int arr[23];

void rec(int a , int sum, set <int> &s)
{
    if(a == num)
    {
        return;
    }
    s.insert(sum + arr[a]);
    rec(a+1,sum , s);
    rec(a+1,sum+arr[a], s);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    set <int> s;    
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
    }
    
    rec(0,0,s);
    
    int count = 1;
    for(auto i = s.begin() ; i != s.end(); i++)
    {
        if(*i != count)
        {
            cout << count;
            return 0;
        }
        count++;
    }
    cout << count;
}
