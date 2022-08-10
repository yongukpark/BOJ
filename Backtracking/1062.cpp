//시간초과나 메모리초과가 날줄 알았지만 그냥 무지성으로 풀어도 풀리는 문제였음
//그러나 그 이유를 모르
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool alpabet[30];
int res = 0;
int n,k;
vector <string> arr;

void read() //읽을 수 있는 문자열인지 확인
{
    int tmp = 0;
    for(int i = 0 ; i < n ; i++)
    {   
        int flg = true;
        for(int j = 0 ; j < arr[i].length() ; j++)
        {
            if(!alpabet[arr[i][j] - 'a'])
            {
                flg = false;
                break;
            }
        }
        if(flg)
        {
            tmp++;
        }
    }
    res = max(res, tmp);
}

void backTracking(int idx, int count) //알파벳 선택
{
    if(count == k)
    {
        read();
        return;
    }
    
    for(int i = idx ; i < 26 ; i++)
    {
        if(!alpabet[i])
        {
            alpabet[i] = true;
            backTracking(i, count+1);
            alpabet[i] = false;
        }
    }
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        string s; cin >> s;
        arr.push_back(s);
    }
    alpabet['a'-'a'] = true;
    alpabet['n'-'a'] = true;
    alpabet['t'-'a'] = true;
    alpabet['i'-'a'] = true;
    alpabet['c'-'a'] = true;
    k = k - 5;
    if(k < 0)
    {
        cout << 0;
        return 0;
    }
    backTracking(0,0);
    cout << res;
}
