#include <stdio.h>
#include <cmath>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m); // n�� 50���� �۰� m�� n���� �۰ų� ����

	int index = 0;
	int count = 0;
	deque<int> d;

	for (int i = 0; i < n; i++)
	{
		d.push_back(i + 1); // 1 2 3 4 5 6 7 8 9 10
	}

	int temp;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &temp); // ���� ���ڵ��� ��´�.
		// printf("%d", array[i]); // �Է� �׽�Ʈ
		index = 0;

		for (int j = 0; j < d.size(); j++)
		{
			if (d[j] == temp)
			{
				index = j;
				break;
			}
		}

		if (index > d.size() - index)
		{
			// �������� �̵��ϸ鼭 üũ
			while (true)
			{
				int num = d.front(); // �������� �̵��Ҷ��� deck�� ���� ���� ���� üũ�Ѵ�. pop_front()�� ���������� ���� �������� �״�� d.front() �̱� ����
				if (d.front() == temp)
				{
					d.pop_front();
					break;
				}
				d.push_front(d.back());
				d.pop_back();
				++count;
			}
		}
		else
		{
			// �������� �̵��ϸ鼭 üũ
			while (true)
			{
				if (d.front() == temp)
				{
					d.pop_front();
					break;
				}
				d.push_back(d.front());
				d.pop_front();
				++count;
			}
		}
	}

	printf("%d", count);
}