// stack으로 구현하려했으나 계속 시간초과로 stack의 원리만 이용한 배열로 구현함
// 풀다가 너무 어려워서 인터넷 참고

#include <iostream>
#include <string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s,bomb;
    cin >> s >> bomb;
    
    string answer;
    int sLen = s.length();
    int bIdx = bomb.length()-1;
    for(int i = 0 ; i < s.length() ; i++){
        
        answer+=s[i];    
        if(answer[answer.length()-1] == bomb[bIdx]){
            if(answer.length() >= bomb.length()){
                int cnt = 1;
                for(int j = bIdx - 1; j >=0 ; j--){
                    if(answer[answer.length()- (bIdx-j)-1] == bomb[j]){
                        cnt++;
                    }
                }
                
                if(bomb.length()==cnt){
                    for(int j = 0 ; j < bomb.length() ; j++){
                        answer.pop_back();
                    }
                }
            }
            
        }        
    }
    if(answer.length()>0){
        cout<<answer<<endl;
    }
    else{
        cout<<"FRULA"<<endl;
    }

    
}
