//쉬웠지만 이게 스택문제란걸 몰랐다면 조금 푸는데 시간이 오래걸렸을 것 같음
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack <char> s1;
    stack <char> s2;
    int num;
    string s;
    
    cin >> s;
    cin >> num;
    
    for(int i = 0 ; i < s.length() ; i++){
        s1.push(s[i]);
    }
    
    for(int i = 0 ; i < num; i ++){
        char a;
        cin >> a;
        if(a == 'L'){
            if(s1.empty()){
                continue;
            }
            s2.push(s1.top());s1.pop();
        }
        else if(a == 'D'){
            if(s2.empty()){
                continue;
            }
            s1.push(s2.top()); s2.pop();
        }
        else if(a == 'B'){
            if(s1.empty()){
                continue;
            }
            s1.pop();
        }
        else if(a == 'P'){
            cin >> a;
            s1.push(a);
        }
    }
    
    while(!s1.empty()){
        s2.push(s1.top()); s1.pop();
    }
    while(!s2.empty()){
        cout << s2.top();
        s2.pop();
    }
}
