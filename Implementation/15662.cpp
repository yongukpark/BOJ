//right left rotate만 구성할줄 안다면 충분히 구현할수 있다고 생각함

#include <iostream>
#include <cmath>
using namespace std;

int num;
char arr[1003][8];


void spin(int arrNum, int d, int go) //톱니바퀴 번호, 회전방향
{
    if(go == 0)
    {
        if(arrNum != 0)
        {
            if(arr[arrNum - 1][2] != arr[arrNum][6])
            {
                spin(arrNum-1, -d, -1);
            }
        }
        
        if(arrNum != num - 1)
        {
            if(arr[arrNum][2] != arr[arrNum+1][6])
            {
                spin(arrNum+1, -d, 1);
            }
        }  
    }
    if(go == -1)
    {
        if(arrNum != 0)
        {
            if(arr[arrNum - 1][2] != arr[arrNum][6])
            {
                spin(arrNum-1, -d, -1);
            }
        }
    }
    
    if(go == 1)
    {
        if(arrNum != num - 1)
        {
            if(arr[arrNum][2] != arr[arrNum+1][6])
            {
                spin(arrNum+1, -d, 1);
            }
        } 
    }
    
    
    if(d == -1)
    {
        char tmp = arr[arrNum][0];
        for(int i = 1 ; i < 8 ; i++)
        {
            arr[arrNum][i - 1] = arr[arrNum][i];
        }
        arr[arrNum][7] = tmp;
    }
    else
    {
        char tmp = arr[arrNum][7];
        for(int i = 6 ; i >= 0 ; i--)
        {
            arr[arrNum][i + 1] = arr[arrNum][i];
        }
        arr[arrNum][0] = tmp;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    int spinCount;
    cin >> spinCount;
    for(int i = 0; i < spinCount ; i++)
    {
        int a,b;
        cin >> a >> b;
        spin(a - 1,b,0);
  
           
    }
    int res = 0;
    for(int i = 0 ; i < num ; i++)
    {
       if(arr[i][0] == '1')
        {
            res++;
        } 
    }
    
    
    
    cout << res;
}


