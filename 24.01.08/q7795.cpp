#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

vector<int> arr_A;
vector<int> arr_B;

int main(void)
{
	int num;
	scanf("%d", &num);

	int a, b;
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &a, &b);

		arr_A.clear();
		arr_B.clear();

		int tempA, tempB;
		for (int j = 0; j < a; j++)
		{
			scanf("%d", &tempA);
			arr_A.push_back(tempA);
		}
		for (int j = 0; j < b; j++)
		{
			scanf("%d", &tempB);
			arr_B.push_back(tempB);
		}
		// ������ �Է¹ޱ� �Ϸ�
		sort(arr_A.begin(), arr_A.end(), greater<>());
		sort(arr_B.begin(), arr_B.end(), greater<>()); // ��������

		int answer = 0;

		for (int i = 0; i < arr_A.size(); i++)
		{
			if (arr_A[i] < arr_B[arr_B.size() - 1])
				break;

			for (int j = 0; j < arr_B.size(); j++)
			{
				if (arr_A[i] > arr_B[j]) // arr_A�� 0�� ��ġ (���� ū ��) ���� arr_B�� 0�� ��ġ (���� ū ��)�� �۴ٸ� arr_B�� ���� ���� - 0(��°����) ��ŭ ¦�� �����
				{
					answer += arr_B.size() - j;
					break;
				}
			}
		}
		printf("%d\n", answer);
	}
}