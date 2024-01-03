#include<stdio.h>
#include<cmath>
int main(void)
{
    int k;
    scanf("%d", &k);
    int x1, y1, r1, x2, y2, r2;
    int answer = 404;
    double distance, sub_radius;
    for (int i = 0; i < k; i++)
    {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        sub_radius = r1 > r2 ? r1 - r2 : r2 - r1;

        if (distance == 0 && r1 == r2) answer = -1;
        else if (distance < r1 + r2 && distance > sub_radius) answer = 2;
        else if (distance == r1 + r2 || distance == sub_radius) answer = 1;
        else
            answer = 0;

        printf("%d\n", answer);
    }
}
//