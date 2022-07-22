//쉽게 풀수 있는 문제였음
//Plus와 Minus로 나누어 푸는 것이 포인트인 문제인 것 같음
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int>arrP;
    vector<int>arrM;
    
    int num, hand;
    cin >> num >> hand;
    
    for(int i = 0 ; i < num ; i++)
    {
        int a;
        cin >> a;
        if(a > 0)
        {
            arrP.push_back(a);
        }
        else
        {
            arrM.push_back(a);
        }
    }
    sort(arrP.begin(),arrP.end());
    reverse(arrP.begin(),arrP.end());
    sort(arrM.begin(),arrM.end());
    
    int max = 0;
    int res = 0;
    for(int i = 0 ; i < arrP.size() ; i+=hand)
    {
        res += arrP[i]*2;
        if(arrP[i] > max)
        {
            max = arrP[i];
        }
    }
    for(int i = 0 ; i < arrM.size() ; i+=hand)
    {
        res += abs(arrM[i])*2;
        if(abs(arrM[i]) > max)
        {
            max = abs(arrM[i]);
        }
    }
    cout << res - max;
}
