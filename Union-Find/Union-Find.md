### Union-Find
---
20040 코드를 통해 알아보면

Union-Find는 같은집합에 속하는 노드들을 구분해주는 알고리즘임
1. 각 노드들이 부모노드를 찾아가며 자신의 가장 위 조상?을 찾는 느낌이고 여기서 주의할점은
아래 함수에서 return parent[a] = search_union(parent[a])를 해줌으로 return과 할당을 한번에 한다는 것이다.

```cpp
int search_union(int a)
{
	if(parent[a] == a)
	{
		return a;
	}

	return parent[a] = search_union(parent[a]);
}
```
2. 그리고 위문제의 경우 이어지는 간선이기 때문에 아래코드에서 parent[a] = b를 이용하여 두개의 부모노드를 통일시켜주어야한다.
이때 통일하는 쪽은 어느쪽이든 상관없다?

```cpp
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
```

전체코드

```cpp
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

```
