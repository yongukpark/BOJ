//음 그냥 백트래킹
#include <iostream>

using namespace std;

int num;
bool check[9];
int arr[9];

void backtracking(int a)
{
    if(a == num)
    {
        for(int i = 0 ; i < num ; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    
    for(int i = 0 ; i < num ; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            arr[a] = i+1;
            backtracking(a+1);
            check[i]= false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    cin >> num;
    backtracking(0);
}
