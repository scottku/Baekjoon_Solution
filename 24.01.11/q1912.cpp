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

using namespace std;

stack<int> s;
vector<int> v;
vector<int> dp;
int _minus = 0;

int main(void)
{
	int n;
	scanf("%d", &n);

	int temp;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		v.push_back(temp); // 10 - 4 3 1 5 6 - 35 12 21 - 1
		if (temp < 0)
			_minus++;
	}

	// ������� ���� ���Ѵ� -> �� ���� ������ �Ǿ������ ���� �� �Ʒ��κ��� ������
	// 10 -4 3 1 5 6 -35 12 21 -1 ����, ���Ǻκ��� �� ���ϴٰ� -35�� �������鼭 ������ ���� ������ ���Ѵ�
	// (���� ��) 12 21 -1
	// (���� ��)�� �����ϰ� 12 21 ... �� ���ذ��� �ȴ�.

	int _max = 0;
	int answer = 0;
	if (n == 1) // �迭�� 1���� �� ���� ���
	{
		printf("%d", v[0]);
		return 0;
	}

	if (_minus == v.size()) // ��� ���� ������, ���� ū �� �Ѱ��� ���
	{
		int _min = -1001; // �Է� �޴� �� �� ���� ���� ���� -1000
		for (int i = 0; i < v.size(); i++)
		{
			_min = max(_min, v[i]);
		}
		printf("%d", _min);
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		_max += v[i];
		if (_max < 0)
		{
			_max = 0; // ������ �Ѿ������ �Ʒ��� ģ������ ���� ��������
			continue;
		}
		answer = max(answer, _max); // ���� �ִ밪 vs ���� �������鼭 ���� ��
	}

	printf("%d", answer);
}