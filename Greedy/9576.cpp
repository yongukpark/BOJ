//처음에는 first에 맞추어 정렬을 하였음
//ex) 1 3 / 2 3 / 2 4 / 3 3  --> 1 3 / 2 3 / 2 4 / 3 3 
//하지만 이렇게하면 3 3을 충분히 배정할 수 있는데에도 배정하지 못하는 불상사가 발생함
//하지만 second에 맞추게 되면
// 1 3 / 2 3 / 3 3 / 2 4 가 되므로 3 3 또한 포함을 시킬 수 있음
//앞보다도 뒤에 여유가 있는 책들을 우선순위를 조금 덜 주고 뒤에 부분이 여유가 적은 책들에게 우선순위를 주며 효율적으로 그리디 알고리즘을 구현할 수 있음

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool arr[1003];

struct compare
{
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        if(a.second == b.second)
        {
            return a.first > b.first;
        }
        
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    
    int testCase;
    cin >> testCase;
    for(int i = 0 ; i < testCase ;i++)
    {
        for(int i = 0 ; i <= 1000 ; i++)
        {
            arr[i] = false;
        }
        int book,num;
        cin >> book >> num;
        for(int i = 0 ; i < num ; i++)
        {
            int a,b;
            cin >> a >> b;
            pq.push({a,b});
        }
        
        int count = 0; 
        
        while(!pq.empty())
        {
            int start = pq.top().first;
            int end = pq.top().second;
            pq.pop();
            for(int i = start ; i <= end ; i++)
            {
                if(!arr[i])
                {
                    arr[i]= true;
                    count++;
                    break;
                }
            }
        }
        cout << count <<'\n';
    }

}
