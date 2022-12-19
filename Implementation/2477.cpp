#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <pair<int,int>> v;
    int count[5] = {0,};
    int n; cin >> n;
    for(int i = 0 ; i < 6 ; i++)
    {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
        count[a]++;
    }
    for(int i = 0 ; i < 6;  i++)
    {
        v.push_back(v[i]);
    }
    int res = 1;
    int mres = 1;
    for(int i = 0 ; i < 6 ; i++)
    {
        if(count[v[i].first] == 1)
        {
            res *= v[i].second;
            mres *= v[i+3].second;
        }
    }
    cout << n*(res-mres);
}
