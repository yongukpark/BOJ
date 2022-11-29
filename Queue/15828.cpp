//기본적인 예제
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue <int> q;
    int n;
    cin >> n;
    
    int a;
    cin >> a;
    while(a != -1)
    {
        if(a == 0)
        {
            q.pop();
        }
        else
        {
            if(q.size() < n)
            {
                q.push(a);
            }
        }
        cin >> a;
    }
    if(q.empty())
    {
        cout << "empty"; return 0;
    }
    while(!q.empty())
    {
        cout << q.front() << ' '; q.pop();
    }
}
