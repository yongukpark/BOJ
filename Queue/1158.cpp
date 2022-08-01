#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    queue <int> q;
    
    int num, die;
    cin >> num >> die;
    for(int i = 1 ; i <= num ; i++)
    {
        q.push(i);
    }
    int count = 1;
    cout << '<';
    while(q.size()!=1)
    {
        int a = q.front(); q.pop();
        if(count == die)
        {
            cout << a << ", ";
            count = 1;
        }
        else
        {
            count++;
            q.push(a);
        }
    }
    cout << q.front();
    cout << '>';
}
