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

int _vertex, _edge;
#define INF 987654321
class myClass
{
public:
	bool toV1;
	bool toV2;
	bool toN;
	int dist;
	int pos;
	myClass(int _dist, int _pos, bool _v1, bool _v2, bool _n)
	{
		dist = _dist;
		pos = _pos;
		toV1 = _v1;
		toV2 = _v2;
		toN = _n;
	}
};
int arr[801][801];
int mustV1, mustV2;
int arr1[801];
int arr2[801];

class comp
{
public:
	bool operator()(const myClass& left, const myClass& right)
	{
		return left.dist > right.dist;
	}
};

void findMinDist(int _start);

int main(void)
{
	for (int i = 0; i < 801; i++)
	{
		for (int j = 0; j < 801; j++)
		{
			if (i == j)
				arr[i][j] = 0;
			else
				arr[i][j] = INF;
		}
	}

	scanf("%d %d", &_vertex, &_edge);
	for (int i = 0; i < _edge; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (arr[a][b] > c)
			arr[a][b] = c;
		if (arr[b][a] > c)
			arr[b][a] = c;
	}
	scanf("%d %d", &mustV1, &mustV2);

	findMinDist(mustV1);
	findMinDist(mustV2);

	int answer1 = -1;
	int answer2 = -1;
	if (arr1[1] < INF && arr1[mustV2] < INF && arr2[_vertex] < INF)
		answer1 = arr1[1] + arr1[mustV2] + arr2[_vertex];
	if (arr2[1] < INF && arr2[mustV1] < INF && arr1[_vertex] < INF)
		answer2 = arr2[1] + arr2[mustV1] + arr1[_vertex];
	if (answer1 == -1 && answer2 == -1)
		printf("%d", -1);
	else if (answer1 == -1)
		printf("%d", answer2);
	else if (answer2 == -1)
		printf("%d", answer1);
	else
		printf("%d", min(answer1, answer2));
}

void findMinDist(int _start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	if (mustV1 == _start)
	{
		for (int i = 0; i < 801; i++)
			arr1[i] = INF;
		pq.push({ 0, _start });
		while (!pq.empty())
		{
			int dist = pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			for (int i = 1; i <= _vertex; i++)
			{
				if (dist + arr[pos][i] < arr1[i]) // 연결되어있거나 더 작은 거리 값을 가지고 있다면
				{
					arr1[i] = dist + arr[pos][i];
					pq.push({ arr1[i], i });
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < 801; i++)
			arr2[i] = INF;
		pq.push({ 0, _start });
		while (!pq.empty())
		{
			int dist = pq.top().first;
			int pos = pq.top().second;
			pq.pop();

			for (int i = 1; i <= _vertex; i++)
			{
				if (dist + arr[pos][i] < arr2[i]) // 연결되어있거나 더 작은 거리 값을 가지고 있다면
				{
					arr2[i] = dist + arr[pos][i];
					pq.push({ arr2[i], i });
				}
			}
		}
	}
}