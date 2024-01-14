### 최소 스패닝 트리
* 모든 노드를 연결하는 최소의 비용을 구하는 방법
* N개의 노드를 연결하기 위해 필요한 간선의 개수는 N-1개

#### Algorithm
1. 가중치를 기준으로 오름차순 정렬을 함
2. 정렬된 순서대로 경로를 찾음
3. 이때 사이클이 형성되지 않는 경우에만 추가해줌
4. N-1개의 간선을 연결하면 탐색 종료

```cpp
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair<int,pair<int,int>>> v;	
int parents[10003];
int v1, e;
int res = 0;

void input() //입력
{
	cin >> v1 >> e;

	for(int i = 0 ; i < e ; i++)
	{
		int a,b,c; cin >> a >> b >> c;
		v.push_back({c,{a,b}});
	}
}

void preprocessing() //모두 자시자신을 부모노드로 설정 + 오름차순 정렬
{
	for(int i = 1 ; i <= v1 ; i++)
	{
		parents[i] = i;
	}
	sort(v.begin(), v.end());
}

void find_road() //가장 가중치가 적은 간선부터 차례차례 탐색 
{
	int node = 0;
	for(int i = 0 ; i < e ; i++)
	{
		int start = v[i].second.first;
		int end = v[i].second.second;
		int weight = v[i].first;
		if(find_parent(start) != find_parent(end)) //이때 두개의 부모노드가 다를 경우 간선 채택
		{
			union_node(start, end); //두 개를 하나의 집합으로 연결시켜줌(부모노드 합침)
			res += weight; //가중치 추가
			node++; //노드 하나씩 추가
			if(node == v1-1) //MST에서 간선의 개수는 N-1개가 되어야 하기에 break 설정
			{
				return;
			}
		}
		
	}
}

int find_parent(int x) //부모노드 찾기
{
	if(parents[x] == x) //부모노드가 자기 자신일 경우 RootNode로 간주하고 return
	{
		return x;
	}
	else
	{
		return parents[x] = find_parent(parents[x]); //부모노드를 찾으러 가는 과정이며 각 부모노드를 설정해주는 역할(중요)
	}
}

void union_node(int x, int y) //합집합 형성
{
	int a = find_parent(x); //두 개의 부모를 찾아
	int b = find_parent(y);
	parents[b] = a; //한 부모를 다른 한쪽에 넣음
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	preprocessing();
	find_road();
	cout << res;
}


```
