//이문제는 100만개의 case가 있기에 일반적인 비트마스크로 구현할 수 없는 문제임
//이문제는 비트마스크를 실제로 구현하는 문제가 아닌 얼마나 잘 이해하고있는지 묻는 문제임
// K = K-(K&((~K)+1)) 를 잘 살펴보면 (~k)+1은 논리회로에서 배운 k의 2의보수임을 알수 있음
//그리고 k&k의 보수를 하게되면 최하위 1인 비트의 값만 남게됨
//즉 k-(k의 최하위 비트 1인비트)가 0이된다는 것은 곧 k에 있는 총 1의 개수많큼 루프를 돌아야한다는 말임 
#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    int count = 0;
    for(int i = 0 ; i < num ; i++)
    {
        char c;
        cin >> c;
        if(c=='1')
        {
            count++;
        }
    }
    
    cout << count;
}


