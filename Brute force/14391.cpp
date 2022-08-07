//비트마스킹 기법을 사용하는데 비트마스킹이라기보다는 true와 false라는 두가지 종류의 경우를 생각하는 기법임
//각각의 비트에 t,f를 할당하게되면 총 2^16으로 시간복잡도는 충분함 
//각각의 t,f에 가로와 세로를 부여하여 각각 알맞는 방향으로 더해나가면됨
//여기서 더하는 팁은 sum = sum*10+a 를 하게되면 배열의 숫자들이 차례차례 나열되는 것처럼 구현가능
#include <iostream>
#include <cmath>
using namespace std;

int arr[6][6];
bool check[6][6];
int row,col;
int res = 0;

void cal()
{
    int allSum = 0;
    for(int i = 0 ; i < row ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < col ; j++)
        {
            if(check[i][j])
            {
                sum = sum*10 + arr[i][j]; 
            }
            else
            {
                allSum += sum;
                sum = 0;
            }
        }
        allSum += sum;
        sum = 0;
    }
    
    for(int i = 0 ; i < col ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j < row ; j++)
        {
            if(!check[j][i])
            {
                sum = sum*10 + arr[j][i]; 
            }
            else
            {
                allSum += sum;
                sum = 0;
            }
        }
        allSum += sum;
        sum = 0;
    }
    
    res = max(res,allSum);
}

void dfs(int r, int c)
{
    if(r == row)
    {
        cal();
        return;
    }
    if(c == col)
    {
        dfs(r+1,0);
        return;
    }
    
    check[r][c] = false;
    dfs(r,c+1);
    check[r][c] = true;
    dfs(r,c+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    cin >> row >> col;
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    dfs(0,0);
    cout <<res;
}
