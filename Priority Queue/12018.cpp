#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	int res_arr[101] = { 0, };
	priority_queue <int,vector<int>,less<int>> pq;

	int num, point;
	cin >> num >> point;
	for (int i = 0; i < num; i++) {

		int a, b;
		cin >> a >> b;
		

		for (int i = 0; i < a; i++) {
			int c;
			cin >> c;
			pq.push(c);
		}

		if (b > a) {
			res_arr[i] = 1;
		}
		else {
			for (int i = 0; i < b - 1; i++) {
				pq.pop();
			}
			res_arr[i] = pq.top();
		}
		while (!pq.empty()) {
			pq.pop();
		}
	}

	sort(res_arr, res_arr + num);
	int res_count = 0;
	for (int i = 0; i < num; i++) {
		if (point - res_arr[i] < 0) {
			break;
		}
		else {
			point -= res_arr[i];
			res_count++;
		}
	}
	cout << res_count;
}
