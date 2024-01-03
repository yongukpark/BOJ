//브루트포스문제였지만 비둘기집원리를 추가하여 시간초과 방지해야함

#include <iostream>
using namespace std;

void mbti()
{   
    

    string s[1000001];
    int n; cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> s[i];
    }

    if(n >= 33)
    {
        cout << 0 << '\n';
        return;
    }

    //select

    int print = 10000000;

    for(int i = 0 ; i < n-2; i++)
    {
        string first = s[i];
        for(int j = i + 1 ; j < n-1; j++)
        {
            string second = s[j];
                for(int k = j + 1 ; k < n ; k++)
            {
                int res = 0;
                string third = s[k];
                for(int roop = 0 ; roop < 4 ; roop++)
                {
                    if(first[roop]!=second[roop])res++;  
                    if(second[roop]!=third[roop])res++;  
                    if(third[roop]!=first[roop])res++;                 
                }
                print = min(print,res);
            }
        }
    }
    cout << print << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case; cin >> test_case;
    
    for(int i = 0 ; i < test_case ; i++)
    {
        mbti();
    }

    return 0;
}
