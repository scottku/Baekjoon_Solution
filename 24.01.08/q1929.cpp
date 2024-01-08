#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>

using namespace std;

// ������ ���� �Ҽ��� �������� �� ������ �������ٸ� �Ҽ��� �ƴϴ�
// ������ ���Ե� for���� 2�� ��ø�Ǿ� �ð� �ʰ� �߻�
//int main(void)
//{
//    vector<int> v;
//    v.push_back(2); // v[0] = 2; ù��° �Ҽ�
//    int n, m;
//    scanf("%d %d", &m, &n);
//    for (int i = 3; i <= n; i++)
//    {
//        if (i % 2 == 0) continue;
//        for (int j = 0; j < v.size(); j++)
//        {
//            if (i % v[j] == 0) // ���������°� �ִ�
//                break; // �����ϰ� �ݺ��� Ż��
//            if (j == v.size() - 1) // ������ �ݺ�
//                v.push_back(i);
//        }
//    }
//    for (int i = 0; i < v.size(); i++)
//    {
//        if (v[i] > n)
//            break;
//
//        if (v[i] >= m && v[i] <= n)
//            printf("%d\n", v[i]);
//    }
//}

// �Ҽ��� ����� �Ҽ��� �ƴ϶�� �Ϳ��� �����Ѵ�.
// �����佺�׳׽��� ü
int _array[1000001];

int main(void)
{
	memset(_array, 0, sizeof(_array));
	int n, m;
	scanf("%d %d", &m, &n);

	_array[0] = 1;
	_array[1] = 1; // 0�� 1�� �Ҽ��� �ƴϴ� // memset�� 0�̳� char �ƴϸ� �ùٸ��� �ʱ�ȭ�� �ȵ�

	for (int i = 2; i <= n + 1; i++)
	{
		for (int j = 2; j <= n + 1; j++)
		{
			if (n < i * j)
				break;

			_array[i * j] = 1;
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (_array[i] == 0)
		{
			printf("%d", i);
			if (i + 1 <= n)
				printf("\n");
		}

	}
}