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
int arr[101][101];
bool visit[101];
vector<int> v;

void func(int _num, int _count)
{
	if (_count == 1) // 처음 시작
	{
		vector<int> v_temp;
		v.push_back(0);
		for (int i = 1; i <= n; i++)
		{
			v.push_back(arr[_num][i]);
			if (arr[_num][i] == 1)
			{
				v_temp.push_back(i);
				visit[i] = true;
			}
		}

		for (int i = 0; i < v_temp.size(); i++)
		{
			func(v_temp[i], _count + 1);
		}
	}
	else
	{
		vector<int> v_temp;
		for (int i = 1; i <= n; i++)
		{
			if (arr[_num][i] == 0)
				continue;
			else
			{
				if (v[i] == 0)
					v[i] = _count;
				else
					v[i] = min(v[i], _count);

				if (visit[i]) // visit 했더라도 일단 최솟값인지 확인은 한 후에 continue
					continue;

				visit[i] = true;
				v_temp.push_back(i);
			}
		}
		for (int j = 0; j < v_temp.size(); j++)
		{
			func(v_temp[j], _count + 1);
		}
	}

}

int main(void)
{
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	int _num = 0;
	int _min = 500001;
	for (int i = 1; i <= n; i++)
	{
		visit[i] = true;
		func(i, 1);
		memset(visit, false, sizeof(visit));
		int answer = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			answer += v[j];
		}
		if (answer < _min)
		{
			_num = i;
			_min = answer;
		}
		v.clear();
	}

	printf("%d", _num);
}