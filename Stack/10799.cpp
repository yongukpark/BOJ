//원리만 이해하면 쉽게 풀렸음
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    stack<char>s1;
    
    bool flg = true;
    int sum = 0;
    
    for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '('){
            s1.push('(');
            flg = true;
        }
        else if(s[i] == ')'){
            if(flg){
                s1.pop();
                sum+= s1.size();
                flg = false;
            }
            else{
                s1.pop(); 
                sum++;
            }
        }
    }
    cout << sum;
}
