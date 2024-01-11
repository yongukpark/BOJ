//예외처리가 너무 많았다 생각하고 다른 사람들 예제코드를 보니
//내가 너무 어렵게 풀었다고 깨달음
//난 투포인터를 중앙에서 시작해서 바깥쪽으로 갔지만
//밖에서 안으로 들어오면 쉬운 문제 였음

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {




	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int a; cin >> a;
        v.push_back(a);
    }

    int start = 0;

    while(start < n)
    {
        if(v[start] >= 0) //음수에서 0으로 넘어가는 부분이 start
        {
            if(start == 0)
            {
                cout << v[0] << ' ' << v[1];
                return 0; 
            }
            break;
        }
        start++;
    }

    if(start == n)
    {
        cout << v[n-2] << ' ' << v[n-1];
        return 0;
    }
   
    int tmp = 2000000000;
    int tmp_left = v[0];
    int tmp_right = v[n-1];    

    if(start + 1 < n) //양 + 양
    {
        int sum = v[start+1] + v[start];
        if(abs(sum) < tmp)
        {
            tmp_left = v[start];
            tmp_right = v[start+1];
            tmp = abs(sum);
        }        
    }

    if(start - 2 >= 0) //음 + 음
    {
        int sum = v[start-2] + v[start - 1];
        if(abs(sum) < tmp)
        {
            tmp_left = v[start-2];
            tmp_right = v[start-1];
            tmp = abs(sum);
        }        
    }

    int left = start-1;
    int right = start;

    while(1)
    {
        int sum = v[left] + v[right];
        if(abs(sum) < tmp)
        {
            tmp_left = v[left];
            tmp_right = v[right];
            tmp = abs(sum);
        }

        if(sum < 0)
        {
            right++;
            if(right >= n)
            {
                break;
            }
        }
        else
        {
            left--;
            if(left < 0)
            {
                break;
            }
        }
    }

    cout << tmp_left << ' ' << tmp_right;
    return 0;
}
