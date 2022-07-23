//문제 자체가 복잡해 보이지만 top-down기법을 사용할줄 쉽게 풀리는 문제였음
//문제 푸는 방법에 대해서는 빠르게 생각했지만 중간중간 초기화를 안하는 등 어처구니 없는 실수로 문제 푸는 시간이 지연되었음
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

vector<vector<int>> v(1001);

int arr[1001];
bool visited[1001];
int dp[1001];

int num, k;
int goal;

int topDown(int a)
{
    
    if(v[a].size() == 0)
    {
        dp[a] = arr[a];
        visited[a] = true;
        return dp[a];
    }
    
    for(int i = 0 ; i <v[a].size() ; i++)
    {
        if(!visited[v[a][i]])
        {
            visited[v[a][i]] = true;
            int k = topDown(v[a][i]) + arr[a];
            dp[a] = max(k, dp[a]);
        }
        else
        {
            dp[a] = max(dp[v[a][i]] + arr[a],dp[a]);
        }
    }
    
    return dp[a];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    int testCase; cin >> testCase;
    for(int i = 1 ; i <= testCase ;i++)
    {


        cin >> num >> k;
        for(int j = 1 ; j <= num ; j++)
        {
            cin >> arr[j];   
        }
        
        for(int j = 0 ; j < k ; j++)
        {
            int a,b;
            cin >> a >> b;
            v[b].push_back(a);
        }
        
        cin >> goal;
        
        for(int j = 1 ; j <= num ; j++)
        {
            dp[j] = 0;
            visited[j] = false;
        }
        cout << topDown(goal) << '\n';
        for(int j = 1 ; j <= num ; j++)
        {

            v[j].clear();
        }
        
    }
    
    
}

