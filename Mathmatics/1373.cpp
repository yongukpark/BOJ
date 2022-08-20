#include <iostream>
#include <cmath>
#include <stack>
using namespace std;


int main()
{
    string s;
    cin >> s;
    stack <int>s1;
    int res = 0;
    int count = 0;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        if(count == 3)
        {
            count = 0;
            s1.push(res);
            res = 0;
        }
        res+=pow(2,count)*(s[i]-'0');
        count++;
    }
    if(count != 0)
    {
        s1.push(res);
    }
    while(!s1.empty())
    {
        cout << s1.top();s1.pop();
    }
}
