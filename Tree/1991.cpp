//하나의 논리만 잘 파악하면 3가지 모두를 쉽게 풀수있었음
//나머지는 거의 동일하고 출력하는 위치만 조금 

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector <pair<int,int>> v(27);
int n;

void front(int a)
{
    cout << (char)(a+'A'); 
    if(v[a].first != 0)
    {
        front(v[a].first);
    }
    if(v[a].second != 0)
    {
        front(v[a].second);
    }
    return;
}

void mid(int a)
{
    if(v[a].first == 0)
    {
        cout << (char)(a+'A');
    }
    if(v[a].first != 0)
    {
        mid(v[a].first);
        cout << char(a+'A');
    }
    if(v[a].second != 0)
    {
        mid(v[a].second);
    }
    return;
}

void end(int a)
{
    if(v[a].first == 0 && v[a].second == 0)
    {
        cout << (char)(a+'A');
        return;
    }
    if(v[a].first != 0)
    {
        end(v[a].first);
    }
    if(v[a].second != 0)
    {
        end(v[a].second);
    }
    cout << char(a+'A');
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        char c1, c2, c3;
        cin >> c1 >> c2 >> c3;
        if(c2 != '.')
        {
            v[c1-'A'].first = c2-'A';
        }
        if(c3 != '.')
        {
            v[c1-'A'].second = c3 -'A';
        }
    }
    
    front(0);
    cout << '\n';
    mid(0);
    cout << '\n';
    end(0);
}
