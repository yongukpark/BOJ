//기본적인 문제라 생각했지만 우선순위 정하는게 조금 중요했던 것 같음
#include <iostream>
#include <vector>
using namespace std;

int count = 0;
int arr[21];
int num,s;

void backTracking(int res, int a)
{
    if(res == s && a != 0)
    {
        count++;
    }
    
    if(a == num)
    {
        return;
    }
    
    for(int i = a ; i < num ; i++)
    {
        backTracking(res + arr[i], i+1);
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    cin >> num >> s;
    
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];   
    }
    
    backTracking(0,0);

    cout << count;
}
