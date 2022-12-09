//문제의 포인트는 시간복잡도를 어떻게 해결하느냐 이었음

#include <iostream>
#include <string>
using namespace std;

int arr[26][200003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    string s;
    char c;
    int num, start, end;
    cin >> s;
    cin >> num;
    for(int i = 0 ; i < 26 ; i++)
    {
        int sum = 0;
        if(i+'a' == s[0])
        {
            arr[i][0] = 1;
        }
        else
        {
            arr[i][0] = 0;
        }
        for(int j = 1 ; j < s.length() ; j++)
        {
            if(i+'a' == s[j])
            {
                arr[i][j] = arr[i][j-1]+1;
            }
            else
            {
                arr[i][j] = arr[i][j-1];
            }
        }
    }
    for(int i = 0 ; i < num ; i++)
    {
        cin >> c >> start >> end;
        if(start == 0)
        {
            cout << arr[c-'a'][end];
        }
        else
        {
            cout << arr[c-'a'][end]-arr[c-'a'][start-1];
        }
        cout << '\n';
    }
    
}
