//입력간에 띄어쓰기가 있긴에 getline으로 입력받는게 중요했음

#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main(){
    map <string, int> m;
    string s;
    float cnt = 0;
    
    while(getline(cin,s)){
        cnt++;
        m[s]++;
    }
    
    for(auto i = m.begin() ; i != m.end() ; i++){
        cout << i->first << " " << fixed << setprecision(4) <<i->second/cnt*100 << '\n';
    }

}
