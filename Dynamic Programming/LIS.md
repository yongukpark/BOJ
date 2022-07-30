## LIS(Longedst Increasing Subsequence) : 최장 증가 부분 수열 
* 원소가 n개인 배열에서 가장 긴 증가하는 수열을 최장 증가 부분 수열이라고함(연속적일 필요 없음)
* 일반적으로 DP로 간단하게 풀수 있는 문제임
## O(N^2) / 일반적인 DP
```cpp
for(int i = 0; i < n ; i++) //dp를 구하고자 하는 원소
{
    dp[i] = 1;
    for(int j = 0 ; j < i ; j++) //앞선 원소들의 값과 비교하며 증가하는 경우 앞의 원소들의 dp의 값과 자신의 dp의 값중 더 큰값을 택함 
    {
        if(arr[i] > arr[j])
        {
            dp[i] = max(dp[i],dp[j] + 1);
        }
    }
}
```

## O(NlogN) / 이진탐색을 활용한 DP
* N^2의 시간 복잡도를 개선하기 위해 이분탐색을 활용한 방법이 있음
```cpp
#include <iostream>
using namespace std;

int lis[1000]; //계산용 배열
int arr[1000]; //입력받는 배열
int binarySearch(int start, int end, int goal) //일반적인 이진탐색
{
    while(start < end)
    {
        int mid = (start+end)/2;
        if(lis[mid] < goal)
        {
            start = mid + 1; 
        }
        else
        {
            end = mid;
        }
    }
    return end;
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
        cin >> arr[i];
    }
    
    int flg = 0; //현재 lis의 최대 인덱스가 0번임
    lis[0] = arr[0]; 
    int i = 1; //현재 계산할 배열의 인덱스
    while(i < num)
    {
        if(lis[flg] < arr[i]) //더 크다면 그냥 맨뒤에 추가하면 됨
        {
            flg++;
            lis[flg] = arr[i];
        }
        else //더 크지 않다면 이진탐색을 이용해 값이 들어갈 위치를 찾아서 넣어야함
        {
            int pos = binarySearch(0,flg,arr[i]);
            lis[pos] = arr[i];
        }
        i++;
    }
    cout << flg + 1 << '\n'; //배열 인덱스를 0에서 시작했기에 1을 더 추가해주는 것이고 lis의 최대 인덱스의 최댓값이 곧 최장 부분 수열이라고 볼 수 
}
```
## LIS의 원소들 출력
* 위 코드들은 최대 부분 수열의 길이밖에 출력해내지 못함
* 따라서 stack을 활용하여 최대 부분수열의 원소들을 출력해낼 수 있음  
```cpp
#include <iostream>
#include <stack>
using namespace std;


int lis[1000];
int arr[1000];
int dp[1000]; //dp저장용
int binarySearch(int start, int end, int goal)
{
    while(start < end)
    {
        int mid = (start+end)/2;
        if(lis[mid] < goal)
        {
            start = mid + 1; 
        }
        else
        {
            end = mid;
        }
    }
    return end;
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
        cin >> arr[i];
    }
    
    int flg = 0;
    lis[0] = arr[0];
    dp[0] = 1;
    int i = 1;
    while(i < num)
    {
        if(lis[flg] < arr[i])
        {
            flg++;
            lis[flg] = arr[i];
            dp[i] = flg + 1; //각 원소들의 dp는 원소가 들어가는 lis의 인덱스임
        }
        else
        {
            int pos = binarySearch(0,flg,arr[i]);
            lis[pos] = arr[i];
            dp[i] = pos + 1; //각 원소들의 dp는 원소가 들어가는 lis의 인덱스임
        }
        i++;
    }
    
    cout << flg + 1 << '\n';

    int count = flg + 1;
    stack <int> s;
    for(int i = num -1 ; i >= 0 ; i--) //원소들의 dp를 역순으로 추적하며 최대dp값부터 dp값을 하나하나 줄이며 각 dp에 해당하는 값을 stack에 저장                                  
    {                                  //ex) 최대dp값이 5라면 역순으로 추적하여 dp가 5인 값을 찾으면 stack에 push하고 찾고자하는 값을 5->4로 변경 위와같이 dp값 1까지 찾고 break
        if(count == 0)
        {
            break;
        }
        if(dp[i] == count)
        {
            s.push(arr[i]);
            count--;
        }
    }
    
    while(!s.empty()) //원소들을 차례대로 빼내어 출력하면 순서대로 정렬됨
    {
        cout << s.top() << ' '; s.pop();
    }
}
```

