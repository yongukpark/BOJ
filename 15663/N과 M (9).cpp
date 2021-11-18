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

	int check = 0;

	for (int i = 0; i < n; i++) {
		if (visited[i] == 0 && (check != arr[i])) {
			res[a] = arr[i];
			check = res[a];
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
	
	tracking(0);
}
