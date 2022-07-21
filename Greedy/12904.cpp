#include <iostream>
//그리디 알고리즘을 활용한 문제라고는 크게 느껴지지 않고 문자열 문제같았음
//string 라이브러리에 pop_back, push_back이라는 메소드가 있음을 알았음 마치 stack처럼 사용이 가능함
//이것을 몰랐기에 size조절을 하기 힘들어 reverse를 사용할 수 없었고 front, end variable을 통해 기점 종점을 표기하며 뒤집히는 것을 
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s1;
    string s2;
    cin >> s1 >> s2;
    
    int front = 0 ;
    int end = s2.length() - 1;
    
    for(int i = 0 ; i < s2.length() - s1.length() ; i++)
    {
        if(s2[end] == 'A')
        {
            if(front < end)
            {
                end--;
            }
            else
            {
                end++;
            }
            continue;
        }
        else
        {
            if(front < end)
            {
                end--;
            }
            else
            {
                end++;
            }
            int temp = front;
            front = end;
            end = temp;
            continue;
        }
    }
    for(int i = 0 ; i < s1.length() ; i++)
    {
        if(front < end)
        {
            if(s1[i] != s2[front + i])
            {
                cout << 0;
                return 0;
            }
        }
        else
        {
            if(s1[i] != s2[front - i])
            {
                cout << 0;
                return 0;
            }            
        }
        
    }
    cout << 1;
}

