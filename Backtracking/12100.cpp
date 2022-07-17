//일단 이문제 통과했을때 쾌감이 엄청짜릿했음
//길이도 길이지만 구현문제라 굉장히 귀찮고 방식이 생각이 안나 어려웠음
//다만 다른 문제에 비해 구현 난이도는 낮은 것 같았고 백트래킹도 그렇게 어렵진 
#include <iostream>
#include <vector> 
#include <cmath>
#include <queue>
using namespace std;

int arr[21][21];
int result = 0;
int num;

void findMax() //최댓값 구하기
{
    int maxi = 0;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            maxi = max(maxi,arr[i][j]);
        }
    }
    result = max(result, maxi);
    
}

void backTracking(int a)
{
    if(a == 5)
    {
        findMax();
        return;
    }
    
    int copyArr[21][21];

    //배열 복사해서 저장    
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            copyArr[i][j] = arr[i][j];
        }
    }
    
    //왼쪽 이동
    for(int i = 0 ; i < num ; i++)
    {
        queue<int>q;
        for(int j = 0 ; j < num ; j++)
        {
            if(arr[i][j])
            {
                q.push(arr[i][j]); 
            }
        }
        
        int idx = 0;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(q.empty()){
                arr[i][idx] = x;
                idx++;
                break;
            }
            if(x == q.front())
            {
                arr[i][idx] = x*2;
                q.pop();
            }
            else
            {
                arr[i][idx] = x;
            }
            idx++;
        }
        if(idx < num)
        {
            for(int j = idx ; j < num ; j++)
            {
                arr[i][j] = 0;
            }
        }

    }
    backTracking(a + 1);
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            arr[i][j] = copyArr[i][j];
        }
    }
    
    //오른쪽 이동
    for(int i = 0 ; i < num ; i++)
    {
        queue<int>q;
        for(int j = num-1 ; j >= 0 ; j--)
        {
            if(arr[i][j])
            {
                q.push(arr[i][j]); 
            }
        }
        
        int idx = num-1;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(q.empty()){
                arr[i][idx] = x;
                idx--;
                break;
            }
            if(x == q.front())
            {
                arr[i][idx] = x*2;
                q.pop();
            }
            else
            {
                arr[i][idx] = x;
            }
            idx--;
        }
        if(idx >= 0)
        {
            for(int j = idx ; j >= 0 ; j--)
            {
                arr[i][j] = 0;
            }
        }

    }
    backTracking(a + 1);
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            arr[i][j] = copyArr[i][j];
        }
    }
    
    //위쪽으로 이동
    for(int i = 0 ; i < num ; i++)
    {
        queue<int>q;
        for(int j = 0 ; j < num ; j++)
        {
            if(arr[j][i])
            {
                q.push(arr[j][i]); 
            }
        }
        
        int idx = 0;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(q.empty()){
                arr[idx][i] = x;
                idx++;
                break;
            }
            if(x == q.front())
            {
                arr[idx][i] = x*2;
                q.pop();
            }
            else
            {
                arr[idx][i] = x;
            }
            idx++;
        }
        if(idx < num)
        {
            for(int j = idx ; j < num ; j++)
            {
                arr[j][i] = 0;
            }
        }

    }
    backTracking(a + 1);
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            arr[i][j] = copyArr[i][j];
        }
    }
    
    //아래쪽 이동
    for(int i = 0 ; i < num ; i++)
    {
        queue<int>q;
        for(int j = num-1 ; j >= 0 ; j--)
        {
            if(arr[j][i])
            {
                q.push(arr[j][i]); 
            }
        }
        
        int idx = num-1;
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            if(q.empty()){
                arr[idx][i] = x;
                idx--;
                break;
            }
            if(x == q.front())
            {
                arr[idx][i] = x*2;
                q.pop();
            }
            else
            {
                arr[idx][i] = x;
            }
            idx--;
        }
        if(idx >= 0)
        {
            for(int j = idx ; j >= 0 ; j--)
            {
                arr[j][i] = 0;
            }
        }

    }
    backTracking(a + 1);
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            arr[i][j] = copyArr[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    backTracking(0);
    cout << result;
    
}
