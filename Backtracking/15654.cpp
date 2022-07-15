//무난한 백트래킹 문제
#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

int n, m;
int arr[10] = { 0, };
int res[10] = { 0, };
int visited[10] = { 0, };

void tracking(int a) {
	if (a == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			res[a] = arr[i];
			visited[i] = 1;
			tracking(a + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		res[0] = arr[i];
		visited[i] = 1;
		tracking(1);
		visited[i] = 0;
	}
}
