//브루트포스를 공부하고싶지만 대부분 백트래킹이랑 연관되어있는 것 같음
//간단한 브루트포스였던 것 같음
#include <iostream>
#include <algorithm>
using namespace std;

int len, num;
string arr[16];
int aeiou = 0;
int another = 0;

void backTracking(int a, string s, int count)
{
    if(len == count)
    {
        aeiou = 0;
        another = 0;
        for(int i = 0 ; i < len ; i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' )
            {
                aeiou++;
            }
            else
            {
                another++;
            }
        }
        if(aeiou >= 1 && another >= 2)
        {
            cout << s << '\n';
        }
    }
    
    if(a == num)
    {
        return;
    }
    for(int i = a ; i < num ; i++)
    {
        backTracking(i+1, s+arr[i], count+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> len >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+num);
    backTracking(0,"",0);
}
