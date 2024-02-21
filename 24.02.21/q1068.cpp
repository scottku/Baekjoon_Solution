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

int n, del;
vector<int> child[50];
int _count = 0;

void insertNode(int _node, int _parent) // _node 의 부모가 _parent 이다
{
	if (child[_parent][0] == -1)
		child[_parent][0] = _node;
	else
		child[_parent].push_back(_node);
}

void findLeafNode(int _parent)
{
	if (_parent == del)
		return;

	if (child[_parent][0] != -1) // 1명인지 2명인지는 몰라도 자식이 있다.
	{
		if (child[_parent].size() >= 2) // 자식이 2명 이상이다 * 그림 때문에 헷갈렸지만 이진 트리라고 어디에도 말해주지 않았다 *
		{
			for (int i = 0; i < child[_parent].size(); i++)
			{
				if (child[_parent][i] != del)
					findLeafNode(child[_parent][i]);
			}
		}
		else // 한명이다
		{
			if (child[_parent][0] != del)
				findLeafNode(child[_parent][0]);
			else
				_count++;
		}
	}
	else
	{
		// 자식 둘 중 앞 녀석 조차 존재하지 않는다 = 자식이 없다
		_count++;
	}
}

int main(void)
{
	for (int i = 0; i < 50; i++)
	{
		child[i].push_back(-1);
	}

	scanf("%d", &n);
	int _root = -1;
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		if (temp == -1) // * root가 꼭 0번째 노드는 아니다 *
			_root = i;
		else
			insertNode(i, temp);
	}
	scanf("%d", &del); // del 과 del 의 자식들은 없다고 본다.
	findLeafNode(_root);
	printf("%d", _count);
}