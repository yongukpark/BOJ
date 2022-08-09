//visited배열을 통해 삭제되는 것처럼 구현함
#include <iostream>
#include <cmath>
using namespace std;

int num; 
int arr[13];
bool visited[13];
long long maxi = 0;

void backTracking(int count , long long sum)
{
    if(count == num - 2)
    {
        maxi = max(sum , maxi);
        return;
    }
    for(int i = 2 ; i <= num - 1; i++)
    {
        if(visited[i])
        {
            continue;
        }
        
        visited[i] = true;
        int left;
        for(int j = i - 1 ; j >= 1 ; j--)
        {
            if(!visited[j])
            {
                left = j;
                break;
            }
        }
        int right;
        for(int j = i + 1 ; j <= num ; j++)
        {
            if(!visited[j])
            {
                right = j;
                break;
            }
        }
        backTracking(count + 1, sum + arr[left]*arr[right]);
        visited[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    for(int i = 1 ; i <= num ; i++)
    {
        cin >> arr[i];
    }
    
    backTracking(0,0);
    cout << maxi;
}
