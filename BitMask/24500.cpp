//이것또한 수학문제였음
//2^n-1일경우 xor을 하지않아도 모든 비트가 1이므로 최대가 되어 한장의 카드만 뽑아도 상관없음
//이 밖의 경우에는 뽑은 카드와 그 카드의 1의 보수인 카드를 찾아야 함
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long num;
    cin >> num;
    long long a = 1;
    while(num > a)
    {
        a = a * 2 + 1;

    }
    if(a==num)
    {
        cout << 1 << '\n' << num;
    }    
    else
    {
        cout << 2 <<'\n'<< (a^num) << '\n' << num;   
    }

}


