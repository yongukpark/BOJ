//stack을 적절히 사용하면 풀수 있는 문제였음

#include <iostream>
#include <stack>
using namespace std;

int arr[1000003];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    stack <int> s, s2, res;
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        int a;
        cin >> a;
        arr[a] += 1;
        s.push(a);
    }
    
    while(!s.empty())
    {
        int a = s.top(); s.pop();

        while(!s2.empty())
        {
            if(arr[s2.top()] <= arr[a])
            {
                s2.pop();
            }
            else
            {
                break;
            }
        }
        
        if(s2.empty())
        {
            res.push(-1);
            s2.push(a);
        }
        else
        {
            res.push(s2.top());
            s2.push(a);
        }
        
    }
    
    while(!res.empty())
    {
        cout << res.top() <<' '; res.pop();
    }
}
