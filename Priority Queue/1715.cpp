//그리디 알고리즘 자체가 생각을 많이해야해서 난이도가 높게 평가 받는 것 같음
//골드4 문제였는데 우선순위큐를 구현할줄만 알면 간단히 풀수 있는 그런 문제였음
//자동정렬이 되어야한다는 것을  처음에는 map으로 구현하였지만 틀리고 우선순위큐로 구현하였음
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<int,vector<int>,greater<int>>q;
    
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        int a; cin >> a;
        q.push(a);
    }
    int res = 0;
    while(q.size() != 1)
    {
        int a1 = q.top();
        q.pop();
                
        int a2 = q.top();
        q.pop();
        
        res += (a1+a2);
        q.push(a1+a2);
    }

    cout <<res;
}
