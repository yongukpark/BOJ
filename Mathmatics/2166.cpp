//풀이 방법은 어렵지 않았음 CCW를 사용해서 푸는 문제(신발끈 공식)
//다만 100,000과 100,000을 곱하는 과정에서 overflow가 발생할 것을 예상하지 못하여
//약간의 실수가 있었음

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector <pair<long long,long long>> v;
int n;

void input()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        long long a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
}

void ccw()
{
    long long firstx = v[0].first;
    long long firsty = v[0].second;

    long double res = 0;
    for(int i = 1 ; i < n-1 ; i++)
    {
        long long secondx = v[i].first;
        long long secondy = v[i].second;
        long long thirdx = v[i+1].first;
        long long thirdy = v[i+1].second;

        res += 0.5*(firstx*secondy + secondx*thirdy + thirdx*firsty - secondx*firsty - thirdx*secondy - firstx*thirdy);
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(res);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    input();
    ccw();
    return 0;
}
