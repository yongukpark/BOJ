//아마도 stack으로 DFS를 구현해야 풀기 쉬운 문제인 것 같음
//방문처리를 적절하게 하지 못하면 시간초과가 났고
//graph에서 cycle인 부분을 찾는 문제였음

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void solution()
{
    vector<int>v(100003);
    vector<bool>visited(100003);
    stack<int>s;
    int n; cin >> n;
    int res = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        int a; cin >> a;
        v[i] = a;
    }
    
    for(int i = 1 ; i <= n ; i++)
    {
        if(!visited[i])
        {
            s.push(i);
            while(!s.empty())
            {
                int vertex = s.top();
                visited[vertex] = true;

                if(visited[v[vertex]])
                {
                    int count = 1;
                    while(!s.empty())
                    {
                        if(s.top() == v[vertex])
                        {
                            res += count;
                        }
                        s.pop();
                        count++;
                    }
                    break;
                }
                s.push(v[vertex]);
            }
        }
    }
    cout << n - res << '\n';
}

int main()
{
    int test_case; cin >> test_case;
    for(int i = 0 ; i < test_case ; i++)
    {
        solution();
    }
}
