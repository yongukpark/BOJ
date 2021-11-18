#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

int n, m;
int arr[10] = { 0, };
int res[10] = { 0, };

void tracking(int a , int start) {
	if (a == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) {
		res[a] = arr[i];
		tracking(a + 1,i);		
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
		tracking(1, i);
	}
}
