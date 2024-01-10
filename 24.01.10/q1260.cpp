#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

int _dfs[1001][1001];
int _dfs_already[1001];
int _bfs[1001][1001];
int _bfs_already[1001];

void dfs(int start, int node)
{
	for (int i = 1; i <= node; i++)
	{
		if (start == i)
			continue;

		if (_dfs[start][i] == 1)
		{
			_dfs[start][i] = 0;
			_dfs[i][start] = 0;
			if (_dfs_already[i] != 1)
			{
				printf("%d ", i);
				_dfs_already[i] = 1;
				dfs(i, node);
			}
		}
	}
}

deque<int> dq;
vector<int> v;

void bfs(int node)
{
	int start = dq.front();
	dq.pop_front();

	for (int i = 1; i <= node; i++)
	{
		if (start == i)
			continue;

		if (_bfs[start][i] == 1)
		{
			if (_bfs_already[i] != 1)
			{
				dq.push_back(i);
				v.push_back(i);
				_bfs_already[i] = 1;
			}
			_bfs[start][i] = 0;
			_bfs[i][start] = 0;
		}
	}

	if (!dq.empty())
		bfs(node);
}

int main(void)
{
	memset(_dfs, 0, sizeof(_dfs));
	memset(_bfs, 0, sizeof(_bfs));
	int node, line, start;
	scanf("%d %d %d", &node, &line, &start);

	for (int i = 0; i < line; i++)
	{
		int s, e;
		scanf("%d %d", &s, &e);

		_dfs[s][e] = 1;
		_dfs[e][s] = 1;
		_bfs[s][e] = 1;
		_bfs[e][s] = 1;
	}

	// DFS
	memset(_dfs_already, 0, sizeof(_dfs_already));
	printf("%d ", start);
	_dfs_already[start] = 1;
	dfs(start, node);
	printf("\n");

	// BFS
	memset(_bfs_already, 0, sizeof(_bfs_already));
	dq.push_back(start);
	v.push_back(start);
	bfs(node);
	for (int i = 0; i < v.size(); i++)
	{
		printf("%d ", v[i]);
	}
}