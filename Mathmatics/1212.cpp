#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    
    if(s == '0')
    {
        cout << 0;
        return 0;
    }
    bool flg = false;
    for(int i = 0 ; i < s.length(); i++)
    {
        int a = s[i] -'0';
        for(int j = 2 ; j >= 0; j--)
        {
            if(a != 0 && a >= 2 * j)
            {
                a -= 2*j;
                cout << 1;
                flg = true;
            }
            else
            {
                if(flg)
                {
                    cout << 0;
                }
            }
        }
    }
    
    
}
