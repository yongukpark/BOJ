//비트마스킹 너무어려운 것 같음
//여러 종류의 문제를 풀면서 익혀야 할 것 같음

#include <iostream>
#include <set>
#include <bitset>
using namespace std;

long long arr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t; cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        int num;
        cin >> num;
        for(int j = 0 ; j < num ; j++)
        {
            int a; cin >> a;
            arr[i]|=((long long)1<<a);
        }
        
    }
    int student; cin >> student;
    for(int i = 0 ; i < student ; i++)
    {
        long long s = 0;
        int num;
        cin >> num;
        for(int j = 0 ; j < num ; j++)
        {
            int a; cin >> a;
            s |= ((long long)1<<a);
        }
        int count = 0;
        for(int j = 0 ; j < t ; j++)
        {
            if((s&arr[j]) == arr[j])
            {
                count++;       
            }
        }
        cout << count << '\n';
    }
}


