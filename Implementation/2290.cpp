//걍 
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int num;
int arr[13];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> num;
    char a;
    int count = 0;
    while(cin >> a)
    {
        arr[count] = a-'0';
        count++;
    }
    
    for(int i = 0 ; i < count ; i++)
    {
        cout << ' ';
        if(arr[i]==2 || arr[i]==3 || arr[i]==5 || arr[i]==6 || arr[i]==7 || arr[i]==8 || arr[i]==9 || arr[i]==0)
        {
            for(int i = 0 ; i < num ; i++)
            {
                cout << '-';
            }
        }
        else
        {
            for(int i = 0 ; i < num ; i++)
            {
                cout << ' ';
            }
        }
        cout << ' ' << ' ';
    }
    cout << '\n';
    
    for(int i = 0 ; i < num ; i++)
    {
        for(int i = 0 ; i < count ; i++)
        {
            if(arr[i]==4 || arr[i]==5 || arr[i]==6 || arr[i]==8 || arr[i]==9 || arr[i]==0)
            {
                cout << '|';
            }
            else
            {
                cout << ' ';
            }
            
            for(int i = 0 ; i < num ; i++)
            {
                cout << ' ';
            }
            
            if(arr[i]==1 || arr[i]==2 || arr[i]==3 || arr[i]==4 || arr[i]==7 || arr[i]==8 || arr[i]==9 || arr[i]==0)
            {
                cout << '|';
            }
            else
            {
                cout << ' ';
            }
            cout << ' ';
        }
        cout << '\n';
    }   
    
    for(int i = 0 ; i < count ; i++)
    {
        cout << ' ';
        if(arr[i]==2 || arr[i]==3 || arr[i]==4 || arr[i]==5 || arr[i]==6 || arr[i]==8 || arr[i]==9)
        {
            for(int i = 0 ; i < num ; i++)
            {
                cout << '-';
            }
        }
        else
        {
            for(int i = 0 ; i < num ; i++)
            {
                cout << ' ';
            }
        }
        cout << ' ' << ' ';
    }
    cout << '\n';
    
    for(int i = 0 ; i < num ; i++)
    {
        for(int i = 0 ; i < count ; i++)
        {
            if(arr[i]==2  || arr[i]==6 || arr[i]==8 || arr[i]==0)
            {
                cout << '|';
            }
            else
            {
                cout << ' ';
            }
            
            for(int i = 0 ; i < num ; i++)
            {
                cout << ' ';
            }
            
            if(arr[i]==1 || arr[i]==3 || arr[i]==4 || arr[i]==5 ||  arr[i]==6 || arr[i]==7 || arr[i]==8 || arr[i]==9 || arr[i]==0)
            {
                cout << '|';
            }
            else
            {
                cout << ' ';
            }
            cout << ' ';
        }
        cout << '\n';
    }  
    
    for(int i = 0 ; i < count ; i++)
    {
        cout << ' ';
        if(arr[i]==2 || arr[i]==3 || arr[i]==5 || arr[i]==6 || arr[i]==8 || arr[i]==9 || arr[i]==0)
        {
            for(int i = 0 ; i < num ; i++)
            {
                cout << '-';
            }
        }
        else
        {
            for(int i = 0 ; i < num ; i++)
            {
                cout << ' ';
            }
        }
        cout << ' ' << ' ';
    }
    cout << '\n';
}

