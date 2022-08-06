//Modular Arithmetics를 사용하여 해결하는 문제임

#include <iostream> 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int a;
    while(cin >> a)
    {
        int cnt = 1;
        int res = 1;
        while(1)
        {
            if(res % a == 0)
            {
                cout << cnt << '\n';
                break;
            }
        
            res = ((res*10)%a + 1) % a;
            cnt++;    
        }

    }
}
