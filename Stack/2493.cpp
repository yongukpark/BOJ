//Big-o 150,000,000 임을 인지하고 시간복잡도에 신경써야함
//cin.tie(0)를 안써서 시간초과가 한번 남
//문제 자체를 해결하는 것은 쉬우나 시간복잡도를 맞추는게 까다로웠음
#include <iostream>
#include <string>
#include <stack>
#include <utility>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    stack <pair<int,int>> s1;
    int num;
    
    cin >> num;
    
    int a;
    for(int i = 1 ; i <= num ; i++){
        cin>>a;
        while(1){
            if(s1.empty()){
                s1.push({a,i});
                cout << 0 << ' ';
                break;
            }
            if(s1.top().first > a){
                cout << s1.top().second << ' ';
                s1.push({a,i});
                break;
            }
            else{
                s1.pop();
            }
        }
    }
}
