//오래 고민하다가 결국 찾아보고 답을 구함
//역시 어려운 문제는 풀이가 생각보다 간단한 것 같음
//문제의 핵심은 누적합과 그리디 알고리즘을 사용하는 것임
//만약 내가 1~8까지 무게측정이 가능하다면 예를들어 다음 추가 7일 경우 1~8(기존) + 7+1~7+8 즉 8~15까지 측정이가능함
//따라서 1~15까지 측정가는하게 되는 것임
//만약 같은 상황에서 9의 추가 추가될경우 1~8(기존) + 9+1~9+8까지 측정가능하고 즉 10~17이 됨
//그럼 1~8 10~17까지 측정가능하나 중간에 9는 측정이 불가능해짐
//따라서 앞선 원소들의 누적합보다 다음 원소의 값이 클 경우 그 누적합 바로 다음 값이 결과값이 되게 되어있음
//꽤 머리쓰는 수학적센스가 필요한 문제였던 
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[1003];
    int num; cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];    
    }
    
    sort(arr,arr+num);
    
    int res = 0;
    for(int i = 0 ; i < num ; i ++)
    {
        if(arr[i] > res + 1)
        {
            break;
        }
        res+=arr[i];
    }
    cout << res + 1;
}