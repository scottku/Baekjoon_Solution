#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>

using namespace std;

// 기존의 수를 소수로 나누었을 때 나누어 떨어진다면 소수가 아니다
// 연산이 포함된 for문이 2번 중첩되어 시간 초과 발생
//int main(void)
//{
//    vector<int> v;
//    v.push_back(2); // v[0] = 2; 첫번째 소수
//    int n, m;
//    scanf("%d %d", &m, &n);
//    for (int i = 3; i <= n; i++)
//    {
//        if (i % 2 == 0) continue;
//        for (int j = 0; j < v.size(); j++)
//        {
//            if (i % v[j] == 0) // 나누어지는게 있다
//                break; // 무시하고 반복분 탈출
//            if (j == v.size() - 1) // 마지막 반복
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

// 소수의 배수는 소수가 아니라는 것에서 시작한다.
// 에라토스테네스의 체
int _array[1000001];

int main(void)
{
	memset(_array, 0, sizeof(_array));
	int n, m;
	scanf("%d %d", &m, &n);

	_array[0] = 1;
	_array[1] = 1; // 0과 1은 소수가 아니다 // memset이 0이나 char 아니면 올바르게 초기화가 안됨

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