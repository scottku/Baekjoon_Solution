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

int main(void)
{
	int n;
	scanf("%d", &n);

	int tempAnswer = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);

		v.push_back(temp);
		tempAnswer += temp;
	}

	int _total;
	scanf("%d", &_total);

	sort(v.begin(), v.end(), greater<int>());
	if (tempAnswer <= _total)
		printf("%d", v[0]);
	else
	{
		int n_dif = tempAnswer - _total; // 예산과 합산의 차이가 얼마인지 확인
		int i = 0;
		while (true)
		{
			if (n_dif <= 0)
				break;

			if ((v[i] - v[i + 1]) * (i + 1) <= n_dif)
			{
				n_dif -= (v[i] - v[i + 1]) * (i + 1);
				for (int j = 0; j < i + 1; j++)
				{
					v[j] -= (v[i] - v[i + 1]);
				}
				i++;
			}
			else
			{
				int _end = (n_dif / (i + 1)) + 1;
				v[0] -= _end;
				break;
			}
		}

		printf("%d", v[0]);
	}
}