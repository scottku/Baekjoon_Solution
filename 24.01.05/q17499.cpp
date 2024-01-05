#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include <deque>

using namespace std;

// for���� ������ �ð��ʰ��� ���ٰ� ������ ��޵ȴ�. �׶��׶����� shift���� ���� shift�� �����ؼ� ��� ��ġ�� �����Ѵ�.

int main(void)
{
    //memset(dp, -1, sizeof(dp));
    //dp[0] = 0; dp[1] = 1;

    int n_size, n_calc;
    scanf("%d %d", &n_size, &n_calc);

    int index = 0; // ����Ʈ�� �������� �ʰ� �󸶳� ������������ ������ ��� �� ���߿� ����ϱ�

    deque<int> d;
    int num = n_size + 1;
    while (--num)
    {
        int temp;
        scanf("%d", &temp);

        d.push_back(temp);
    }

    int a, b, c;
    for (int i = 0; i < n_calc; i++)
    {
        scanf("%d", &a);
        int temp;
        switch (a)
        {
        case 1:
            scanf("%d %d", &b, &c);

            temp = b - 1 + index;
            if (temp > n_size - 1)
                temp -= n_size;
            d[temp] += c;
            break;
        case 2:
            scanf("%d", &b); // ������ ������ ��������
            index += n_size - b; // 1 2 3 4 5�� ������ b = 2 ��� index = 3, �� �տ��� �ڷ� n_size - b ������ŭ �ű�Ŷ� ����� ����. -> 4 5 1 2 3
            index %= n_size; // 1 2 3 4 5 ���� index�� 12���, 5 �϶� 1 2 3 4 5, 10 �϶� 1 2 3 4 5 �̹Ƿ� n_size�� ������ ���� �������� ������ ����
            //for (int j = 0; j < b; j++)
            //{
            //    d.push_front(d.back());
            //    d.pop_back();
            //}
            break;
        case 3:
            scanf("%d", &b);
            index += b;
            index %= n_size;
            //for (int j = 0; j < b; j++)
            //{
            //    d.push_back(d.front());
            //    d.pop_front();
            //}
            break;
        }
    }

    for (int k = 0; k < n_size; k++)
    {
        int temp = k + index;
        if (temp > n_size - 1)
            temp -= n_size;
        printf("%d ", d[temp]);
    }
}