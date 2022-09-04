//각 행또는 열은 0번또는 1번만 뒤집을 것임
//결국 이를 이용하여 계산을 하면되는데 testcase가 10이므로 완전한 브루트포스로 하기에는 2^40의 시간이 걸려 시간초과가 나게됨
//따라서 행에 대한 브루트포스를 먼저하여 2^20개의 연산을하고 그 이후에 열에대한 계산은 그리디(T가 더 많으면 뒤집기)로 하면됨
//총 시간복잡도는 N^2*2^N 이 나왔고 수치로 환산하면 약 4억 이르모 6초시간제한에 들수 있음

#include <iostream>
using namespace std;

bool arr[21][21];
bool saveArr[21][21];
int n; 
int res = 987654321;

void check()
{
    
    for(int i = 0 ; i < n ; i++)
    {
        int zero = 0;
        int one = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[j][i]) one++;
            else zero++;
        }
        if(zero > one)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(arr[j][i]) arr[j][i] = false;
                else arr[j][i] = true;
            }
        }
    }
    int cnt = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(!arr[i][j])
            {
                cnt++;
            }
        }
    }
    res = min(res,cnt);
}

void backTracking(bool arr[21][21] , int cnt)
{
    if(cnt == n)
    {
        check();
        return;
    }
    backTracking(arr,cnt+1);
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[cnt][i]) arr[cnt][i] = false;
        else arr[cnt][i] = true;
    }
    backTracking(arr,cnt+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            char c;
            cin >> c;
            if(c == 'H')
            {
                arr[i][j] = true;
            }
            else
            {
                arr[i][j] = false;            
                
            }
        }
    }
    backTracking(arr,0);
    cout << res;
}
