//map<string,int>로 푸는 방법이 일반적으로 보였고 실제 풀이도 그러한 것이 많지만 구현이 어려워 포기했었음
//원리는 이러함 / map에 차량과 순번을 쓴 후 나온 차의 들어간 순번만 array에 저장하고 배열의 앞 원소가 뒷 원소보다 큰 경우만 찾
//내가한 원리는 실제 차가 움직이는 것처럼 버블 정렬을 이용하여 풀었음
#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    
    string arr[1003];
    
    for(int i = 0 ; i < num ; i++)
    {
        cin >> arr[i];    
    }
    
    int count = 0;
    for(int i = 0 ; i < num; i++){
        string s;
        cin >> s;
        
        int point;
        for(int j = i ; j < num ; j++)
        {
            if(arr[j]==s)
            {
                point = j;
                break;
            }
        }
        
        if(point != i)
        {
            count++;
            while(point != i)
            {
                string tmp = arr[point];
                arr[point] = arr[point-1];
                arr[point-1] = tmp;
                point--;
            }
            
        }
    }
    cout <<count;
}

