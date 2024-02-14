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

int n, m;
int parent[1000001];

int findParent(int _start)
{
	if (parent[_start] == _start)
		return _start;
	else
		return findParent(parent[_start]);
}

void unionParent(int _a, int _b)
{
	int a = findParent(_a);
	int b = findParent(_b);
	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}

int main(void)
{
	memset(parent, 0, sizeof(parent));
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int calc, a, b;
		scanf("%d %d %d", &calc, &a, &b);
		if (calc == 0) // 둘을 합쳐라
		{
			unionParent(a, b);
		}
		else // calc == 1 / 같은 곳에 포함되어있는가를 체크?
		{
			if (a == b)
				printf("%s\n", "YES");
			else
			{
				int a_parent = findParent(a);
				int b_parent = findParent(b);
				if (a_parent == b_parent) // 같은 부모 = 같은 집합
					printf("%s\n", "YES");
				else
					printf("%s\n", "NO");
			}
		}
	}
}