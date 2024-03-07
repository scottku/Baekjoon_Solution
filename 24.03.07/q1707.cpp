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

#define _BLACK_ 1
#define _WHITE_ 2

vector<vector<int>> v;
int test_case;
int _vertex, _edge;
int visit[20001];

bool duplication(int vertex, int color);

int main(void)
{
	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		memset(visit, 0, sizeof(visit));
		v.clear();

		scanf("%d %d", &_vertex, &_edge);
		for (int j = 0; j <= _vertex; j++)
		{
			v.push_back(vector<int>());
		}
		for (int j = 0; j < _edge; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}

		bool b_dup = false;
		for (int j = 1; j <= _vertex; j++)
		{
			if (visit[j] == 0) // 한번도 방문되지 않은 곳
			{
				b_dup = duplication(j, _WHITE_);
				if (b_dup)
					break;
			}
		}
		if (b_dup)
			printf("%s\n", "NO");
		else
			printf("%s\n", "YES");
	}
}

bool duplication(int vertex, int color)
{
	if (visit[vertex] != 0) // 방문된 곳
	{
		if (visit[vertex] == color) // 방문된 곳인데 같은 색으로 칠해짐 -> 루프 모양이어도 가능한 이유
			return false;

		return true;
	}

	visit[vertex] = color;
	// 해당 정점과 연결된 다른 친구들은 다른 색으로 변경한다.
	int next_color;
	if (color == _WHITE_)
		next_color = _BLACK_;
	else
		next_color = _WHITE_;

	vector<int> tv = v[vertex];
	for (int i = 0; i < tv.size(); i++)
	{
		if (duplication(tv[i], next_color))
			return true;
	}

	return false;
}