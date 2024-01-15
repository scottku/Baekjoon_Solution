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
vector<int> v_tree;
int g_num = 0;

void findNumber(int _start) // 트리 형식으로 모든 조건을 만들어간다. -> 특정 위치의 숫자를 더하거나 빼거나
{
	if (_start > v.size() - 1)
		return;

	int _add = v[_start];
	int temp = pow(2, _start) - 1;
	for (int i = 0; i < pow(2, _start); i++)
	{
		v_tree.push_back(v_tree[temp] + _add);
		v_tree.push_back(v_tree[temp]);
		temp++;
	}

	findNumber(_start + 1);
}

int main(void)
{
	int n, s;
	scanf("%d %d", &n, &s);
	v_tree.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	// 숫자가 그렇게 크지 않고, 시간도 2초로 넉넉 -> 완전탐색
	findNumber(0);

	int answer = 0;
	for (int i = pow(2, n) - 1; i < pow(2, n + 1) - 1; i++)
	{
		if (v_tree[i] == s)
			answer++;
	}
	if (s == 0)
		answer--; // 하나도 안더해서 0 나온건 부분수열이 아님
	printf("%d", answer);
}