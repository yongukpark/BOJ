//쉬움 그리디알고리즘 문제이지만 계산할게 없음
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    string res = "";
    cin >> s;
    
    int count = 0;
    
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == 'X')
        {
            count++;
            continue;
        }
        else if(s[i] == '.')
        {
            if(count % 2 == 1)
            {
                cout << -1;
                return 0;
            }
            while(count != 0)
            {
                if(count >= 4)
                {
                    res += "AAAA";
                    count -= 4;
                }
                else
                {
                    res += "BB";
                    count -= 2;
                }
            }
            res += ".";
        }
    }
    if(count > 0)
    {            
        if(count % 2 == 1)
        {
           cout << -1;
            return 0;
        }
        while(count != 0)
        {
            if(count >= 4)
            {
                res += "AAAA";
                count -= 4;
            }
            else
            {
                res += "BB";
                count -= 2;
            }
        }
    }
    cout << res;
}

