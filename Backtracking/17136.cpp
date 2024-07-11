//골드2문제 치고는 복잡한 알고리즘 없이 단순히 백트래킹 이용하면 풀이가 가능해서 비교적 쉬웠음

#include <iostream>
#include <algorithm>
using namespace std;

int arr[13][13];
bool visited[13][13];
int paper_size[6];
int min_paper = -1;

void visited_true(int x,int y,int c)
{
    for(int i = x ; i < x + c ; i++)
    {
        for(int j = y ; j < y + c ; j++)
        {
            visited[i][j] = true;
        }
    }
}

void visited_false(int x,int y,int c)
{
    for(int i = x ; i < x + c ; i++)
    {
        for(int j = y ; j < y + c ; j++)
        {
            visited[i][j] = false;
        }
    }
}

void backTracking(int count, int paper)
{
    while(count < 100)
    {
        if(arr[count/10][count%10] == 1 && !visited[count/10][count%10]) break;
        count++;
    }

    if(count == 100)
    {
        if(min_paper == -1)
        {
            min_paper = paper;
            return;
        }
        min_paper = min(min_paper,paper);
    }

    int x = count /10;
    int y = count % 10;
    for(int k = 5 ; k >= 1 ; k--)
    {
        bool flg = true;
        for(int i = 0 ; i < k; i++)
        {
            for(int j = 0 ; j < k ; j++)
            {
                if(x + i  > 9 || y + j > 9 || arr[x+i][y+j]==0||visited[x+i][y+j]) 
                {
                    flg = false;
                    break;
                }
            }
            if(!flg) break;
        }
        if(flg) 
        {
            if(paper_size[k] == 5) continue;

            paper_size[k]++;
            visited_true(x,y,k);
            backTracking(count+1, paper + 1);
            paper_size[k]--;
            visited_false(x,y,k);
        }
    }

    
}

int main()
{
    for(int i = 0 ; i < 10  ; i++)
    {
        for(int j = 0 ; j < 10 ; j++)
        {
            cin >> arr[i][j];
        }
    }

    backTracking(0,0);
    cout << min_paper;
}
