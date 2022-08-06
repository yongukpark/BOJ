//확인을 위한 함수를 하나 만들어야 한다는 점에서 조금 복잡했던 문제였음
//check 함수와 같이 sum을 이용하여 한번에 계산하지 않으면 시간초과가 날수도 있다고 생각되는 문제임
#include <iostream>
using namespace std;

int num;
char arr[11][11];
int res[11];

bool check(int a)
{
    int sum = 0;
    for(int i = a ; i >= 0 ; i--)
    {
        sum += res[i];
        if(arr[i][a] == '+' && sum <= 0)
        {
            return false;
        }
        if(arr[i][a] == '-' && sum >= 0)
        {
            return false;
        }
        if(arr[i][a] == '0' && sum != 0)
        {
            return false;
        }
    }
    return true;
}

void bf(int count)
{
    if(count == num)
    {
        for(int i = 0 ; i < num ; i++)
        {
            cout << res[i] << ' ';
        }
        exit(0);
    }
    for(int i = -10 ; i <= 10 ; i++)
    {
        res[count] = i;
        if(check(count)){
            bf(count + 1);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = i ; j < num ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    bf(0);
    
}
