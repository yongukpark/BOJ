//주사위 전개도에 대해 생각하는 부분이 조금 귀찮았지만 조금만 노력?하면 풀수있었음

#include <iostream>
using namespace std;



int arr[23][23];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    int n,m,x,y,k;
    
    int dice[6]; //   3 
                 //  2015 
                 //   4 
    for(int i = 0 ; i  < 6; i++)
    {
        dice[i] = 0;
    }
    cin >> n >> m >> x >> y >> k;
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0 ; i < k ; i++)
    {
        int a; cin >> a;
        int x2,y2,tmp;
        
        switch(a)
        {
        case 1:
            x2 = x;
            y2 = y + 1;
            if(y2 >= m)
            {
                break;
            }
            tmp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[1];
            dice[1] = tmp;
            x = x2;
            y = y2;
            break;
            
        case 2:
            x2 = x;
            y2 = y - 1;
            if(y2 < 0)
            {
                break;
            }
            tmp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[2];
            dice[2] = tmp;
            x = x2;
            y = y2;
            break;
        case 3:
            x2 = x-1;
            y2 = y;
            if(x2 < 0)
            {
                break;
            }
            tmp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[3];
            dice[3] = tmp;
            x = x2;
            y = y2;
            break;
        case 4:
            x2 = x + 1;
            y2 = y;
            if(x2 >= n)
            {
                break;
            }
            tmp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[4];
            dice[4] = tmp;
            x = x2;
            y = y2;
            break;
        }
        if(x2==x && y2==y)
        {
            if(arr[x2][y2] == 0)
            {
                arr[x2][y2] = dice[5];
            }
            else
            {
                dice[5] = arr[x2][y2];
                arr[x2][y2] = 0;
            }
            cout << dice[0] << '\n'; 
        }
    }
}
