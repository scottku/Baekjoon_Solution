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

int N, M;
vector<int> arr_v[32001];
int arr_before[32001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr_before, 0, sizeof(arr_before));

	cin >> N >> M;

	int first, second;
	for (int i = 0; i < M; i++)
	{
		cin >> first >> second;
		arr_before[second]++; // 먼저 풀어야할 문제 갯수 추가
		arr_v[first].push_back(second);
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++)
	{
		if (arr_before[i] == 0) // 비어있다 == 먼저 풀어야할 문제가 없다.
			pq.push(i);
	}

	while (!pq.empty())
	{
		int temp = pq.top();
		pq.pop();

		cout << temp << ' ';

		for (int i = 0; i < arr_v[temp].size(); i++)
		{
			int t = --arr_before[arr_v[temp][i]];
			if (t == 0)
				pq.push(arr_v[temp][i]);
		}
	}
}