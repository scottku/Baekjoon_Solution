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

unordered_map<long long, int> v;
long long a, b;
bool b_exist = false;
int g_count = 999999;

void aIntoB(long long a, int _count)
{
	if (v.find(a * 2) == v.end()) // map에 key가 없다면
		v.insert({ a * 2, _count + 1 });
	else
		v[a * 2] = min(v[a * 2], _count + 1);

	if (v.find(a * 10 + 1) == v.end())
		v.insert({ a * 10 + 1, _count + 1 });
	else
		v[a * 10 + 1] = min(v[a * 10 + 1], _count + 1);

	if (a * 2 < b)
	{
		aIntoB(a * 2, _count + 1);
	}
	else if (a * 2 == b)
	{
		g_count = min(g_count, v[a * 2]);
		return;
	}

	if (a * 10 + 1 < b)
		aIntoB(a * 10 + 1, _count + 1);
	else if (a * 10 + 1 == b)
	{
		g_count = min(g_count, v[a * 10 + 1]);
		return;
	}
}

int main(void)
{
	scanf("%lld %lld", &a, &b);

	v.insert({ a, 1 });

	aIntoB(a, 1);

	if (g_count == 999999)
		printf("%d", -1);
	else
		printf("%d", g_count);
}