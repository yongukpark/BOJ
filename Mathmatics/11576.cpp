//약 15개월전 동아리에서 줬을때 이 문제를 틀렸고 푼 코드마저 어이없을 정도로 이상하지만
//15개월 후인 지금 이 문제를 아무어려움없이 간단히 풀었음
//나름 보람차고 의미있는 문제였다고 생각하고 내가 성장하고 있다라는 것을 느꼈음
//지금 하는 공부에 엄청 큰 동기부여가 되었다고 

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a,b;
    cin >> a >> b;
    int n;
    cin >> n;
    
    
    int decimal = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int k; cin >> k;
        decimal += k * pow(a,n-1-i);
    }
    
    stack <int> s;
    
    while(decimal != 0)
    {
        s.push(decimal%b);
        decimal /= b;
    }
    
    while(!s.empty())
    {
        cout << s.top() << ' '; s.pop(); 
    }
}
