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
#include <queue>

using namespace std;

vector<char> v;

int main(void)
{
	while (true)
	{
		char c;
		scanf("%c", &c);
		if ((int)c == (int)'\n')
			break;
		v.push_back(c);
	}

	int n_line = 0;
	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if ((int)v[i] == (int)'(' && (int)v[i + 1] == (int)')') // ������
		{
			if (n_line == 0) // ���� ����� ���� �ִ� ��������
			{
				i++; // ������ �׳� �Ѿ��
			}
			else
			{
				answer += n_line; // ���� �ִ� ������ŭ �߷� ���� ��
				i++; // �������� ���ԵǴ� ')' �κ� �ǳʶٱ�
			}
			continue;
		}
		if ((int)v[i] == (int)'(') // �������� �ƴϰ� �׳� ������ �����̸�
		{
			n_line++; // ������ ���� �߰�
			continue;
		}
		if ((int)v[i] == (int)')') // �������� �ƴϰ� �׳� ������ �������̸�
		{
			n_line--; // ������ ���� ����
			answer++; // ������ ���� �����鼭 ������ �߷ȴ� �κ��� �߰����� ( �� �������� �߸���� �߸� ���뿡 �߰� ���ߴ� �κ� )
			continue;
		}
	}

	printf("%d", answer);
}
