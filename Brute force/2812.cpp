//처음엔 배열로 그냥 구현하다가 실패함
//그 후 stack두개를 이용하면 쉽게 풀릴 것임을 깨닫고 쉽게 
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    stack <char> s1;
    stack <char> s2;
    
    int num , k;
    cin >> num >> k;
    string s;
    cin >> s;
    
    for(int i = s.length() - 1 ; i >=0 ; i--)
    {
        s2.push(s[i]);
    }
    
    for(int i = 0 ; i < k ; i++)
    {
        if(s1.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
        while(!s2.empty())
        {
            if(s1.top() < s2.top())
            {
                s1.pop();
                break;
            }
            s1.push(s2.top());
            s2.pop();
        }
        
        if(s2.empty())
        {
            s1.pop();
        }
    }
    
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    
    while(!s2.empty())
    {
        cout << s2.top();
        s2.pop();
    }
}


