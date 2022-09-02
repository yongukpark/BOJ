//변수명부처 코드까지 너무 조잡하게 짰음
//그래도 맞는 코드만 만들었고 처음만든코드는 메모리 초과로 인해 못쓰게 된점이 아쉬웠음
//이진트리를 입력받을때 하나만 입력받는 것이 루트노드라고 예측할수있다라는 것을 알았음

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int,int>> v(10003);
int arr[10003];
int index = 1;
int maxCount;
void dfs(int a, int count)
{
    if(v[a].first != -1)
    {
        dfs(v[a].first,count+1);
    }
    
    arr[index] = count;
    index++;
    maxCount = max(maxCount,count);
    if(v[a].second != -1)
    {
        dfs(v[a].second ,count+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        arr[a]++;
        if(b==-1)
        {
            arr[a]++;
        }
        else
        {
           arr[b]++; 
        }
        if(c==-1)
        {
            arr[a]++;
        }
        else
        {
            arr[c]++;
        }
        v[a].first = b;
        v[a].second = c;
    }

    int rootNode;
    for(int i = 1 ; i <= n ; i++)
    {
        if(arr[i] == 1)
        {
            rootNode = i;
            break;
        }
    }
    
    dfs(rootNode,1);

    int ans = 0;
    int index;
    
    for(int i = 1 ; i <= maxCount ; i++)
    {
        int start = 0 , end = 0;
        for(int j = 1 ; j <= n ; j++)
        {
            if(arr[j] == i)
            {
                start = j;
                break;
            }
        }
        for(int j = n ; j >= 1 ; j--)
        {
            if(arr[j] == i)
            {
                end = j;
                break;
            }
        }
        if(end-start+1 > ans)
        {
            ans = end-start+1;
            index = i;
        }
    }
    cout << index << ' ' << ans;
    
}
