//일단 결과값이 long long으로 나와야 한다는 것을 인지해야함
//vector에서의 삭제는 O(n)을 따르고 map set 에서의 삭제는 O(n)을 따름
//따라서 이문제는 vector를 이용하여 삭제할경우 시간초과가 나는 문제임 
//용도에 따라 컨테이너를 적절히 활용해야함을 크게 깨달음
#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <map>
using namespace std;

bool compare(pair<int,int>a, pair<int,int>b)
{
    if(a.second == b.second)
    {
        return a.first > b.first;
    }
    
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int jw; cin >> jw;
    int bag; cin >> bag;
    vector <pair<int,int>> vJw;
    for(int i = 0 ; i < jw ; i++)
    {
        int a,b;
        cin >> a >> b;
        vJw.push_back({a,b});
    }
    
    
    map <int,int> vBag;
    for(int i = 0 ; i < bag ; i++)
    {
        int a;
        cin >> a;
        vBag[a]++;
    }
    
   sort(vJw.begin(), vJw.end(), compare); 
   
   long long int count = 0;
   for(int i = 0 ; i < jw ; i++)
   {

        map<int,int>::iterator iter = vBag.lower_bound(vJw[i].first);
        if(iter != vBag.end())
        {
            count += vJw[i].second;
            iter->second--;
            if(iter->second == 0)
            {
                vBag.erase(iter);
            }

        }
   }
   cout << count;
}
