//후위표기식에 대한 공부가 조금 필요해보임
//후위표기식의 원리를 알면 쉽게 풀수있는 문제였던 것같음
//간단히 말해 우선순위가 낮은 연산자가 나올경우 stack에 있는 그 연산자보다 우선순위가 높은 연산자들은 모두 나와야함

#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main()
{
    string s;
    cin >> s;
    
    stack <char> sta;
    string res;
    
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
        }
        else if(s[i]== '+' || s[i] == '-')
        {
            while(!sta.empty() && sta.top() != '(')
            {
                res+= sta.top() ; sta.pop();
            }
            sta.push(s[i]);
        }
        else if(s[i] == '*' || s[i] == '/')
        {
            while(!sta.empty() && (sta.top() == '*' || sta.top() =='/'))
            {
                res+= sta.top() ; sta.pop();
            }
            sta.push(s[i]);
        }
        else if(s[i] == '(')
        {
            sta.push(s[i]);
        }
        else
        {
            while(sta.top() != '(')
            {
                res+= sta.top() ; sta.pop();
            }
            sta.pop();
        }
    }
    while(!sta.empty())
    {
        res += sta.top(); sta.pop();
    }
    cout << res;
}
