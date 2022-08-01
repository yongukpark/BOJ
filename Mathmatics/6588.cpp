#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool arr[1000003];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 2 ; i <= 1000000 ; i++)
    {
        arr[i] = false;
    }
    
    for(int i = 2 ; i*i <= 1000000 ; i++)
    {
        if(!arr[i])
        {
            for(int j = i * 2 ; j <= 1000000 ; j += i)
            {
                arr[j] = true;
            }
        }
    }
    

    while(1)
    {
        int input;
        cin >> input;
        if(input == 0)
        {
            return 0;
        }
        for(int i = 3 ; i < input ; i += 2)
        {
            if(arr[i] == false && arr[input - i] == false)
            {
                cout << input << " = " << i << " + " << input-i << '\n';
                break;
            }
        }
        
    }
    
}
