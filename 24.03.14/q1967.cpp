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

vector<pair<int, int>> arr[10001];
int arr_toEnd[10001];
bool visit_toEnd[10001];
int arr_fromEnd[10001];
bool visit_fromEnd[10001];
int n;
int answer = 0;
int node = 1;

void findNode(int _root);
void findLength(int _node);

int main(void)
{
	for (int i = 0; i < 10001; i++)
	{
		visit_toEnd[i] = false;
		visit_fromEnd[i] = false;
		arr_toEnd[i] = 0;
		arr_fromEnd[i] = 0;
		arr[i] = vector<pair<int, int>>();
	}
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}

	findNode(1); // 특정 위치에서 가장 멀리 있는 점을 찾기
	for (int i = 1; i <= n; i++)
	{
		if (arr_toEnd[i] > arr_toEnd[node])
			node = i;
	}
	// 가장 먼 점에서 가장 먼 점을 찾기
	findLength(node);
	node = 1;
	for (int i = 1; i <= n; i++)
	{
		if (arr_fromEnd[i] > arr_fromEnd[node])
			node = i;
	}
	printf("%d", arr_fromEnd[node]);
}

void findNode(int _root)
{
	visit_toEnd[_root] = true;
	for (int i = 0; i < arr[_root].size(); i++)
	{
		int child = arr[_root][i].first;

		if (visit_toEnd[child])
			continue;

		int value = arr[_root][i].second;
		arr_toEnd[child] = arr_toEnd[_root] + value;
		findNode(child);
	}
}

void findLength(int _node)
{
	visit_fromEnd[_node] = true;
	for (int i = 0; i < arr[_node].size(); i++)
	{
		int child = arr[_node][i].first;

		if (visit_fromEnd[child])
			continue;

		int value = arr[_node][i].second;
		arr_fromEnd[child] = arr_fromEnd[_node] + value;
		findLength(child);
	}
}