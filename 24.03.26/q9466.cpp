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

//class comp
//{
//public:
//	bool operator() (const pair<pair<int, int>, bool>& p1, const pair<pair<int, int>, bool>& p2)
//	{
//		if (p1.first.first != p2.first.first) // 더 위쪽인 순서
//			return p1.first.first > p2.first.first;
//		else if(p1.first.second != p2.first.second) // 더 왼쪽인 순서
//			return p1.first.second > p2.first.second;
//	}
//};
int test_case;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> test_case;
	for (int tc = 0; tc < test_case; tc++)
	{
		int _count = 0;
		int n;
		cin >> n;

		int arr[100001];
		int visit_num[100001];
		pair<bool, int> visit[100001];
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			visit_num[i] = 0;
			visit[i] = { false, 0 };
		}

		for (int i = 1; i <= n; i++)
		{
			if (visit[i].first)
				continue;

			queue<int> q;
			q.push(i);
			int temp_count = 0;
			while (!q.empty())
			{
				int s = q.front();
				q.pop();

				if (visit[s].first && visit[s].second != i)
					break;

				if (visit_num[s] >= 2)
					break;

				q.push(arr[s]);
				visit_num[s] += 1;
				visit[s] = { true, i };
			}

		}

		for (int i = 1; i <= n; i++)
		{
			if (visit_num[i] >= 2)
				_count++;
		}

		cout << n - _count << '\n';
	}
}