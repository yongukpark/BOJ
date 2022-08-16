
#include <iostream>
using namespace std;

int visited[1203] = {0,};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    for(int i = 1 ; i <= num ; i++)
    {
        visited[i] = 100000000;
    }
    visited[1] = 1;
    for(int i = 1 ; i <= num ; i++)
    {
        int a;
        cin >> a;
        if(visited[i] != 0)
        {
            for(int j = 0 ; j <= a ; j++)
            {
               
                {
                    visited[i + j] = min(visited[i] + 1,visited[i+j]);
                }
            }  
        }
    }
    if(visited[num] == 100000000)
    {
        cout << -1;
    }
    else{
        cout << visited[num] - 1;
    }
}
