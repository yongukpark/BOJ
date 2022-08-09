//무난함
#include <iostream>
#include <cmath>
using namespace std;

int num; 
int arr[13];
int ar[4];

int mini =  1000000003;
int maxi = -1000000003;

void rec(int a , int sum)
{
    if(a == num)
    {
        maxi = max(maxi,sum);
        mini = min(mini,sum);
        return;
    }
    
    if(ar[0] != 0)
    {
        ar[0]--;
        rec(a+1, sum+arr[a]);
        ar[0]++;
    }
    
    if(ar[1] != 0)
    {
        ar[1]--;
        rec(a+1,sum-arr[a]);
        ar[1]++;
    }
    
    if(ar[2] != 0)
    {
        ar[2]--;
        rec(a+1,sum*arr[a]);
        ar[2]++;
    }
    
    if(ar[3] != 0)
    {
        ar[3]--;
        rec(a+1,sum/arr[a]);
        ar[3]++;
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
    for(int i = 0 ; i < 4 ; i++)
    {
        cin >> ar[i];
    }
    
    rec(1,arr[0]);
    cout << maxi <<'\n' << mini;
    
}
