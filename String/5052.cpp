//정렬 카테고리를 공부하고 있지만 정렬보다는 다른 것들 위주로 더 쓰이는 것 같음
//이 문제 같은 경우에도 단순 문자열 문제로 보임
//이 문제의 해설을 찾아보다가 이 문제를 푸는 방법중 하나로 트라이라는 문자열을 다루는 자료구조에 대해 알았음 / 추후 다시 공부예정
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int testCase; cin >> testCase;
    for(int i = 0 ; i < testCase ; i++)
    {
        bool totalFlg = true;
        string arr[10003];
        int num; cin >> num;
        for(int j = 0 ; j < num ; j++)
        {
            cin >> arr[j];
        }
        sort(arr,arr + num);
        for(int j = 0 ; j < num - 1 ; j++)
        {
            

            if(arr[j].length() >= arr[j+1].length())
            {
                continue;
            }
            else{
                bool flg = false;
                for(int k = 0 ; k < arr[j].length() ; k++)
                {
                    if(arr[j][k] != arr[j+1][k])
                    {
                        flg = true;
                        break;
                    }
                }
                if(!flg)
                {
                    totalFlg = false;
                }
            }
            if(!totalFlg)
            {
                break;
            }
        }
        if(totalFlg)
        {
           cout << "YES" << '\n'; 
        }
        else{
            cout << "NO" << '\n';
        }
    }
}
