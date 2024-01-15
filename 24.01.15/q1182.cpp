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

void findNumber(int _start) // Ʈ�� �������� ��� ������ ������. -> Ư�� ��ġ�� ���ڸ� ���ϰų� ���ų�
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
	// ���ڰ� �׷��� ũ�� �ʰ�, �ð��� 2�ʷ� �˳� -> ����Ž��
	findNumber(0);

	int answer = 0;
	for (int i = pow(2, n) - 1; i < pow(2, n + 1) - 1; i++)
	{
		if (v_tree[i] == s)
			answer++;
	}
	if (s == 0)
		answer--; // �ϳ��� �ȴ��ؼ� 0 ���°� �κм����� �ƴ�
	printf("%d", answer);
}