//늘 같은 재귀함수처럼 생각만 잘하면 구현에는 문제 없었음
//별찍기 10번이 생각나는 문제였음 

#include <iostream>
using namespace std;

int count;
char arr[3100][6200];

void triangle(int n, int x, int y)
{
    if(n == 3)
    {
        arr[x][y] = '*';
        arr[x+1][y-1] = '*';
        arr[x+1][y+1] = '*';
        for(int i = 0 ; i < 5 ; i++)
        {
            arr[x+2][y-2+i] = '*';
        }
        return;
    }
    triangle(n/2, x, y);
    triangle(n/2,x+n/2,y-n/2);
    triangle(n/2,x+n/2,y+n/2);
    
}

int main()
{
    cin >> count;
    for(int i = 0 ; i < count ; i++)
    {
        for(int j = 0 ; j < count * 2; j++)
        {
            arr[i][j] = ' ';
        }
    }
    
    triangle(count, 0 , count-1);
    
    for(int i = 0 ; i < count ; i++)
    {
        for(int j = 0 ; j < count * 2 - 1; j++)
        {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}
