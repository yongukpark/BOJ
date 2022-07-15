#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct BaseBall{
	int a;
	int strike;
	int ball;
};

vector <BaseBall> v;
int num;

bool compare(int n) {
	int tmp[3];
	for (int i = 0; i < 3; i++) {
		tmp[2-i] = n % 10;
		n = n / 10;
	}
	for (int i = 0; i < num; i++) {
		int com_tmp[3];
		int a = v[i].a;
		int strike = 0;
		int ball = 0;
		for (int j = 0; j < 3; j++) {
			com_tmp[2-j] = a % 10;
			a = a / 10;
		}
		if (tmp[0] == com_tmp[0]) {
			strike++;
		}
		if (tmp[0] == com_tmp[1]) {
			ball ++;
		}
		if (tmp[0] == com_tmp[2]) {
			ball++;
		}
		if (tmp[1] == com_tmp[0]) {
			ball++;
		}
		if (tmp[1] == com_tmp[1]) {
			strike++;
		}
		if (tmp[1] == com_tmp[2]) {
			ball++;
		}
		if (tmp[2] == com_tmp[0]) {
			ball++;
		}
		if (tmp[2] == com_tmp[1]) {
			ball++;
		}
		if (tmp[2] == com_tmp[2]) {
			strike++;
		}
		if (strike != v[i].strike || ball != v[i].ball) {
			return false;
		}
	}
	return true;
}

int Game() {
	int count = 0;
	for (int i = 123; i <= 999; i++) {
		int tmp[3] = { 0, };
		int ii = i;
		for (int j = 0; j < 3; j++) {
			tmp[2-j] = ii % 10;
			ii = ii / 10;
		}
		if (tmp[0] == tmp[1] || tmp[1] == tmp[2] || tmp[0] == tmp[2] || tmp[1] == 0 || tmp[2] == 0) {
			continue;
		}
		if (compare(i)) {
			count++;
		}
	}
	return count;
}

void init() {

	cin >> num;
	for (int i = 0; i < num; i++) {
		int a, s, b;
		cin >> a >> s >> b;
		v.push_back({ a,s,b });
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	cout << Game();
	return 0;

}
