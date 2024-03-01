#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

// 프림 : 다익스트라 -> 다익스트라를 이용해 방문한 곳인지 확인

int n, m;
vector<vector<pair<int, int>>> v;
bool visit[10001];
int node[10001];

int main()
{

	memset(visit, false, sizeof(visit));
	for (int i = 0; i < 10001; i++)
	{
		vector<pair<int, int>> temp_v;
		v.push_back(temp_v);
		node[i] = INT_MAX;
	}

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, value;
		scanf("%d %d %d", &a, &b, &value);
		vector<pair<int, int>> temp_v1 = v[a];
		vector<pair<int, int>> temp_v2 = v[b];
		temp_v1.push_back({ value, b });
		temp_v2.push_back({ value, a });
		v[a] = temp_v1;
		v[b] = temp_v2;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, 1 }); // 가중치 없이 1에서 시작

	int answer = 0;
	while (!q.empty())
	{
		int _v = q.top().first;
		int num = q.top().second;
		q.pop();

		if (!visit[num])
		{
			visit[num] = true;
			answer += _v;

			vector<pair<int, int>> temp_v1 = v[num];
			for (int i = 0; i < temp_v1.size(); i++)
			{
				int dest = temp_v1[i].second;
				int _v = temp_v1[i].first;

				if (!visit[dest])
					q.push({ _v, dest });
			}
		}
	}

	printf("%d", answer);
}

// 크루스칼 : 유니온 파인드를 이용해 같은 집합인지 확인

typedef pair<int, pair<int, int>> T;

int V, E;
vector<T> v;
int parent[10000 + 1];
int ans;

int findParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	parent[b] = a;
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ c, {a, b} });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= V; i++)
		parent[i] = i;

	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		T curEdge = v[i];
		int cost = curEdge.first;
		int now = curEdge.second.first;
		int next = curEdge.second.second;

		if (findParent(now) == findParent(next)) continue; // 사이클이면 pass

		unionParent(now, next);
		ans += cost;

		if (++cnt == V - 1) break;
	}
	cout << ans << '\n';
	return 0;
}