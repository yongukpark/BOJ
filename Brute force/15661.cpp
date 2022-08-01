//그냥 브루트포스 문제였음
#include <iostream>
using namespace std;

int tt = 0;
int ft = 0;

int num;
int arr[21][21];
bool team[21];
int res = 100000000;

void balance(int a)
{
    if(a > num)
    {
        if(tt >= 2 && ft >= 2)
        {
            int ts = 0;
            int fs = 0;
            for(int i = 1 ; i < num ; i++)
            {
                for(int j = i + 1; j <= num ; j++)
                {
                    if(team[i] && team[j])
                    {
                        ts += arr[i][j] + arr[j][i];
                    }
                    if(!team[i] && !team[j])
                    {
                        fs += arr[i][j] + arr[j][i];
                    }
                }
            }
            if(abs(ts-fs) < res)
            {
                res = abs(ts-fs);
            } 
        }
        return;
    }
    
    team[a] = true;
    tt++;
    ft--;
    balance(a+1);
    tt--;
    ft++;
    team[a] = false;
    balance(a+1);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 1 ; j <= num ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    ft = num;
    balance(1);
    cout << res;
}
