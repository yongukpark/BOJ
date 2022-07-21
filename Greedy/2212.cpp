//문제 자체는 어렵지 않음
//하지만 이해를 잘못해서 이해하는데에 시간을 많이 쏟았고 검색후 이해하게되었음
//처음에 각 센서에서 집중국까지의 거리를 모두 더하는 것으로 이해하고 풀려했지만 예제를 보니 저런 답이 나올수 없다고 생각함
//하지만 각 센서에서 집중국이 아닌 각 집중국이 관활?하는 범위의 합을 구하는 것이었음
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int arr[10001];
    int distanceArr[10001];
    int num; cin >> num;
    int tele; cin >> tele;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr,arr+num);
    
    
    for(int i = 0 ; i < num - 1; i++)
    {
        distanceArr[i] = arr[i+1]-arr[i];
    }
    
    sort(distanceArr, distanceArr + num-1);
    
    int sum = 0;
    
    for(int i = 0 ; i < num - tele ; i++)
    {
        sum += distanceArr[i];
    }
    
    cout << sum;
}

