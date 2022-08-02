//문제자체는 어렵지 않았으나 문제가 조금 모호해서 인터넷을 통해 이해함
//a-b b-c c-d d-e 인 총 4개의 경우가 있어야함 물론 testcase에 상관없이 4개만 있으면 되는거라는 것을 알았음
//또한 일반적인 친구관계 문제처럼 a-b b-c 라면 a-c는 친구가 아니라 딱 직접적인 친구관계만 해당된다는 것을 알았음
//이런것들을 안다는 전제하에는 구현하는것에 큰 문제는 없었다고 생각함
#include <iostream>
#include <vector>
using namespace std;

int person, num;
vector <int> v[2003];
bool visited[2003];
void dfs(int count, int a)
{
    visited[a] = true;
    if(count == 4)
    {
        cout << 1;
        exit(0);
    }
    
    for(int i = 0 ; i < v[a].size() ; i++)
    {
        if(visited[v[a][i]] == false)
        {
            dfs(count + 1 , v[a][i]);
        }
    }
    
    visited[a] = false; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> person >> num;
    
    for(int i = 0 ; i < num ; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    
    for(int i = 0 ; i < num ; i++)
    {
        dfs(0,i);
    }
    cout << 0;
}
