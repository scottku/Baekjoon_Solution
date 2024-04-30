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

int N, K;
int M, V;
int C;

class Comp
{
public:
	bool operator() (const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if (p1.second != p2.second)
			return p1.second > p2.second;
		else
			return p1.first > p2.first;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq;
priority_queue<int, vector<int>, greater<int>> pq_bag;
priority_queue<int, vector<int>, less<int>> pq_temp;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> M >> V;
		pq.push({ V, M });
	}
	for (int i = 1; i <= K; i++)
	{
		cin >> C;
		pq_bag.push(C);
	}

	long long answer = 0;
	while (!pq_bag.empty())
	{
		int bag_weight = pq_bag.top();
		pq_bag.pop();
		while (!pq.empty())
		{
			if (pq.top().second <= bag_weight)
			{
				pq_temp.push(pq.top().first);
				pq.pop();
			}
			else
				break;
		}
		if (!pq_temp.empty())
		{
			answer += pq_temp.top();
			pq_temp.pop();
		}
	}
	cout << answer;
}