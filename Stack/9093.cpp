//getline을 사용하기전에는 cin.ignore()이라는 메소드로 버퍼를 비워주고 시작해야함
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    stack <char> st;

    int testCase;
    cin >> testCase;
    cin.ignore();
    for(int i = 0 ; i < testCase ; i++)
    {
        string s;
        getline(cin,s);
        for(int j = 0 ; j < s.length() ; j++)
        {
            if(s[j] == ' ')
            {
                while(!st.empty())
                {
                    cout << st.top(); st.pop();
                }
                cout << ' ';
            }
            else
            {
                st.push(s[j]);
            }
            
        }
        while(!st.empty())
        {
            cout << st.top(); st.pop();
        }
        cout << '\n';
    }
}
