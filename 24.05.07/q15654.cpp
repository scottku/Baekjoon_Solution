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

int N, M;
vector<int> v;
vector<int> v_temp;
bool visit[9];

void DFS(int index, int count)
{
	if (count == M)
	{
		for (int i = 0; i < v_temp.size(); i++)
		{
			cout << v_temp[i] << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = index; i < v.size(); i++)
		{
			if (visit[i])
				continue;
			v_temp.push_back(v[i]);
			visit[i] = true;
			DFS(0, count + 1);
			v_temp.pop_back();
			visit[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
		visit[i] = false;
	}
	sort(v.begin(), v.end());

	DFS(0, 0);
}