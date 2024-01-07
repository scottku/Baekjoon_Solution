#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <memory.h>

using namespace std;

map<string, int> m;

int main(void)
{
	char c[1001];
	scanf("%s", c);

	string strTemp = c;
	string st = "";
	for (int i = 0; i < strTemp.size(); i++)
	{
		for (int j = 0; j < strTemp.size() - i; j++)
		{
			st = strTemp.substr(j, i + 1);
			m.insert({ st, 1 });
		}
	}

	printf("%d", m.size());
}