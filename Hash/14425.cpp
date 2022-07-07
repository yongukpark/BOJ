//시간초과를 잡아내느데이에 있어 어려움을 겪음
//map의 탐색은 O(logN)를 가진다는 것을 알았다.(정렬되어있기때문)
//이를 O(N)로 해결하려하니 안되었던 것임

#include <iostream>
#include <map>

using namespace std;


int main(){
    map <string,int> m;
    int num1,num2;
    cin >> num1 >> num2;
    
    for(int i = 0 ; i < num1 ; i++){ //10,000
        string s;
        cin >> s;
        m[s]++;
    }
    
    int cnt = 0;
    for(int i = 0 ; i < num2; i++){ //10,000
        string s;
        cin >> s;
            
        if(m[s]){
            cnt++;
        }
    }
    cout << cnt;
}
