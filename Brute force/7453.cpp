//Meet in the middle을 통하여 풀 수 있는 문제였음
//4000^4 이기에 2*4000^2로 바꾸고 마지막에 4000^2*log(4000^2)를 통해 시간복잡도를 해결함
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v1;
vector <int> v2;
int arr[4003][4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
       
    int num; cin >> num;
    
    //Input
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < 4 ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    //Sum list
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            v1.push_back(arr[i][0]+arr[j][1]);
            v2.push_back(arr[i][2]+arr[j][3]);
        }
    }

    //Find value using Binary Search
    sort(v1.begin(),v1.end());
    long long res = 0;
    for(int i = 0 ; i < v2.size(); i++)
    {
        int a = lower_bound(v1.begin(), v1.end(), -v2[i]) - v1.begin();
        int b = upper_bound(v1.begin(), v1.end(), -v2[i]) - v1.begin();
        res += b-a;
    }
    cout << res;
}
