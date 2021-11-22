//long long 자료형을 안바꿔줘서 헤맸음
//나머지는 기본적인 우선순위큐 문제
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	priority_queue <int, vector<int>, greater<int>> pq;

	int card, count;
	cin >> card >> count;

	for (int i = 0; i < card; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}

	for (int i = 0; i < count; i++) {
		int first = pq.top(); 
		pq.pop();
		int second = pq.top(); 
		pq.pop();
		pq.push(first + second);
		pq.push(first + second);
	}

	int res = 0;

	for (int i = 0; i < card; i++) {
		int ps = pq.top();
		pq.pop();
		res += ps;
	}

	cout << res;
}
