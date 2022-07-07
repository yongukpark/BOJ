//쉽다

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

#include <string>
using namespace std;

bool compare(pair<string,int> a , pair<string,int> b){
    return a.first < b.first;
}

int main(){
    int num;
    cin >> num;
     
    vector <pair<string,int>> v;
    
    for(int i = 0 ; i < num; i++){
        string s;
        bool flg = false;
        cin >> s;
        for(int i = 0 ; i < v.size() ; i++){
            if(v[i].first == s){
                v[i].second++;
                flg = true;
            }
        }    
        
        if(!flg){
            v.push_back({s,1});
        }
    }
    
    sort(v.begin(), v.end() , compare);
    
    int maxNum = 0;
    string maxWord;
    
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i].second > maxNum){
            maxNum = v[i].second;
            maxWord = v[i].first;
        }

    }
    cout << maxWord;
}
