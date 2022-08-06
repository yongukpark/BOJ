//코드를 막짠 감이 없지 않아있지만 그래도 통과받은 코드임
//구현이 귀찮을뿐 논리적으로 막힌 부분은 없었음

#include <iostream>
#include <cmath>
using namespace std;

int num;
char arr[10];
int tmp[11];
long long res = 0;
long long resm = 9999999999;
bool visited[11];

void bf(int a)
{
    if(a == num + 1){
        long long b = 0;
        for(int i = 0 ; i < a ; i++)
        {
            b += pow(10,a - 1 - i)*tmp[i];
        }
        res = max(res,b);
        resm = min(resm,b);
        return;
    }
    
    for(int i = 0 ; i <= 9 ; i++)
    {
        if(arr[a-1] == '<')
        {
            if(!visited[i] && tmp[a-1] < i)
            {
                tmp[a] = i;
                visited[i] = true;
                bf(a+1);
                visited[i] = false;
            }
        }
        else
        {
            if(!visited[i] && tmp[a-1] > i)
            {
                tmp[a] = i;
                visited[i] = true;
                bf(a+1);
                visited[i] = false;
            }
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
        cin >> arr[i];
    }
    
    for(int i = 0 ; i <= 9 ; i++)
    {
        visited[i] = true;
        tmp[0] = i;
        bf(1);
        visited[i] = false;
    }
    if(res < pow(10,num))
    {
        cout << 0;
    }
    cout << res <<'\n';
    if(resm < pow(10,num))
    {
        cout << 0;
    }   
    cout << resm;
    
}
