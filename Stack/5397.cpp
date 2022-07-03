//1406 문제랑 매우 유사함
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    stack <char> s1;
    stack <char> s2;
    int num;
    string s;

    cin >> num;
    
    for(int i = 0 ; i < num ; i++){
        cin >> s;
        for(int j = 0 ; j < s.length() ; j++){
            char a = s[j];
            if(a == '<'){
               if(s1.empty()){
                   continue;
             }
                 s2.push(s1.top());s1.pop();
            }
            else if(a == '>'){
               if(s2.empty()){
                   continue;
               }
                s1.push(s2.top()); s2.pop();
           }
            else if(a == '-'){
                if(s1.empty()){
                    continue;
                }
            s1.pop();
            }
            else{
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
        cout << '\n';
    }
}
