//동전이 하나만 떨어져야하기에 조건이 조금 까다롭지만 그래도 크게 어렵진 않았음
//처음에 bool배열로 방문체크를 하였지만 2개의 동전의 경우를 한번에 고려해서 visited를 설정해야하지만 각각 따로 해서 틀렸음
#include <iostream>
#include <cmath>
using namespace std;

int row,col;
char arr[21][21];
int res = 100;
int coin[2][2];
int moveX[4] = {-1,1,0,0};
int moveY[4] = {0,0,-1,1};

void backTracking(int count)
{
    if(count == 10)
    {
        res = min(11 , res);
        return;
    }
    
    int tmpCoin[2][2];
    tmpCoin[0][0] = coin[0][0];
    tmpCoin[0][1] = coin[0][1];
    tmpCoin[1][0] = coin[1][0];
    tmpCoin[1][1] = coin[1][1];
    for(int i = 0 ; i < 4 ; i++)
    {
        int coin1X = coin[0][0] + moveX[i];
        int coin2X = coin[1][0] + moveX[i];
        int coin1Y = coin[0][1] + moveY[i];
        int coin2Y = coin[1][1] + moveY[i];
        if((coin1X < 0 || coin1X >= row || coin1Y < 0 || coin1Y >= col) && (coin2X >= 0 && coin2X < row &&coin2Y >= 0 && coin2Y < col))
        {
            res = min(res,count + 1);  
            return;
        }
        
        if((coin2X < 0 || coin2X >= row || coin2Y < 0 || coin2Y >= col) && (coin1X >= 0 && coin1X < row &&coin1Y >= 0 && coin1Y < col))
        {
            res = min(res,count + 1);  
            return;
        }
        
        if(arr[coin1X][coin1Y] == '.' || arr[coin1X][coin1Y] == 'o')
        {
            coin[0][0] = coin1X;
            coin[0][1] = coin1Y;
            
        }
        
        if(arr[coin2X][coin2Y] == '.' || arr[coin2X][coin2Y] == 'o')
        {
            coin[1][0] = coin2X;
            coin[1][1] = coin2Y;
            
        }
        
        backTracking(count+1);
        
        coin[0][0] = tmpCoin[0][0];
        coin[0][1] = tmpCoin[0][1];
        coin[1][0] = tmpCoin[1][0];
        coin[1][1] = tmpCoin[1][1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int coinCount = 0;
    cin >> row >> col;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)        
        {
            cin >> arr[i][j];
            if(arr[i][j] == 'o')
            {
                coin[coinCount][0] = i;
                coin[coinCount][1] = j;
                coinCount++;
            }
        }
    }
    
    backTracking(0);
    if(res == 11)
    {
        cout << -1;
        return 0;
    }
    cout << res;
}
