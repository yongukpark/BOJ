//queue를 사용할때에는 visited라는 배열을 통해 방문 체크를 함으로써 메모리를 효율적으로 사용할 수 있음
//또한 범위를 넘어가는 부분을 잘 캐치해야함 (Validate Check 항시 필수)
#include <iostream>
#include <queue>
using namespace std;

bool visited[2003][2003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    
    queue <int> emti;
    queue <int> clipBoard;
    queue <int> count;
    
    emti.push(1);
    clipBoard.push(0);
    count.push(0);
    
    while(!emti.empty())
    {
        int a = emti.front(); emti.pop();
        int b = clipBoard.front(); clipBoard.pop();
        int c = count.front(); count.pop();
        
        visited[a][b] = true;
        
        if(a == num)
        {
            cout << c;
            return 0;
        }
        
        //paste
        if(b && (a + b < 2000) && !visited[a+b][b])
        {
            visited[a+b][b] = true;
            emti.push(a+b);
            clipBoard.push(b);
            count.push(c+1);
        }
        
        //copy
        if(a && !visited[a][a])
        {
            visited[a][a] = true;
            emti.push(a);
            clipBoard.push(a);
            count.push(c+1);
        }
        
        
        //delete
        if(a && !visited[a-1][b])
        {
           visited[a-1][b] = true;
           emti.push(a-1);
           clipBoard.push(b);
           count.push(c+1);
        }
        
    }
}
