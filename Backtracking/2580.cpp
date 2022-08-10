//bool배열로 각 행,열,블록에 대해 중복 체크를 한다라는 것을 떠올리기 어려웠음
//이걸 제외하면 나머지는 다 쉬운 구현이었음
//시간 초과가 날까 걱정했지만 문제에 제시된대로 그렇지 않은 케이스만 나온 것 같음
#include <iostream>
using namespace std;

int arr[10][10];
int tmp[100][2];
int count = 0;
bool row[10][10];
bool col[10][10];
bool squ[10][10];

int square(int x, int y)
{
    return ((x/3)*3 + (y/3));
}

void backTracking(int c)
{
    if(c == count)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }
    
    int x = tmp[c][0];
    int y = tmp[c][1];
    for(int i = 1 ; i <= 9 ; i++)
    {
        if(!row[x][i] && !col[y][i] && !squ[square(x,y)][i])
        {
            row[x][i] = col[y][i] = squ[square(x,y)][i] = true;
            arr[x][y] = i;
            backTracking(c+1);
            arr[x][y] = 0;
            row[x][i] = col[y][i] = squ[square(x,y)][i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    for(int i = 0 ; i < 9 ; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0)
            {
                tmp[count][0] = i;
                tmp[count][1] = j;
                count++;
                continue;
            }
            row[i][arr[i][j]] = true;
            col[j][arr[i][j]] = true;
            squ[square(i,j)][arr[i][j]] = true;
        }
    }
    
    backTracking(0);
}
