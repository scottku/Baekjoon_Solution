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

vector<int> v[101];
int arr[101];
int n_parent, n_child;

vector<int> v_p;
vector<int> v_c;

int main(void)
{
	memset(arr, 0, sizeof(arr));

	int n_human;
	scanf("%d", &n_human);

	scanf("%d %d", &n_parent, &n_child);

	int n_num;
	scanf("%d", &n_num);

	for (int i = 0; i < n_num; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);

		v[y].push_back(x); // y의 부모는 x다.
		arr[y] = true; // y는 부모가 있다.
	}

	vector<int> v_parent;
	v_parent.push_back(n_parent);
	vector<int> v_child;
	v_child.push_back(n_child);
	bool b_parent = true;
	bool b_child = true;
	int np = n_parent;
	int nc = n_child;

	while (true)
	{
		if (b_parent)
		{
			if (arr[np])
			{
				v_parent.push_back(v[np][0]);
				np = v[np][0];
			}
			else
				b_parent = false;
		}
		if (b_child)
		{
			if (arr[nc])
			{
				v_child.push_back(v[nc][0]);
				nc = v[nc][0];
			}
			else
				b_child = false;
		}

		if (!b_parent && !b_child)
			break;
	}

	if (v_parent[v_parent.size() - 1] != v_child[v_child.size() - 1]) // 각 최상위 조상이 다르다 -> 다른 직계
	{
		printf("%d", -1);
	}
	else // 최상위 조상이 같다면 촌 계산 가능
	{
		while (true)
		{
			if (v_parent[v_parent.size() - 1] == v_child[v_child.size() - 1])
			{
				v_parent.pop_back(); // 9 - 5 - 2 - 1 과 10 - 7 - 4 - 2 - 1 이라면
				v_child.pop_back(); // 공통 조상인 1과 2는 일단 제외한다.

				if (v_parent.empty() || v_child.empty())
					break;
			}
			else
				break;
		}
		if (v_parent.empty())
			printf("%d", v_child.size());
		else if (v_child.empty())
			printf("%d", v_parent.size());
		else
			// 9 - 5 와 10 - 7 - 4 가 남는다. size는 각각 2와 3, 촌 수는 size-1 + size-1 + 2 (조상 바로 밑 형재자매 2촌)
			printf("%d", v_parent.size() - 1 + v_child.size() - 1 + 2);
	}
}