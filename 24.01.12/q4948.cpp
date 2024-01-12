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
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> v_pn;

int main(void)
{
	const int _MAX = 123456;
	bool arr[_MAX * 2 + 1]; // 123456*2 + 1
	memset(arr, 0, _MAX * 2 + 1); // 0 �̸� �Ҽ�
	int n;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		v.push_back(n);
	}

	arr[0] = 1;
	arr[1] = 1;

	int i = 2;
	while (true)
	{
		if (arr[i] == 1) // �̹� �Ҽ��� ����� ����������
		{
			i++;
			continue;
		}

		for (int j = 2; i * j <= _MAX * 2; j++)
		{
			// arr[123456 * 2] �Ѿ�� outofbound
			arr[i * j] = 1; // �Ҽ��� ����� ���� ���ֹ�����
		}

		if (i > (_MAX * 2 + 1) / 2 + 1)
			break;
		else
			i++;
	}

	int num = 0;
	int answer = 0;
	int _n;
	while (true)
	{
		_n = v[num];
		for (int i = _n + 1; i <= _n * 2; i++)
		{
			if (i > _MAX * 2) // outofbound
				break;
			if (arr[i] == 0)
				answer++;
		}

		printf("%d\n", answer);
		answer = 0;
		num++;
		if (num >= v.size())
			break;
	}
}