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
#include <time.h>

using namespace std;

struct edge
{
public:
	int s;
	int e;
	int t;
};

#define ARR_SIZE 501
#define INF 987654321
int TC, N, M, W;
int from, to, Value;
int Distance[ARR_SIZE];
vector<edge> v;

bool BellmanFord(int start)
{
	for (int i = 1; i <= N; i++)
	{
		Distance[i] = INF;
	}

	int s, e, t;
	Distance[start] = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			s = v[j].s;
			e = v[j].e;
			t = v[j].t;
			if (Distance[e] > Distance[s] + t)
				Distance[e] = Distance[s] + t;
		}
	} // N-1 번 반복해서 start 위치에서 각 노드 까지의 최단거리 확인

	for (int j = 0; j < v.size(); j++)
	{
		s = v[j].s;
		e = v[j].e;
		t = v[j].t;
		if (Distance[e] > Distance[s] + t) // 한번 더 추가로 반복했을 때 감소하는 거리가 나온다면 음의 사이클이 존재
			return true;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		v.clear();

		for (int i = 0; i < M; i++)
		{
			cin >> from >> to >> Value;
			v.push_back({ from, to, Value });
			v.push_back({ to, from, Value });
		}
		for (int i = 0; i < W; i++)
		{
			cin >> from >> to >> Value;
			v.push_back({ from, to, -Value });
		}

		// 밸만 포드 (음수 가중치), 모든 간선을 확인하는 것이 포인트
		if (BellmanFord(1)) // 음의 사이클이 있다면, 무한정 음의 사이클을 통과한 후 원래 위치로 돌아가면 무조건 시간은 감소할 수 밖에 없음
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
}