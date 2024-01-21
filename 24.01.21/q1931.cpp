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

using namespace std;

int n;
vector<pair<int, int>> v;

int main(void)
{
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back({ b, a });
	}
	sort(v.begin(), v.end(), less<pair<int, int>>());

	int time = v[0].first;
	int count = 1;
	int i = 1;
	while (true)
	{
		if (i >= v.size())
			break;

		if (time <= v[i].second)
		{
			time = v[i].first;
			count++;
		}

		i++;
	}

	printf("%d", count);
}