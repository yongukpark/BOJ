//1~N까지의 수들 중 i를 약수로 가지는 수의 개수는 N/i 개임 (이유는 살짝만 생각해보면 알수 있음)
//이러한 수들의 합을 구하려면 (N/i)*i 를 하면 됨
#include <iostream> 
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num; cin >> num;
    long long res = 0;
    for(int i = 1 ; i <= num ; i++)
    {
        res += num/i * i;
    }
    cout << res;
    
}
