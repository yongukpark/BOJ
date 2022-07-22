//13904문제와 동일함
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool arr[10001];

struct compare
{
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        if(a.second == b.second)
        {
            return a.first < b.first;
        }
        
        return a.second < b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        int a,b;
        cin >> a >> b;
        pq.push({b,a});
    }
    
    int res = 0;
    
    while(!pq.empty())
    {
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        for(int i = a ; i > 0 ; i--)
        {
            if(!arr[i])
            {
                arr[i] = true;
                res += b;
                break;
            }
        }
    }
    cout << res;
}
