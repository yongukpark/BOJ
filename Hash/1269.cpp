//m[a]와 같은 형식으로 찾을때는 값이 반환됨
//m에서 find함수를 호출하면 iterator가 반환됨
//ex) m.find[a] == m.end() 와 같은 형식으로 써야됨

#include <iostream>
#include <map>

using namespace std;

int main(){
    
    map <int,bool> m;
    
    int num1,num2;
    
    cin >> num1 >> num2;
    
    for(int i = 0 ; i < num1 ; i++){
        int num;
        cin >> num;
        m[num] = true;
    }
    
    int cnt = 0;
    
    for(int i = 0 ; i < num2 ; i++){
        int  num;
        cin >> num;
        if(!m[num]){
            cnt ++;
        }
        else{
            m[num] = false;
        }
    }
    
    for(auto i = m.begin() ; i != m.end() ; i++){
        if(i->second){
            cnt++;
        }
    }
    cout << cnt;
}
