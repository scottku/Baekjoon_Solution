#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
    //char s[10];
    string s = "";
    string movement = "";
    int pKing[2];
    int pStone[2];
    getline(cin, s); // "A" "1" "" "A" "2" "" "5" "0"
    //  0   1  2   3   4   5  6   7
// ��ȯ �׽�Ʈ
//int i = int('A'); -> 65
//int j = int('H'); -> 72
    pKing[0] = int(s[0]) - 65; // 0~7
    pKing[1] = int(s[1]) - '0' - 1; // 0~7
    pStone[0] = int(s[3]) - 65;
    pStone[1] = int(s[4]) - '0' - 1;
    int loop = 0;
    if (s.size() > 7)
    {
        if (int(s[7]) != 10 && int(s[7]) != 32)
        {
            loop = (int(s[6]) - '0') * 10 + (int(s[7]) - '0');
        }
        else
            loop = int(s[6]) - '0';
    }
    else
    {
        loop = int(s[6]) - '0';
    }

    for (int i = 0; i < loop; i++)
    {
        getline(cin, movement);
        char c_front = movement[0];
        char c_back = '\n';
        if (movement.size() > 1)
            c_back = movement[1]; // '' = 32, '\n' = 10
        switch (c_front)
        {
            case int('B') :
                if (pKing[1] - 1 >= 0) // �Ʒ��� �Ѿ�����°� �ƴϸ�
                {
                    pKing[1] -= 1; // �ϴ� �Ʒ��� �̵�
                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // �̵����� ���� ���� ŷ�� ��ġ�� ���������ٸ� ���� �ű�
                    {
                        if (pStone[1] - 1 >= 0) // ���� ���� ������ �����°� �ƴϸ�
                            pStone[1] -= 1; // �Ʒ��� �̵��ϰ� �̵� ����
                        else // �� �̵����״µ� ���� ���̴�?
                            pKing[1] += 1; // ŷ�� �̵� ���
                    }
                    else // ŷ�� �Ű��� �� ���� ��ġ�°� �ƴϸ�
                    {
                        // ŷ�� �ű�� ��, ���� �ǵ� �ʿ� ����.
                    }
                }
                else
                    break; // ���� ŷ�� �� ������ �̵��ؼ� �Ѿ������ �̵� ����

                break;
                case int('T') :
                    if (pKing[1] + 1 <= 7) // ���� �Ѿ�����°� �ƴϸ�
                    {
                        pKing[1] += 1; // �ϴ� ���� �̵�
                        if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // �̵����� ���� ���� ŷ�� ��ġ�� ���������ٸ� ���� �ű�
                        {
                            if (pStone[1] + 1 <= 7) // ���� ���� ������ �����°� �ƴϸ�
                                pStone[1] += 1; // ���� �̵��ϰ� �̵� ����
                            else // �� �̵����״µ� ���� ���̴�?
                                pKing[1] -= 1; // ŷ�� �̵� ���
                        }
                        else // ŷ�� �Ű��� �� ���� ��ġ�°� �ƴϸ�
                        {
                            // ŷ�� �ű�� ��, ���� �ǵ� �ʿ� ����.
                        }
                    }
                    else
                        break; // ���� ŷ�� �� ������ �̵��ؼ� �Ѿ������ �̵� ����

                    break;
                    case int('R') :
                        if (int(c_back) == 32 || int(c_back) == 10) // �ޱ��ڰ� �����̰ų� �ٹٲ��� ��
                        {
                            if (pKing[0] + 1 <= 7) // ���������� �Ѿ�����°� �ƴϸ�
                            {
                                pKing[0] += 1; // �ϴ� �̵�
                                if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // �̵����� ���� ���� ŷ�� ��ġ�� ���������ٸ� ���� �ű�
                                {
                                    if (pStone[0] + 1 <= 7) // ���� ���� ������ �����°� �ƴϸ�
                                        pStone[0] += 1; // �̵��ϰ� �̵� ����
                                    else // �� �̵����״µ� ���� ���̴�?
                                        pKing[0] -= 1; // ŷ�� �̵� ���
                                }
                                else // ŷ�� �Ű��� �� ���� ��ġ�°� �ƴϸ�
                                {
                                    // ŷ�� �ű�� ��, ���� �ǵ� �ʿ� ����.
                                }
                            }
                            else
                                break; // ���� ŷ�� �� ������ �̵��ؼ� �Ѿ������ �̵� ����
                        }
                        else // �ڿ� ���ڰ� ���� ��
                        {
                            if (int(c_back) == int('T'))
                            {
                                if (pKing[0] + 1 <= 7 && pKing[1] + 1 <= 7)
                                {
                                    pKing[0] += 1; pKing[1] += 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] + 1 <= 7 && pStone[1] + 1 <= 7)
                                        {
                                            pStone[0] += 1; pStone[1] += 1;
                                        }
                                        else
                                        {
                                            pKing[0] -= 1; pKing[1] -= 1;
                                        }
                                    }
                                    else
                                    {
                                        // �Ȱ�ġ�� �ȿŰܿ�
                                    }
                                }
                                else
                                    break;
                            }
                            else if (int(c_back) == int('B'))
                            {
                                if (pKing[0] + 1 <= 7 && pKing[1] - 1 >= 0)
                                {
                                    pKing[0] += 1; pKing[1] -= 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] + 1 <= 7 && pStone[1] - 1 >= 0)
                                        {
                                            pStone[0] += 1; pStone[1] -= 1;
                                        }
                                        else
                                        {
                                            pKing[0] -= 1; pKing[1] += 1;
                                        }
                                    }
                                    else
                                    {
                                        // �Ȱ�ġ�� �ȿŰܿ�
                                    }
                                }
                                else
                                    break;
                            }
                        }

                    break;
                    case int('L') :
                        if (int(c_back) == 32 || int(c_back) == 10) // �ޱ��ڰ� �����̰ų� �ٹٲ��� ��
                        {
                            if (pKing[0] - 1 >= 0) // �������� �Ѿ�����°� �ƴϸ�
                            {
                                pKing[0] -= 1; // �ϴ� �̵�
                                if (pKing[0] == pStone[0] && pKing[1] == pStone[1]) // �̵����� ���� ���� ŷ�� ��ġ�� ���������ٸ� ���� �ű�
                                {
                                    if (pStone[0] - 1 >= 0) // ���� ���� ������ �����°� �ƴϸ�
                                        pStone[0] -= 1; // �̵��ϰ� �̵� ����
                                    else // �� �̵����״µ� ���� ���̴�?
                                        pKing[0] += 1; // ŷ�� �̵� ���
                                }
                                else // ŷ�� �Ű��� �� ���� ��ġ�°� �ƴϸ�
                                {
                                    // ŷ�� �ű�� ��, ���� �ǵ� �ʿ� ����.
                                }
                            }
                            else
                                break; // ���� ŷ�� �� ������ �̵��ؼ� �Ѿ������ �̵� ����
                        }
                        else // �ڿ� ���ڰ� ���� ��
                        {
                            if (int(c_back) == int('T'))
                            {
                                if (pKing[0] - 1 >= 0 && pKing[1] + 1 <= 7)
                                {
                                    pKing[0] -= 1; pKing[1] += 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] - 1 >= 0 && pStone[1] + 1 <= 7)
                                        {
                                            pStone[0] -= 1; pStone[1] += 1;
                                        }
                                        else
                                        {
                                            pKing[0] += 1; pKing[1] -= 1;
                                        }
                                    }
                                    else
                                    {
                                        // �Ȱ�ġ�� �ȿŰܿ�
                                    }
                                }
                                else
                                    break;
                            }
                            else if (int(c_back) == int('B'))
                            {
                                if (pKing[0] - 1 >= 0 && pKing[1] - 1 >= 0)
                                {
                                    pKing[0] -= 1; pKing[1] -= 1;
                                    if (pKing[0] == pStone[0] && pKing[1] == pStone[1])
                                    {
                                        if (pStone[0] - 1 >= 0 && pStone[1] - 1 >= 0)
                                        {
                                            pStone[0] -= 1; pStone[1] -= 1;
                                        }
                                        else
                                        {
                                            pKing[0] += 1; pKing[1] += 1;
                                        }
                                    }
                                    else
                                    {
                                        // �Ȱ�ġ�� �ȿŰܿ�
                                    }
                                }
                                else
                                    break;
                            }
                        }

                    break;
        }
    }

    char kx = pKing[0] + 65;
    char ky = pKing[1] + '0' + 1;
    char sx = pStone[0] + 65;
    char sy = pStone[1] + '0' + 1;
    string pos_King = "A1"; string pos_Stone = "A1";
    pos_King[0] = kx; pos_King[1] = ky;
    pos_Stone[0] = sx; pos_Stone[1] = sy;

    printf("%s\n%s", pos_King.c_str(), pos_Stone.c_str());
}