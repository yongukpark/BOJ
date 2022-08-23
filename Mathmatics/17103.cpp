//에라토스테네스의 체만 이용하면 간단히 풀수있는 

#include <iostream>
using namespace std;

bool visited[1000003]; //false : prime num / true : non-prime num

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    visited[1] = true;
    for(int i = 2 ; i * i <= 1000000 ; i++)
    {
        if(visited[i])
        {
            continue;
        }
        for(int j = i * i ; j <= 1000000 ; j += i)
        {
            visited[j] = true; 
        }
    }
    
    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        int res = 0;
        int a; cin >> a;
        for(int j = 2 ; j <= a/2 ; j++)
        {
            if(!visited[j] && !visited[a-j])
            {
                res++;   
            }
        }
        cout << res << '\n'; 
    }
}
