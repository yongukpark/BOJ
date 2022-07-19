//구현방법은 굉장히 빨리 떠올랐지만 생각보다 구현하는데에 애를 썼음
//algorithm라이브러리의 reverse함수를 통해 string도 뒤집을 수 있음을 알았음
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string res = "";
    map<char,int>m;
    string s;
    cin >> s;
    
    for(int i = 0 ; i < s.length() ; i++)
    {
        m[s[i]]++;
    }
    
    int cnt = 0;
    
    map <char,int>::iterator it;
    
    for(auto i = m.begin() ; i != m.end() ; i++)
    {
        if(i->second%2==1)
        {
            it = i;
            cnt++;
        }

        for(int j = 0 ; j < i->second/2 ; j++)
        {
            res += i->first;
        }
    }
    
    if(cnt > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    string reverseRes = res;
    reverse(reverseRes.begin(),reverseRes.end());
    if(cnt == 0)
    {
        cout << res + reverseRes;
        return 0;
    }
    res = res + it->first + reverseRes;
    
    cout << res;

}
