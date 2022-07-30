//그냥 심심해서 풀어본 문제
//간단하게 공식만 알면 풀수 있음(굳이 dp를 사용하지 않더라도)
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin >> num;
    if(num%2 == 1)
    {
        cout << "CY";
    }
    else
    {
        cout << "SK";
    }
}
