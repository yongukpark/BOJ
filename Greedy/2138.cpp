//일단 배열의 길이가 100000이 넘기때문에 브루트포스를 사용할수없고 그리디를 이용하여 풀어야함
//처음에 현재전구의 일치여부를 통해 스위치를 조작했지만 올바른 답안이 나오지 않았고 
//결국 이전전구의 일치여부를 이용해야한다는 것을 알았음


#include <iostream>
#include <queue>
using namespace std;
int arr[100003];
int res[100003];
int c[100003];  


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int n; cin >> n;
    
    string s1,s2; cin >> s1 >> s2;
    for(int i = 0 ; i < n ; i++)
    {
        c[i] = s1[i]-'0';
        res[i] = s2[i]-'0';
    }

    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = c[i];
    }
    
    int count = 0;
    int ans = 987654321;
    arr[0] = 1 - arr[0];
    arr[1] = 1 - arr[1];
    count++;
    
    for(int i = 1 ; i < n - 1; i++)
    {
        if( arr[i-1] != res[i-1] )
        {
            arr[i-1] = 1 - arr[i-1];
            arr[i] = 1 - arr[i];
            arr[i+1] = 1 - arr[i+1];
            count++;
        }
    }
    if(arr[n-2] != res[n-2])
    {
        arr[n-1] = 1 - arr[n-1];
        arr[n-2] = 1 - arr[n-2];
        count++;
    }
    if(arr[n-1] == res[n-1])
    {
        ans = min(ans,count);
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        arr[i] = c[i];
    }
    count = 0;
    for(int i = 1 ; i < n - 1 ; i++)
    {
        if(arr[i-1] != res[i-1])
        {
            arr[i-1] = 1 - arr[i-1];
            arr[i] = 1 - arr[i];
            arr[i+1] = 1 - arr[i+1];
            count++;
        }
    }
    if(arr[n-2] != res[n-2])
    {
        arr[n-1] = 1 - arr[n-1];
        arr[n-2] = 1 - arr[n-2];
        count++;
    }
    if(arr[n-1] == res[n-1])
    {
        ans = min(ans,count);
    }
    if(ans == 987654321)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}

