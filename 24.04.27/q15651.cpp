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

using namespace std;

int N, M;
vector<vector<int>> v;
vector<int> temp_v;

void DFS(int count)
{
	if (count == M)
	{
		v.push_back(temp_v);
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			temp_v.push_back(i);
			DFS(count + 1);
			temp_v.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	DFS(0);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}