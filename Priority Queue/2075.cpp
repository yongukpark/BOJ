//맨처음 pq를 쓰는 문제인지 몰랐음
//또한 1500*1500개를 모두 pq에 담으면 메모리 초과가 나기에 공간활용을 충분히 하면서 담아야함
//ios::sync_with_stdio(false)가 없으면 시간초과가 남 중요성을 또 한번 깨달음
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int arr[1502][1502];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num = 0; 
    cin >> num;
    
    priority_queue<int,vector<int>,greater<int>>pq;
    
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            int a;
            cin >> a;
            if(pq.size() < num)
            {
                pq.push(a);
            }
            else
            {
                if(pq.top() < a)
                {
                    pq.pop();
                    pq.push(a);
                }
            }
                
            
        }
    }
    cout << pq.top();
}
