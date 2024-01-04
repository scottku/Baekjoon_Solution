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
	scanf("%d %d", &n, &m); // n은 50보다 작고 m은 n보다 작거나 같다

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
		scanf("%d", &temp); // 뽑을 숫자들을 얻는다.
		// printf("%d", array[i]); // 입력 테스트
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
			// 뒤쪽으로 이동하면서 체크
			while (true)
			{
				int num = d.front(); // 뒤쪽으로 이동할때도 deck의 가장 앞의 값을 체크한다. pop_front()로 빠져나가면 다음 시작점은 그대로 d.front() 이기 때문
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
			// 앞쪽으로 이동하면서 체크
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