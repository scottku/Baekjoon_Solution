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
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
bool visit[10001];
bool _coin[100001];
vector<int> v_coin;

int main(void)
{
	memset(visit, false, sizeof(visit));
	memset(_coin, false, sizeof(_coin));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (!_coin[temp])
		{
			_coin[temp] = true;
			v_coin.push_back(temp);
		}
	}
	sort(v_coin.begin(), v_coin.end(), less<int>());
	for (int i = 0; i < v_coin.size(); i++)
	{
		if (v_coin[i] == m)
		{
			printf("%d", 1);
			return 0;
		}
		else if (v_coin[i] < m)
		{
			visit[v_coin[i]] = true;
			pq.push({ 1, v_coin[i] });
		}
	}

	while (!pq.empty())
	{
		int num = pq.top().first;
		int value = pq.top().second;
		pq.pop();

		for (int i = 0; i < v_coin.size(); i++)
		{
			if (v_coin[i] + value == m)
			{
				printf("%d", num + 1);
				return 0;
			}
			else if (v_coin[i] + value < m)
			{
				if (!visit[v_coin[i] + value])
				{
					visit[v_coin[i] + value] = true;
					pq.push({ num + 1, v_coin[i] + value });
				}
			}
			else
			{

			}
		}
	}
	printf("%d", -1);
}