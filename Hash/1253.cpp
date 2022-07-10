//2초이므로 2000을 이용해서 n^3가 안되기 때문에 투포인터를 적용 
//처음에는 해시라는 카테고리만 보고 map으로 풀려고 고생했음
//투포인터를 이용하려하였지만 iterator를 조작하는게 어려웠고 예외처리가 너무 많았음
//하지만 그냥 단순히 배열 + 정렬을 이용하고 투포인터를 이용하면 쉽다는 것을 알았고 코드도 간략해지고 쉽게 풀림

#include <iostream>
#include <algorithm>
#include <array>
using namespace std;


int main()
{
    int arr[2002];
    int num;
    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+num);
    int count =0;
    for(int i = 0 ; i < num ; i++){
        int targetVal = arr[i];
        int frontPointer = 0;
        int endPointer = num-1;
        int sum;
        while(frontPointer < endPointer){
            sum = arr[frontPointer] + arr[endPointer]; 
            if(sum == targetVal){
                if(frontPointer!=i && endPointer!=i)
                {
                count++;
                break;
                    
                }
                else if(endPointer==i){
                    endPointer--;
                }
                else if(frontPointer==i){
                    frontPointer++;   
                }
            }
            else if(sum < targetVal){
                frontPointer++;
            }
            else{
                endPointer--;
            }
        }
    }
    cout << count;
}
