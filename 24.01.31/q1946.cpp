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

using namespace std;

int n, m;
vector<pair<int, int>> v;

// 지원자a 와 같이 리스트에 선발될 수 있는 사람들을 구한다
// 지원자a 와 지원자b가 같이 들어갈 수 있다면, 지원자b 가 같이 들어갈 친구들 다시 구한다.
// 돌고돌아 지원자c가 지원자a와도 같이 들어갈 수 있다면, 지원자 a b c는 한 리스트에 포함될 수 있다.
// 직선이 아닌 원형으로 연결될 수 있는가? 최대 몇명까지 해당 원형 연결에 포함될 수 있는가
// >> 배열의 크기가 10만 * 10만 이라 무조건 크기 오버... 옳은 방법이 아님

int main(void)
{
	scanf("%d", &n);

	for (int tc = 0; tc < n; tc++)
	{
		v.clear();
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			v.push_back({ a, b });
		}

		if (m == 1)
		{
			printf("%d\n", 1);
			continue;
		}

		sort(v.begin(), v.end(), less<pair<int, int>>());
		int _count = 1;
		int _rank = v[0].second;
		for (int i = 1; i < v.size(); i++)
		{
			if (_rank > v[i].second) // 그리디 알고리즘으로 가보자
			{
				_count++;
				_rank = v[i].second; // 한쪽 순위를 정렬해놓고 다른쪽 순위를 체크해보면서 하나씩 갯수를 늘려나간다.
			}
		}
		printf("%d\n", _count);
	}
}