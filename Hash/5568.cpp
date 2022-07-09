//백트래킹기법을 사용하여 해결 / 백트래킹을 모르는 해결하기 힘들
//실제 예제들을 찾아보면 백트래킹을 사용하지만 to_string을 사용하여 내 코드보다 더 간략하게 풀이함
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

vector<pair<string,bool>> v;

set <string> s;

int k;
int num;

void bt(string s1,int count)
{
    if(count == k){
        s.insert(s1);
        return;
    }
    string copyS1 = s1;
    for(int i = 0 ; i < num;i++){
        if(v[i].second == false){
            v[i].second = true;
            s1+=v[i].first;
            count++;
            bt(s1,count);
            s1 = copyS1;
            count--;
            v[i].second = false;
        }
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    

    cin >> num;
    cin >> k;
    
    for(int i = 0 ; i < num ; i++){
        string s1;
        cin >> s1;
        v.push_back({s1,false});
    }
    string s1 = "";
    bt(s1,0);
    cout << s.size();
}

