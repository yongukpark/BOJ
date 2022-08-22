//매번 호제법을 까먹는 것 같음
//반복적인 학습으로 잘 기억해야할 것 

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
    int tmp;
    while(b != 0)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n,s,gcdNum = 0; 
    cin >> n >> s;
    
    for(int i = 0 ; i < n ; i++)
    {
        int a;
        cin >> a;
        gcdNum = gcd(gcdNum,abs(a-s));
    }
    cout << gcdNum;
    
}
