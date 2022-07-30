//dp문제였지만 크게 dp를 사용하지 않고 푼것 같음
//그래도 시간복잡도는 dp만큼만 나왔음 O(N)
//마지막에 등호가 들어간다라는 문구를 못읽어서 계속 디버깅하다가 시간만 많이 날림

#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    long long arr[21];
    long long tmp[21];
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
