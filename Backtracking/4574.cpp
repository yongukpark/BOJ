//진짜 정신나갈것 같음
//접근부터도 어렵다기보단 막막했던 문제였음
//처음에 블럭 두칸을 골라 각각에 이중포문을 통해 수를 지정해야함
//구현부분도 굉장히 복잡했던 문제였음
//중간에 return을 하나 넣지 않아 계속해서 오류가 났었고 나중에 찾아 고치니 잘 되었음

#include <iostream>
using namespace std;

int arr[10][10];
bool row[10][10];
bool col[10][10];
bool squ[10][10];
bool visited[10][10];
bool flg = false;

int square(int x, int y)
{
    return ((x/3)*3 + (y/3));
}

void backTracking(int c)
{
    if(flg)
    {
        return;
    }
    if(c == 81)
    {
        for(int i = 0 ; i < 9 ; i++)
        {
            for(int j = 0 ; j < 9 ; j++)
            {
                cout << arr[i][j];
            }
            cout << '\n';
        }
        flg = true;
        return;
    }
    
    int x = c/9;
    int y = c%9;
    
    if(arr[x][y])
    {
        backTracking(c+1);
        return;
    }
    
    if(y < 8 && arr[x][y+1] == 0)
    {
        for(int i = 1 ; i <= 9 ; i++)
        {
            for(int j = i + 1 ; j <= 9 ; j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j] = true;
                    visited[j][i] = true;
                    if(!row[x][i] && !col[y][i] && !squ[square(x,y)][i] && !row[x][j] && !col[y+1][j] && !squ[square(x,y+1)][j])
                    {
                        row[x][i] = col[y][i] = squ[square(x,y)][i] = true;
                        row[x][j] = col[y+1][j] = squ[square(x,y+1)][j] = true;
                        arr[x][y] = i;
                        arr[x][y+1] = j;

                        backTracking(c+2);
                        row[x][i] = col[y][i] = squ[square(x,y)][i] = false;
                        row[x][j] = col[y+1][j] = squ[square(x,y+1)][j] = false;
                        arr[x][y] = 0;
                        arr[x][y+1] = 0;

                    }
                    if(!row[x][j] && !col[y][j] && !squ[square(x,y)][j] && !row[x][i] && !col[y+1][i] && !squ[square(x,y+1)][i])
                    {
                        row[x][j] = col[y][j] = squ[square(x,y)][j] = true;
                        row[x][i] = col[y+1][i] = squ[square(x,y+1)][i] = true;
                        arr[x][y] = j;
                        arr[x][y+1] = i;


                        backTracking(c+2);
                        row[x][j] = col[y][j] = squ[square(x,y)][j] = false;
                        row[x][i] = col[y+1][i] = squ[square(x,y+1)][i] = false;
                        arr[x][y] = 0;
                        arr[x][y+1] = 0;

                    }
                    visited[i][j] = false;
                    visited[j][i] = false;
               }
            }
        }
    }
    if(x < 8 && arr[x+1][y] == 0)
    {
        for(int i = 1 ; i <= 9 ; i++)
        {
            for(int j = i + 1 ; j <= 9 ; j++)
            {
                if(!visited[i][j])
                {
                    visited[i][j] = true;
                    visited[j][i] = true;
                    if(!row[x][i] && !col[y][i] && !squ[square(x,y)][i] && !row[x+1][j] && !col[y][j] && !squ[square(x+1,y)][j])
                    {
                        row[x][i] = col[y][i] = squ[square(x,y)][i] = true;
                        row[x+1][j] = col[y][j] = squ[square(x+1,y)][j] = true;
                        arr[x][y] = i;
                        arr[x+1][y] = j;
                        backTracking(c+1);
                        row[x][i] = col[y][i] = squ[square(x,y)][i] = false;
                        row[x+1][j] = col[y][j] = squ[square(x+1,y)][j] = false;
                        arr[x][y] = 0;
                        arr[x+1][y] = 0;
                    }
                    
                    if(!row[x+1][i] && !col[y][i] && !squ[square(x+1,y)][i] && !row[x][j] && !col[y][j] && !squ[square(x,y)][j])
                    {
                        row[x+1][i] = col[y][i] = squ[square(x+1,y)][i] = true;
                        row[x][j] = col[y][j] = squ[square(x,y)][j] = true;
                        arr[x+1][y] = i;
                        arr[x][y] = j;
                        backTracking(c+1);
                        row[x+1][i] = col[y][i] = squ[square(x+1,y)][i] = false;
                        row[x][j] = col[y][j] = squ[square(x,y)][j] = false;
                        arr[x][y] = 0;
                        arr[x+1][y] = 0;
                    }
                    visited[i][j] = false;
                    visited[j][i] = false;
            
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int count = 1;
    int num;
    cin >> num;
    while(num)
    {
        flg = false;
        for(int i = 0 ; i < 10 ; i++)
        {
            for(int j = 0 ; j < 10 ; j++)
            {
                arr[i][j] = 0;
                row[i][j] = false;
                col[i][j] = false;
                squ[i][j] = false;
                visited[i][j] = false;
                
            }
        }
        for(int i = 0 ; i < num ; i++)
        {
            int a,b;
            string s1,s2;
            cin >> a >> s1 >> b >> s2;
            visited[a][b] = true;
            visited[b][a] = true;
            
            arr[s1[0]-'A'][s1[1]-'0'-1] = a;
            
            row[s1[0]-'A'][a] = true;
            col[s1[1]-'0'-1][a] = true;
            squ[square(s1[0]-'A',s1[1]-'0'-1)][a] = true;
    
            
            arr[s2[0]-'A'][s2[1]-'0'-1] = b;
            
            row[s2[0]-'A'][b] = true;
            col[s2[1]-'0'-1][b] = true;
            squ[square(s2[0]-'A',s2[1]-'0'-1)][b] = true;
        }
        
        for(int i = 1 ; i <= 9 ; i++)
        {
            string s;
            cin >> s;
            arr[s[0]-'A'][s[1]-'0'-1] = i;
            
            row[s[0]-'A'][i] = true;
            col[s[1]-'0'-1][i] = true;
            squ[square(s[0]-'A',s[1]-'0'-1)][i] = true;
        }
        cout << "Puzzle " << count << '\n';
        backTracking(0);
        count++;
        cin >> num;
    }
    return 0;
}
