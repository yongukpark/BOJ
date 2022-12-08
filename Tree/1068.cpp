#include <iostream>
#include <vector>
using namespace std;
vector<int>v[51];
int sum = 0;
int num;
void dfs(int a)
{
    if(v[a].size() == 0 || (v[a].size() == 1 && v[a][0] == num))
    {
        sum += 1;
        return;
    }
    
    for(int i = 0 ; i < v[a].size() ; i++)
    {
        if(v[a][i] == num){
            continue;
        }
        dfs(v[a][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    
    int n;
    int root;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int a; cin >> a;
        if(a == -1)
        {
            root = i;
            continue;
        }
        v[a].push_back(i);
    }
    cin >> num;
    if(root == num)
    {
        cout << 0;
        return 0;
    }
    dfs(root);
    
    cout << sum;
    
}
