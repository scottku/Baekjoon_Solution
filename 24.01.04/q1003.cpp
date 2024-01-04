#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>

// �ð��ʰ� << �ٸ� �ܼ��� �ش��� ���� �� �ִ�
// �ش� ���ڸ� �� Ǯ��ٺ��� 0�� 1�� ȣ�� Ƚ���� �Ǻ���ġ ������ ���谡 ������ Ȯ�� �����ߴ�.
// f(6) = f(5)+f(4) = 2f(4)+f(3) = 3f(3)+2f(2) = 5f(2)+3f(1) = 8f(1)+5f(0)
// ���� 6�� �������� f(1)�� 7��°, f(0)�� 6��° �Ǻ���ġ ���� ���ڸ�ŭ ȣ��ȴ�.
// �׳� �Ǻ���ġ ������ ���ؼ� ���ڸ� ������ �ȴ�.

int dp[41];
// ȣ�� Ƚ���� ���� ���� �ʿ䰡 ����.
//int n_zero = 0;
//int n_one = 0;

int fibonacci(int num)
{
    if (num == 0)
    {
        //n_zero++;
        return dp[0];
    }
    else if (num == 1)
    {
        //n_one++;
        return dp[1];
    }

    if (dp[num] != -1)
    {
        //    if (dp[num] == 0)
        //        n_zero++;
        //    else if (dp[num] == 1)
        //        n_one++;

        return dp[num];
    }

    dp[num - 1] = fibonacci(num - 1);
    // ������ dp[num]�� ���ϸ� �� �Ʒ����� �� ������ ���� ��
    //dp[num - 2] = fibonacci(num - 2);
    dp[num] = dp[num - 1] + dp[num - 2];

    return dp[num];
}

int main(void)
{
    memset(dp, -1, sizeof(dp));
    dp[0] = 0; dp[1] = 1;

    int k, x;
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &x);
        if (x == 0)
        {
            printf("%d %d\n", 1, 0);
            continue;
        }
        if (dp[x] == -1)
            fibonacci(x);

        printf("%d %d\n", dp[x - 1], dp[x]);
    }
}