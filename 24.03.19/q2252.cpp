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

int n, m;
vector<int> arr[32001];
bool visit[32001];

class comp
{
public:
	bool operator() (const pair<int, int>& num1, const pair<int, int>& num2)
	{
		return num1.first > num2.first;
	}
};

void printParent(int num);

int main(void)
{
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= 32000; i++)
	{
		arr[i] = vector<int>();
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int f, b;
		scanf("%d %d", &f, &b);
		arr[b].push_back(f); // b 앞에 f 라는 녀석이 위치해야 한다.
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	for (int i = 1; i <= n; i++)
	{
		pq.push({ arr[i].size(), i });
	}
	while (!pq.empty())
	{
		int size = pq.top().first;
		int num = pq.top().second;
		pq.pop();

		if (!visit[num]) // 본인이 이미 출력되지 않았다면
			printParent(num);
	}
}

void printParent(int num)
{
	if (arr[num].size() != 0)
	{
		for (int i = 0; i < arr[num].size(); i++)
		{
			if (!visit[arr[num][i]]) // 나보다 앞에 있어야 할 녀석이 아직 출력이 안됐다면
				printParent(arr[num][i]); // 그 녀석을 출력시키기 위해 DFS
		}
	}

	visit[num] = true;
	printf("%d ", num);
}