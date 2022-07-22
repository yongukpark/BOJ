//앞선 다른 문제들과 형태는 비슷해도 같은 코드로 풀게되면 답이 틀리게 나옴
//이유는 범위가 커졌기때문에 시간초과가 남
//따라서 기존의 풀던 for문을 사용하면 안되고 그것을 대체할 다른 알고리즘을 짜야함
//그 결론으로 가중치로 정렬하는 것이 아닌 기한으로 먼저 정렬, 비교한 후 가중치를 비교하는 방법을 사용함
//물론 이 문제로 앞선 다른 문제들을 푸는 것은 가능함

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool arr[200001];

struct compare
{
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        if(a.first == b.first)
        {
            return a.second < b.second;
        }
        
        return a.first > b.first;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    priority_queue<int,vector<int>,greater<int>> resPq;
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        int a,b;
        cin >> a >> b;
        pq.push({a,b});
    }
    
    int count = 1;
    while(!pq.empty())
    {
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        if(count <= a)
        {
            count++;
            resPq.push(b);
        }
        else{
            if(resPq.top() < b)
            {
                resPq.pop();
                resPq.push(b);
            }
        }
    }
    
    int res = 0;
    while(!resPq.empty())
    {
        res += resPq.top(); resPq.pop();
    }
    cout << res;
}
