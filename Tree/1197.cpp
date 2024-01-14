//처음보는 MST문제이자 합집합 문제 
//풀이가 꽤 복잡해 보였지만 개념은 생각보다 쉬웠음

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,pair<int,int>>> v;	
int parents[10003];
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
			if(node == v1-1)
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
