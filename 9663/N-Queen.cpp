//대각선 중복을 판별하는 26번줄 abs(arr[j] - arr[a]) == a - j 이 식을 유도하는게 어려웠음

#include <iostream>
#include <queue>
using namespace std;

int arr[17] = { 0, };
int n = 0;
int res = 0;

void clear() {
	for (int i = 0; i < 15; i++) {
		arr[i] = -1;
	}
}

void queen(int a) {
	if (a == n) {
		res++;
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[a] = i;
		bool flg = true;
		for (int j = 0; j < a; j++) {
			if (arr[j] == arr[a] || abs(arr[j] - arr[a]) == a - j) {
				flg = false;
				break;
			}
		}
		if (flg) {
			queen(a + 1);
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	clear();
	queen(0);

	cout << res;
}
