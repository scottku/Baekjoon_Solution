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
		// 데이터 입력받기 완료
		sort(arr_A.begin(), arr_A.end(), greater<>());
		sort(arr_B.begin(), arr_B.end(), greater<>()); // 내림차순

		int answer = 0;

		for (int i = 0; i < arr_A.size(); i++)
		{
			if (arr_A[i] < arr_B[arr_B.size() - 1])
				break;

			for (int j = 0; j < arr_B.size(); j++)
			{
				if (arr_A[i] > arr_B[j]) // arr_A의 0번 위치 (제일 큰 수) 보다 arr_B의 0번 위치 (제일 큰 수)가 작다면 arr_B의 인자 갯수 - 0(번째부터) 만큼 짝이 생길것
				{
					answer += arr_B.size() - j;
					break;
				}
			}
		}
		printf("%d\n", answer);
	}
}