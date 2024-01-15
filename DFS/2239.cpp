//boolean 함수를 사용하여 조건에 맞게 탈출하는 DFS 문제였음

#include <iostream>
#include <string>
using namespace std;

bool arr[3][9][10]; //0 : 가로 
					//1 : 세로 
					//2 : 칸

string s_arr[10];
void reset_arr();
void input();
bool fill_arr(int);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	reset_arr();
	input();
	if(fill_arr(0))
	{
		return 0;
	}
}

void reset_arr()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0  ; j < 9 ; j++)
		{
			for(int k = 1 ; k <= 9 ; k++)
			{
				arr[i][j][k] = false;
			}
		}
	}
}

void input()
{
	for(int i = 0 ; i < 9 ; i++)
	{
		string s;
		cin >> s;
		s_arr[i] = s;

		for(int j = 0 ; j < 9 ; j++)
		{
			int a = s[j] - '0';
			if(a == 0)
			{
				continue;
			}
			arr[0][i][a] = true;
			arr[1][j][a] = true;
			arr[2][i/3 * 3 + j/3][a] = true; //칸 찾기
		}
	}
}

bool fill_arr(int cnt)
{
	int x = cnt/9;
	int y = cnt%9;

	if(cnt == 81)
	{
		for(int i = 0 ; i < 9 ; i++)
		{
			for(int j = 0 ; j < 9 ; j++)
			{
				cout << s_arr[i][j];
			}
			cout << '\n';
		}
		return true;
	}

	if(s_arr[x][y] == '0')
	{
		for(int i = 1 ; i <= 9 ; i++)
		{
			if(arr[0][x][i] == false && arr[1][y][i] == false && arr[2][x/3 * 3 + y/3][i] == false)
			{
				arr[0][x][i] = true;
				arr[1][y][i] = true;
				arr[2][x/3 * 3 + y/3][i] = true;
				s_arr[x][y] = i + '0';
				if(fill_arr(cnt+1))
				{
					return true;
				}
				arr[0][x][i] = false;
				arr[1][y][i] = false;
				arr[2][x/3 * 3 + y/3][i] = false;
				s_arr[x][y] = '0';
			}
		}
		return false;
	}
	else
	{
		return fill_arr(cnt+1);
	}
}
