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
#include <climits>
#include <time.h>

using namespace std;

int N;
vector<int> v;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	int s = 0;
	int e = N - 1;
	pair<int, int> p_answer = { INT_MAX / 2, INT_MAX / 2 };
	int sum;
	while (s < e)
	{
		sum = v[s] + v[e];
		if (sum == 0)
		{
			cout << v[s] << ' ' << v[e];
			return 0;
		}

		if (abs(p_answer.first + p_answer.second) > abs(sum))
		{
			p_answer.first = v[s];
			p_answer.second = v[e];
		}

		if (sum > 0)
			e--;
		else
			s++;
	}

	cout << p_answer.first << ' ' << p_answer.second;
}