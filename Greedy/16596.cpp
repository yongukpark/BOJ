// 로직을 생각하는데 오래걸렸지만 구현하는데는 5분도 채 걸리지 않았음
// Strick Week Ordering이라는 것에 대해 알게 되었다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b)
{
	string aa = to_string(a);
	string bb = to_string(b);
	int alen = aa.length();
	int blen = bb.length();
	int idx = 0;
	while(true)
	{
		if(idx >= alen && idx >= blen)
		{
			if(alen >= blen && alen % blen == 0) return false;
			else if(alen < blen && blen % alen == 0) return false; 
		}
		int acomp = aa[idx % alen];
		int bcomp = bb[idx % blen];
		if(acomp > bcomp) return true;
		else if(acomp < bcomp) return false;

		idx++;
	}
}

vector<int>v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
	int n; cin >> n;

	for(int i = 0 ; i < n ; i++)
	{
		int a; cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.begin() + n, comp);
	
	if(v[0] == 0)
	{
		cout << 0;
	}
	else
	{
		for(int i : v)
		{
			cout << i;
		}
	}
}
