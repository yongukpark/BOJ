//n^1000000005 을 분할정복으로 푸는 문제였음
//+ 모듈러 연산을 사용해야함

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int mod = 1000000007;
int a,b;

int modular(long long b, long long p)
{
    if(p==1)
    {
        return b;
    }

    if(p % 2 == 1)
    {
        return (b *  modular(b,p-1))% mod;
    }

    long long tmp = modular(b, p/2);
    
    return (tmp*tmp)%mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

    int n; cin >> n;

    long long res = 0;

    for(int i = 0 ; i < n ; i++)
    {
        long long a,b;
        cin >> b >> a;
        
        res += (a * (modular(b,mod-2))) % mod;
        res %= mod;
    }

    cout << res;
}
