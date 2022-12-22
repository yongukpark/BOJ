#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v[100001];
vector <int> arr(100001);
vector <bool> visited(100001);

int count = 1;

void dfs(int a)
{
    visited[a] = true;
    for(int i = 0 ; i < v[a].size() ; i++)
    {
        if(!visited[v[a][i]])
        {
            ::count++;
            arr[v[a][i]] = ::count;
            dfs(v[a][i]);
        }
    }
}

int main()
{
    int a,b,c; cin >> a >> b >> c;
    for(int i = 0 ; i < b ; i++)
    {
        int d,e; cin >> d >> e;
        v[d].push_back(e);
        v[e].push_back(d);
    }
    
    for(int i = 0 ; i < a ; i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    arr[c] = 1;
    dfs(c);
    for(int i = 1 ; i <= a ; i++)
    {
        cout << arr[i] << '\n';
    }
}
