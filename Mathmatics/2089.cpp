#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    if(num == 0)
    {
        cout << 0;
        return 0;
    }
    
    string s = "";
    while(num != 0)
    {
        if(num % -2 == 0)
        {
            s += "0";
            num /= -2;
        }
        else
        {
            s += "1";
            num = (num-1) / -2;
        }
    }
    reverse(s.begin(),s.end());
    cout <<s;
}
