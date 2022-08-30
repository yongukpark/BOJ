#include <iostream>
#include <queue>
using namespace std;

bool visited[203][203];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int movex[6] = {-2,-2,0,0,+2,+2};
    int movey[6] = {-1,1,-2,2,-1,1};
    
    int n;
    cin >> n;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    queue <pair<int,int>> q;
    queue <int> count;
    q.push({x1,y1});
    count.push(0);
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int c = count.front();
        q.pop(); count.pop();
        
        if(x2 == x && y2 == y)
        {
            cout << c;
            return 0;
        }
        
        for(int i = 0 ; i < 6; i ++)
        {
            int xx = x + movex[i];
            int yy = y + movey[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= n)
            {
                continue;
            }
            
            if(!visited[xx][yy])
            {
                visited[xx][yy] = true;
                q.push({xx,yy});
                count.push(c+1);
            }
        }
    }
    cout << -1;
    return 0;
}
