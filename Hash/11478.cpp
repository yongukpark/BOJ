//쉬웠음
//굳이 map을 사용하지 않고 set을 사용하여 문제를 해결할 수도 있음

#include <iostream>
#include <map>
using namespace std;

int main(){
    string s;
    map<string,bool>m;
    
    cin >> s;
    
    for(int i = 0 ; i < s.length() ; i++){
        string pushS = "";
        for(int j = 0 ; j < s.length() - i ; j++){
            pushS += s[i+j];
            m[pushS] = true;
        }
    }
    cout << m.size();
}
