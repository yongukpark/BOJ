//벽 3개의 위치선정이 굉장히 까다로웠음
//나머지는 기본적인 BFS문제였음


#include <iostream>
#include <queue>
using namespace std;

int arr[10][10] = { 0, };
int arr1[10][10] = { 0, };
int copy_arr[10][10] = { 0, };
int row, col;
int res = 0;
int movex[4] = { -1,1,0,0 };
int movey[4] = { 0,0,-1,1 };


void arrCopy() { 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			copy_arr[i][j] = arr[i][j];
		}
	}
}


void bfs() {

	arrCopy();

	queue <int> x;
	queue <int> y;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (copy_arr[i][j] == 2) {
				x.push(i);
				y.push(j);
			}
		}
	}

	while (!x.empty()) {
		int x1 = x.front();
		int y1 = y.front();
		x.pop();
		y.pop();
		for (int i = 0; i < 4; i++) {
			int x2 = x1 + movex[i];
			int y2 = y1 + movey[i];
			if (x2 >= 0 && x2 < row && y2 >= 0 && y2 < col) {
				if (copy_arr[x2][y2] == 0) {
					copy_arr[x2][y2] = 2;
					x.push(x2);
					y.push(y2);
				}
			}

		}
	}

	int cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (copy_arr[i][j] == 0) {
				cnt++;
			}
		}
	}

	res = max(cnt, res);
}

void wall(int num) {
	if (num == 3) {
		bfs();
		return;
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr[i][j]==0) {
				arr[i][j] = 1;
				wall(num + 1);
				arr[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr1[i][j];
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (arr1[i][j] == 0) {
				for (int k = 0; k < row; k++) {
					for (int l = 0;  l < col; l++) {
						arr[k][l] = arr1[k][l];
					}
				}
				arr[i][j] = 1;
				wall(1);
				arr[i][j] = 0;
			}
		}
	}
	cout << res;
}
