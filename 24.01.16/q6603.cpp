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

vector<int> v;
vector<int> v_tree[10000];

void makeTree(int _start, int i) // 1-> 3,4 / 2-> 5,6 / 3-> 7,8
{
	if (v_tree[_start].size() == 6) // 갯수 6개면 출력
	{
		for (int i = 0; i < 6; i++)
		{
			printf("%d ", v_tree[_start][i]);
		}
		printf("\n");
		return;
	}

	if (i == v.size()) // out of bound 방지
		return;

	v_tree[_start * 2 + 1].clear();
	v_tree[_start * 2 + 2].clear();
	v_tree[_start * 2 + 1] = v_tree[_start];
	v_tree[_start * 2 + 2] = v_tree[_start];
	v_tree[_start * 2 + 1].push_back(v[i]);

	makeTree(_start * 2 + 1, i + 1);
	makeTree(_start * 2 + 2, i + 1);
}

int main(void)
{
	while (true)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			return 0;
		for (int i = 0; i < n; i++)
		{
			int temp;
			scanf("%d", &temp);
			v.push_back(temp);
		}
		v_tree[1].clear();
		v_tree[1].push_back(v[0]);
		v_tree[2].clear();

		makeTree(1, 1); // 맨 앞의 인자가 들어간 상태에서 시작
		makeTree(2, 1); // 맨 앞의 인자가 들어가지 않은 상태에서 시작
		printf("\n");

		v.clear();
		//v_tree->clear(); << 이거 안먹힘
	}
}