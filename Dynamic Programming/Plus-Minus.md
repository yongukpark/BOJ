## Plus Minus 
* 이름은 내가 그냥 임의로 붙였음
* 규칙은 각각의 루프동안 +- 하였을 때 그 값이 항상 일정범위 내에 있어야함 (ex. <a href = "https://www.acmicpc.net/problem/5557">5557</a>, <a href = "https://www.acmicpc.net/problem/1495">1495</a>)

## No DP
* 아래와 같은 방법은 dp를 이용하지 않은 방법임
* 배열 두개를 생성 / 현재 값을 구할 배열(1), 이전 값들의 정보가 저장된 배열(2)
* 2 배열에서 각각의 번호의 정보를 가져와 각 값들을 +-한 값을 1 배열에 저장
* 모든 루프가 끝나고 1 배열의 정보를 2배열로 다시 넘김
* 이때 정해진 범위를 벗어나는 값은 버림
```cpp
// 5557
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int arr[21];
    int tmp[21];
    for(int i = 0 ; i <= 20 ; i++)
    {
        tmp[i] = 0;
    }
    for(int i = 0 ; i <= 20 ; i++)
    {
        arr[i] = 0;
    } 
    
    int num; cin >> num;
    int in;
    cin >> in;
    arr[in] = 1;
    for(int i = 1 ; i < num - 1; i++)
    {
        int a;
        cin >> a;
        for(int j = 0 ; j <= 20 ; j++)
        {
            if(arr[j]==0)
            {
                continue;
            }
            if(j-a >= 0)
            {
                tmp[j-a] += arr[j];
            }
            if(j+a <= 20)
            {
                tmp[j+a] += arr[j];
            }
        }

        for(int i = 0 ; i <= 20 ; i++)
        {
            arr[i] = 0;
        } 
        for(int i = 0 ; i <= 20 ; i++)
        {
            arr[i] = tmp[i];
        }
        for(int i = 0 ; i <= 20 ; i++)
        {
            tmp[i] = 0;
        }
    }
    int res;
    cin >> res;
    cout << arr[res];
}
```
## DP
* DP를 사용하는 방법
* 이차원 배열의 dp를 생성함
* 각각 현재 원소의 순서와 그 순서에 따른 값이 있음 / ex) dp[2][3] : 2번째 원소가 3의 값을 가짐
* i 루프일때 dp[i-1][X]에서 값을 가져와 +-한 후 dp[i][X+a] dp[i][X-a]에 저장
* 이때 값이 범위를 벗어나는지 체크하고 벗어나면 버려야함

```cpp
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int arr[53];
    int dp[53][1003];
    int num,start,maxi;
    cin >> num >> start >> maxi;
    for(int i = 1 ; i <= num ; i++) //input
    {
        cin >> arr[i];
    }
    
    for(int i = 1 ; i <= num ; i++) //initialization dp
    {
        for(int j = 0 ; j <= maxi ; j++)
        {
            dp[i][j] = 0;
        }
    }
    
    dp[0][start] = 1;
    
    for(int i = 1 ; i <= num ; i++)
    {
        for(int j = 0 ; j <= maxi ; j++)
        {
            if(dp[i-1][j] == 1)
            {
                if(j+arr[i] <= maxi)
                {
                    dp[i][j+arr[i]] = 1;
                }
                if(j-arr[i] >= 0)
                {
                    dp[i][j-arr[i]] = 1;
                }
            }
        }
    }
    
    for(int i = maxi ; i >= 0 ; i--)
    {
        if(dp[num][i] == 1)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;

}
```
