#include<stdio.h>
int main(void)
{
    int k;
    scanf("%d", &k);
    int num = 1;
    int answer = 0;
    while (true)
    {
        if (k == 0)
            break;

        if (k >= num && num * 2 > k) // k = 23 ����
        {
            k = k - num; // num = 16 �϶����� 2�� ������, k�� 7
            num = 1;    // num�� 1�� ���µǰ� answer ���� 1�� �߰���
            answer++;    // num = 4 �϶����� 2�� �������� k�� 3
        }                // num�� 1�� ���µǰ� answer�� 2�� �� (���� 2���� �ʿ�)
        else            // num = 2 �϶� k�� 1�� �Ǹ� answer�� 3 -> �ѹ� �� �������� k=0, ���� ���� break;
            num *= 2;
    }

    printf("%d", answer);
}
//