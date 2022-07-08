//쉬움
#include <iostream>
#include <map>
using namespace std;

int main(){
    int num;
    map <string,bool,greater<string>> m;
    
    cin >> num;
    for(int i = 0 ; i < num; i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(s2=="enter"){
            m[s1] = true;
        }
        else if(s2 == "leave"){
            m[s1] = false;
        }
    }
    for(auto i = m.begin() ; i != m.end() ; i++){
        if(i->second){
            cout << i->first << '\n';
        }
    }
}
