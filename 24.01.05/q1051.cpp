#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string.h>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
    vector<vector<int>> v;

    int width, height;
    int answer = 1;
    scanf("%d %d", &height, &width);

    for (int i = 0; i < height; i++)
    {
        vector<int> v_temp;
        int temp, calc;

        for (int j = 0; j < width; j++)
        {
            //calc = temp / pow(10, j); // 42101 / 10^4 = 4 (�� ���ڸ�)
            //v_temp.push_back(calc);
            //temp -= calc * pow(10, j); // 42101 - 40000 = 2101 (���� ����) 
            // �� ��Ĵ�� ����� ���ڰ� 10^50�±��� �������� ������ ���� �� ����
            scanf("%1d", &temp); // 42101 << �̰� ���ε��� �޾Ƶ鿩���� ����, �Է¹��� �� Ȱ��Ǵ� ��ȣ �˾Ƶ� ��
            v_temp.push_back(temp);
        }
        v.push_back(v_temp);
    } // �簢�� �Է¹޾Ƽ� �����

    // �� �ٿ��� ���� �� 2���� �ִ������� Ȯ���ϱ�.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 1; k < width; k++)
            {
                if (j + k >= width) break;
                if (v.at(i).at(j) == v.at(i).at(j + k)) // k+1 ��ŭ�� ���̸� �� ������ �ϴ� ���簢���� ������� ���� �ִ�.
                {
                    if (i + k >= height) continue; // �� ���̰� ���̺��� Ŀ������ ������
                    if (v.at(i + k).at(j) == v.at(i).at(j))
                    {
                        if (v.at(i).at(j) == v.at(i + k).at(j + k))
                        {
                            answer = (k + 1) * (k + 1) > answer ? (k + 1) * (k + 1) : answer;
                        }
                    }
                }
            }
        }
    }

    printf("%d", answer);
}