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
//int arr[51][51];

int main(void)
{
	//memset(arr, 0, sizeof(arr));
	scanf("%d %d", &n, &m);
	vector<pair<int, int>> v_chicken;
	v_chicken.push_back({ 0, 0 });
	vector<pair<int, int>> v_house;
	v_house.push_back({ 0,0 });
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int temp;
			scanf("%d", &temp);
			//arr[i][j] = temp;
			if (temp == 1)
				v_house.push_back({ i,j });
			if (temp == 2)
				v_chicken.push_back({ i,j }); // v[1] ~ v[k] 까지 k개의 치킨 집 확인
		}
	}

	vector<int> v_permutation;
	for (int i = 1; i < v_chicken.size() - m; i++)	// 치킨집이 5개, 폐점이 2곳이라면
		v_permutation.push_back(0);					// v_chicken.size() <6> - m <3> = 3
	for (int i = 1; i <= m; i++)
		v_permutation.push_back(1);

	int __min = -1;
	do
	{
		vector<int> v_add;
		v_add.push_back(0);
		bool b_first = true;

		for (int i = 0; i < v_permutation.size(); i++)
		{
			if (v_permutation[i] == 1)
			{
				int _x = v_chicken[i + 1].first;
				int _y = v_chicken[i + 1].second;
				if (b_first)
				{
					b_first = false;
					for (int j = 1; j < v_house.size(); j++)
					{
						v_add.push_back(abs(_x - v_house[j].first) + abs(_y - v_house[j].second));
					}
				}
				else
				{
					for (int j = 1; j < v_house.size(); j++)
					{
						v_add[j] = min(v_add[j], (abs(_x - v_house[j].first) + abs(_y - v_house[j].second)));
					}
				}
			}
		}

		int __min_temp = 0;
		for (int j = 1; j < v_add.size(); j++)
		{
			__min_temp += v_add[j];
		}

		if (__min == -1)
			__min = __min_temp;
		else
			__min = min(__min, __min_temp);
	} while (next_permutation(v_permutation.begin(), v_permutation.end()));


	printf("%d", __min);
}