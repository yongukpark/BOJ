//문제의 아이디어는 쉽게 올릴수 있지만 더 쉽게 푸는 방법이 존재했음
//특히 부모 배열을 만들어 각각 이전의 값을 넣어준다라는 것은 좀 신기하게 다가왔음

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int arr[200003][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    
    queue <int> q;
    q.push(n);
    arr[n][0] = 0;
    
    while(!q.empty())
    {
        int a = q.front(); q.pop();
        
        if(a == m)
        {
            break;
        }
        
        for(int next : {a+1,a-1,a*2})
        {
            if(next >= 0 && next <= 200000 && !arr[next][0] && next != n)
            {
                arr[next][0] = arr[a][0] + 1;
                arr[next][1] = a;
                q.push(next);
            }
        }
    }
    
    stack <int> res;

    cout << arr[m][0] << '\n';
    int tmp = m;
    res.push(m);
    while(1)
    {
        if(res.top() == n)
        {
            break;
        }
        res.push(arr[res.top()][1]);
    }
    
    while(!res.empty())
    {
        cout << res.top() << ' '; res.pop();
    }
}
