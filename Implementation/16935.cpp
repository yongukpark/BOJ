//귀찮음

#include <iostream>
using namespace std;

int arr[103][103];
int tmpArr[103][103];
int n,m,num;

void turnLeft()
{
    int tmp = n;
    n = m;
    m = tmp;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
        {
            tmpArr[i][j] = arr[j][n-1-i];
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
        {
            arr[i][j] = tmpArr[i][j];
        }
    }    

}


void turnRight()
{
    int tmp = n;
    n = m;
    m = tmp;
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
        {
            tmpArr[i][j] = arr[m - 1 - j][i];
        }
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
        {
            arr[i][j] = tmpArr[i][j];
        }
    }    

}


void upDown()
{
    for(int i = 0 ; i < n/2 ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            int tmp = arr[i][j];
            arr[i][j] = arr[n-i-1][j];
            arr[n-i-1][j] = tmp;
        }
    }
}

void leftRight()
{
    for(int i = 0 ; i < m / 2 ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            int tmp = arr[j][i];
            arr[j][i] = arr[j][m-i-1];
            arr[j][m-1-i] = tmp;
        }
    }
}

void five()
{
    for(int i = 0 ; i < n / 2 ; i++)
    {
        for(int j = 0 ; j < m / 2 ; j++)
        {
            tmpArr[i + n/2][j] = arr[i+n/2][j+m/2];
            tmpArr[i][j] = arr[i + n/2][j];
            tmpArr[i][j + m/2] = arr[i][j];
            tmpArr[i+n/2][j+m/2] = arr[i][j+m/2];
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
        {
            arr[i][j] = tmpArr[i][j];
        }
    }
}

void six()
{
    for(int i = 0 ; i < n / 2 ; i++)
    {
        for(int j = 0 ; j < m / 2 ; j++)
        {
            tmpArr[i + n/2][j] = arr[i][j];
            tmpArr[i][j] = arr[i][j + m/2];
            tmpArr[i][j + m/2] = arr[i+n/2][j+m/2];
            tmpArr[i+n/2][j+m/2] = arr[i + n/2][j];
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++)
        {
            arr[i][j] = tmpArr[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> num;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> arr[i][j];            
        }
    }
    
    for(int i = 0 ; i < num ; i++)
    {
        int a;
        cin >> a;
        switch(a)
        {
        case 1:
            upDown();
            break;
        case 2:
            leftRight();
            break;
        case 3:
            turnRight();
            break;
        case 4:
            turnLeft();
            break;
        case 5:
            five();
            break;
        case 6:
            six();
            break;
        }
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout << arr[i][j] << ' ';            
        }
        cout << '\n';
    }
}
