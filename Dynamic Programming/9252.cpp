//LCS 예전에 몇번 풀어봤지만 다시 봐도 어려운 것 같음
//개념은 쉬우나 역추적하는 과정에서 항상 실수함
//DP문제를 조금 보충해야겠음

#include <iostream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int dp[1003][1003];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s1;
	string s2;
	
	cin >> s1 >> s2;

	for(int i = 1 ; i <= s1.length() ; i++)
	{
		for(int j = 1 ; j <= s2.length() ; j++)
		{
 			if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	
	cout << dp[s1.length()][s2.length()] << '\n';

	int x = s1.length();
	int y = s2.length();

	stack <char> s;

	while(x >=1 && y >= 1)
	{
		if(s1[x-1] == s2[y-1])
		{
			s.push(s1[x-1]);
			x--;
			y--;
		}
		else
		{
			if(dp[x-1][y] == dp[x][y])
			{
				x--;
			}
			else 
			{
				y--;
			}
		}
	}

	while(!s.empty())
	{
		cout << s.top();s.pop();
	}
	return 0;
}
