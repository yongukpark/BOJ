//float를 사용했을때는 틀렸었고 double을 사용하니 맞다는 답이 나왔음
//정확한 이유는 모르겠지만 double을 사용했을때 더 정교한 계산이 가능하기때문이라고 생각함

#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    
    int arr[27];
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    
    stack <double> sta;
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            sta.push(arr[s[i]-'A']);
        }
        else if(s[i] == '*')
        {
            double b = sta.top(); sta.pop();
            double a = sta.top(); sta.pop();
            sta.push(a*b);
        }
        else if(s[i] == '+')
        {
            double b = sta.top(); sta.pop();
            double a = sta.top(); sta.pop();
            sta.push(a+b);
        }
        else if(s[i] == '-')
        {
            double b = sta.top(); sta.pop();
            double a = sta.top(); sta.pop();
            sta.push(a-b);
        }
        else if(s[i] == '/')
        {
            double b = sta.top(); sta.pop();
            double a = sta.top(); sta.pop();
            sta.push(a/b);
        }
    }
    cout << fixed << setprecision(2) << sta.top();
}

