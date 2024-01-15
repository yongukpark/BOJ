//MST문제에서 간선이 N-2개가 있게 만드는 문제였음
//기존 MST코드에서 수정한 것이 없음

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,pair<int,int>>> v;	
int parents[100003];
int v1, e;
int res = 0;

void input();
void preprocessing();
void find_road();
int find_parent(int);
void union_node(int, int);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	preprocessing();
	find_road();
	cout << res;
}

void input()
{
	cin >> v1 >> e;

	for(int i = 0 ; i < e ; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		v.push_back({c,{a,b}});
	}
}

void preprocessing()
{
	for(int i = 1 ; i <= v1 ; i++)
	{
		parents[i] = i;
	}
	sort(v.begin(), v.end());
}

void find_road()
{
	if(v1 == 2)
	{
		return;
	}

	int node = 0;
	for(int i = 0 ; i < e ; i++)
	{
		int start = v[i].second.first;
		int end = v[i].second.second;
		int weight = v[i].first;
		if(find_parent(start) != find_parent(end))
		{
			union_node(start, end);
			res += weight;
			node++;
			if(node == v1-2)
			{
				return;
			}
			
		}
		
	}
}

int find_parent(int x)
{
	if(parents[x] == x)
	{
		return x;
	}
	else
	{
		return parents[x] = find_parent(parents[x]);
	}
}

void union_node(int x, int y)
{
	int a = find_parent(x);
	int b = find_parent(y);
	parents[b] = a;
}
