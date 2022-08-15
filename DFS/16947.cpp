//정말 귀찮고 복잡한 구현이었음
//flg체크가 까다로운 문제였던 것 같음
//ex)순환선을 찾으면 종료해야함 -> 함수리턴형을 bool로 하여 해결하였음

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>v[3003];
bool loop[3003];
bool visited[3003];
int standard;
int res = 300000;
int route = 0;

bool find(int a)
{
    for(int i = 0 ; i < v[a].size() ; i++)
   {
        if(v[a][i] == standard && route > 1)
        {
            loop[a] = true;
            return true;
        }
        if(visited[v[a][i]])
        {
            continue;
        }
        
        visited[v[a][i]] = true;
        route++;
        if(find(v[a][i]))
        {
            route--;
            loop[a] = true;
            return true;
        }
        route--;
        visited[v[a][i]] = false;
    }
    return false;
}

void distance(int a, int count)
{
    if(loop[a])
    {
        res = min(count,res);
        return;
    }
    
    for(int i = 0 ; i < v[a].size() ; i++)
    {
        if(visited[v[a][i]])
        {
            continue;
        }
        visited[v[a][i]] = true;
        distance(v[a][i],count+1);
        visited[v[a][i]] = false;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= num ; i++)
    {
        standard = i;
        visited[i] = true;
        if(find(i))
        {
            break;   
        }
        visited[i] = false;
    }
    
    for(int i = 1 ; i <= num ; i++)
    {
        visited[i] = false;
    }
    
    for(int i = 1 ; i <= num ; i++)
    {
        visited[i] = true;
        distance(i,0);
        visited[i] = false;
        cout << res << ' ';
        res = 300000;
    }
}

