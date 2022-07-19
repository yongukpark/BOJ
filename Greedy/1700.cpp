//예외처리가 너무 많았음
//코드를 너무 억지로 짠 감이 없진 않지만 그래도 맞췄음
//경우의 수가 너무 많아 구현에 어려움이 있었음
#include <iostream>
#include <queue>
#include <set>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int arr[101];
    bool visited[101];
    int hole, item;
    cin >> hole >> item;
    int now[101]; //현재 사용중인 플러그
    for(int i = 0 ; i < hole ; i++)
    {
        visited[i] = false;
        now[i] = 0;
    }
    
    
    for(int i = 0 ; i < item ; i++)
    {
        cin >> arr[i];
    }
    
    set <int> s;
    
    for(int i = 0 ; i < hole ; i++)
    {
        s.insert(arr[i]);
    }
    
    int idx = 0;
    for(auto i = s.begin() ; i != s.end() ; i++)
    {
        now[idx] = *i;
        idx++;
    }
    int res = 0;
    for(int i = hole ; i < item ; i++)
    {
        bool inPlug = false;
        int a = arr[i];
        for(int j = 0 ; j < hole ; j++)
        {
            if(now[j] == 0)
            {
                inPlug = true;
                now[j] = a;
                break;
            }
            if(a == now[j])
            {
                inPlug = true;
                break;
            }
        }
        if(inPlug)
        {
            continue;
        }
        int cnt = 0;
        for(int j = i + 1; j < item ; j++)
        {
            if(cnt == hole-1)
            {
                break;
            }
            for(int k = 0 ; k < hole ; k++)
            {
                if(arr[j] == now[k] && !visited[k])
                {
                    visited[k] = true;
                    cnt++;
                    break;
                }
            }

        }
        
        for(int j = 0 ; j < hole ; j++)
        {
            if(!visited[j])
            {
                now[j] = a;
                res++;
                break;
            }
        }
        
        for(int j = 0 ; j < hole ; j++)
        {
            visited[j] = false;
        }
    }
    cout << res;
}


