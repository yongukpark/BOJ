//자료형이 long long이라는 사실을 10^12를 보자마자 알아차려야함
//시간복잡도를 계산해보았을때 O(N)보다 작아야한다는 것을 인지해야함
//그 결과 dp를 사용하기로 했었음 

//#include <iostream>
//#include <map>
//using namespace std;
//
//
//
//int dfs(long long a,long long p,long long q){
//    if(a==0){
//        return 1;
//    }
//    return dfs(a/p,p,q) + dfs(a/q,p,q);
//}
//
//int main(){
//    long long n,p,q;
//    cin >> n >> p >> q;
//    cout << dfs(n,p,q);
//
//}

//하지만 위와 같은 형식으로 할 경우 시간초과가 나기때문에 map에 저장하면서 진행해야함
//왜 시간초과가 나는지에 대한 정확한 이유는 모르겠음

#include <iostream>
#include <map>
using namespace std;

map<long long int, long long int>m;

long long int dfs(long long a,long long p,long long q){
    if(a==0){
        return 1;
    }
    
    if(m[a]){
        return m[a];
    }
    return m[a] = dfs(a/p,p,q) + dfs(a/q,p,q);
}

int main(){
    long long n,p,q;
    cin >> n >> p >> q;
    cout << dfs(n,p,q);

}
