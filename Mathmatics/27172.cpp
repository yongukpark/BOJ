//에라토스테네스의 채를 활용하면 풀기 쉬운 문제였음
//에라토스테네서의 시간복잡도를 계산하는 것이 아직도 이해가 안됨
//개선전 알고리즘은 O(NloglogN)인 것이 이해가 되지만 개선 후 시간복잡도에 대한 설명을 찾기 힘듬

#include <iostream>
using namespace std;

int arr[1000003];
int input[100003];
int score[1000003];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> input[i];
		arr[input[i]] = 1;
	}

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = input[i] * 2 ; j <= 1000000 ; j += input[i])
		{
			if(arr[j] == 1)
			{
				score[input[i]]++;
				score[j]--;
			}
		}
	}

	for(int i = 0 ; i < n ; i++)
	{
		cout << score[input[i]] << ' ';
	}

}
