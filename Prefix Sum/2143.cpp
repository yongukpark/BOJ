//이분탐색과 누적합을 이용하는 문제

#include <iostream>
#include <algorithm>
using namespace std;

int dp_a[1003];
int dp_b[1003];
int arr_a[1000003];
int arr_b[1000003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num; cin >> num;
    int a; cin >> a;
    for(int i = 0 ; i < a ; i++)
    {
        cin >> dp_a[i];
        if(i != 0)
        {
            dp_a[i] += dp_a[i-1];
        }
    }

    int b; cin >> b;
    for(int i = 0 ; i < b ; i++)
    {
        cin >> dp_b[i];
        if(i != 0)
        {
            dp_b[i] += dp_b[i-1];
        }
    }

    int cnt_a = 0;
    for(int i = 0 ; i < a ; i++)
    {
        arr_a[cnt_a] = dp_a[i];
        cnt_a++;
        for(int j = i + 1 ; j < a ; j++)
        {
            arr_a[cnt_a] = dp_a[j]-dp_a[i];
            cnt_a++;
        }
    }
    sort(arr_a,arr_a+cnt_a);

    int cnt_b = 0;
    for(int i = 0 ; i < b ; i++)
    {
        arr_b[cnt_b] = dp_b[i];
        cnt_b++;
        for(int j = i + 1 ; j < b ; j++)
        {
            arr_b[cnt_b] = dp_b[j]-dp_b[i];
            cnt_b++;
        }
    }
    sort(arr_b, arr_b + cnt_b);

    long long res = 0;
    
    //=============

    for(int i = 0 ; i < cnt_a ; i++)
    {
        cout << arr_a[i] << ' ';
    }
    cout << '\n';

    for(int i = 0 ; i < cnt_b ; i++)
    {
        cout << arr_b[i] << ' ';
    }
    cout << '\n';
    //=============

    for(int i = 0 ; i < cnt_a ; i++)
    {
        int goal_num = num - arr_a[i];
        res += upper_bound(arr_b, arr_b + cnt_b, goal_num) - lower_bound(arr_b, arr_b + cnt_b, goal_num);
    }

    cout << res;
    return 0;
}
