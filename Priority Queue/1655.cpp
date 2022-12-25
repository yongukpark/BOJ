// 이 문제는 priority queue라는 특수한 기능을 가진 컨테이너를 적절히 활용하여 구현해내는 문제였음
// 처음에 제한시간 0.1을 보고 조건을 보니 어떻게 풀어야할지 안와서 문제 카테고리를 보았고
// pq를 이용하는 문제라는 것을 알고 난 후는 구현하는 방법이 바로 떠올랐음
// 또한 13-15번의 입출력 속도를 조정하는 코드가 없으니 시간 초과로 틀렸었음

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>>right;
    int a; cin >> a;
    left.push(a);
    cout << left.top() << '\n';
    
    for(int i = 1 ; i < n ; i++)
    {
        cin >> a;
        right.push(a);
        if(i%2 == 1)
        {
            if(left.top() > right.top())
            {
                int l = left.top(); left.pop();
                int r = right.top(); right.pop();
                left.push(r); right.push(l);
            }
        }
        else
        {
            left.push(right.top()); right.pop();
        }
        cout << left.top() << '\n';
    }
}
