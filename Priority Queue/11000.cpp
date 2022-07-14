//문제를 보고 그리디라는 것은 알았지만 pq를 쓰는 문제라고는 생각 못함
//문제 카테고리를 보고 pq를 쓴다는 것을 본후에는 어떻게 문제를 풀어야할지 감이 왔음
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int arr[200002];
int main()
{
    vector <pair<int,int>> v;
    priority_queue<int,vector<int>,greater<int>> resPq;
    
    int num; cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end());
    resPq.push(v[0].second);
    
    for(int i = 1 ; i < num ; i++)
    {
        if(v[i].first >= resPq.top())
        {
            resPq.pop();
            resPq.push(v[i].second);
        }
        else
        {
            resPq.push(v[i].second);
        }
    }
    cout << resPq.size();
}

