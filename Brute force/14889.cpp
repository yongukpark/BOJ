//이전에 백트래킹을 잘 구현하지 못할때 풀다가 포기하였지만 다시 풀때 풀어서 굉장히 만족함
//기본적인 백트래킹과 배열들을 적절히 활용하여 풀었음
//resArray1을 굳이 안쓰고 그냥 이중배열로 똑같은 방식으로 풀어도 가능함
#include <iostream>
#include <vector>
using namespace std;

int arr [21][21];
bool check[21];
vector <int> resArray1;
vector <int> resArray2;
int res1 = 0;
int res2 = 0;
int num; 
int print = 100000000;

void dfs(int a, int count)
{
    if(count == num/2)
    {
        res1 = 0;
        res2 = 0;
        resArray1.clear();
        resArray2.clear();
        for(int i = 0 ; i < num ; i++)
        {
            if(check[i]==true)
            {
                resArray1.push_back(i);
            }
            else{
                resArray2.push_back(i);
            }
        }
            
        for(int j = 0 ;  j < num / 2 ; j++)
        {
            for(int k = 0 ; k < num/2 ; k++)
            {
                res1+=arr[resArray1[j]][resArray1[k]];
                res2+=arr[resArray2[j]][resArray2[k]];
            }
        }
            
        if(abs(res1-res2) < print)
        {
            print = abs(res1-res2);
        }

    }
    
    for(int i = a ; i < num ; i++)
    {
        if(check[i]!=false)
        {
            check[i]=false;
            dfs(i+1,count+1);
            check[i]=true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

cin >> num;
    for(int i = 0 ; i < num ; i++)
    {
        for(int j = 0 ; j < num ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0 ; i < num ; i++)
    {
        check[i] = true;
    }
    dfs(0,0);
    cout << print;
}
