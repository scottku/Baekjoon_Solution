#include<stdio.h>
#include<cmath>
int main(void)
{
    int T;
    scanf("%d", &T);
    // �����, �������� �����ϰ��ִ� �� ������ �ᱹ ����� �����ؾ� �ϴ� Ƚ�� �ƴѰ�?
    int x1, y1, x2, y2, n, cx, cy, r;
    int answer = 0;
    double distance1, distance2, sub_radius;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d %d", &cx, &cy, &r);

            distance1 = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));
            distance2 = sqrt(pow(x2 - cx, 2) + pow(y2 - cy, 2));
            if (distance1 < r)
            {
                if (distance2 < r) // ��� ������ ��� �� ���ȿ� ������ ������� ����
                    continue;
                answer++; // ���� �ϳ����� ���ԵǾ� ������ �� 1 �ø�
            }
            else // ���� ������� �������� �ʴ´ٸ�, �������� �����ϰ� �־�� ����� ��
            {
                if (distance2 > r)
                    continue; // �Ѵ� �� �ۿ� �־ ������� �ʴ´�
                answer++;
            }
        }

        printf("%d\n", answer);
        answer = 0;
    }
}
//