//간단한 백트래킹 문제였음
//IUPC 
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

double arr[10];
bool visited[10];

int num;
int count = 0;

void backTracking(int start, double sum)
{
    
    if(sum >=0.99 && sum <=1.01)
    {
        count++;
    }

    for(int i = start ; i < num ; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            backTracking(i,sum + 1/arr[i]);
            visited[i] = false;
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
    }
    
    backTracking(0,0.0);
    cout << count;
}

