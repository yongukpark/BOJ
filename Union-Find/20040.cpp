//Union Find를 사용하면됨

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int parent[500003];
bool flg = false;

int search_union(int a)
{
	if(parent[a] == a)
	{
		return a;
	}

	return parent[a] = search_union(parent[a]);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector <pair<int,int>> v;
	
	for(int i = 0 ; i < m ; i++)
	{
		int a,b; cin >> a >> b;
		v.push_back({a,b});
	}	

	for(int i = 0 ; i < n ; i++)
	{
		parent[i] = i;
	}

	for(int i = 0 ; i < m ; i++)
	{
		int a = search_union(v[i].first);
		int b = search_union(v[i].second);
		if(a == b)
		{
			cout << i+1;
			return 0;
		}
		else
		{
			parent[a] = b;
		}
	}
	cout << 0;
	return 0;

}
