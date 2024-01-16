#define _CRT_SECURE_NO_WARNINGS
// Linked List Ȱ�� -> ���� �бⰡ �ϳ� ��ٷο�
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <map>
#include <stack>
#include <sstream>
#include <unordered_map>

using namespace std;

class _linked_List
{
public:
	_linked_List* front;
	_linked_List* back;
	char data;

	_linked_List(char c)
	{
		front = nullptr;
		back = nullptr;
		data = c;
	}
};

int main(void)
{
	deque<char> dq;
	_linked_List* ptr = nullptr;
	_linked_List* ptr_first = nullptr;
	bool isFront = false;

	while (true)
	{
		char c;
		scanf("%c", &c);
		if ((int)c == (int)'\n' || (int)c == (int)' ')
			break;
		dq.push_back(c);
	}
	while (!dq.empty())
	{
		_linked_List* t = new _linked_List(dq.front());
		dq.pop_front();
		if (ptr == nullptr) // ù��° ������ LL
		{
			ptr = t;
			ptr_first = t;
		}
		else
		{
			ptr->back = t;
			t->front = ptr;
			ptr = t;
		}
	}
	// ptr �� �� ������ �ܾ��� �����ͷ� ���õȴ�.
	// �⺻������ ptr �� ����Ű�� �ִ� ��ü�� ���ʿ� Ŀ���� �ִٰ� �����Ѵ�.
	// �׷��ٸ� Ŀ���� �� ������ �������� ���� �߰����� �����Ͱ� �ʿ� => bool isFront;

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char temp_c;
		scanf("%c", &temp_c);
		if ((int)temp_c == (int)'\n' || (int)temp_c == (int)' ') // ���Ͱ��� char�� ������ �κ��� �ٽ� �����͸� �޴´�.
		{
			i--;
			continue;
		}

		if ((int)temp_c == (int)'L') // ������ ��ĭ Ŀ�� �̵�
		{
			if (ptr == nullptr) // �� ����ִٸ�
			{
				isFront = false; // Ȥ�� �����Ͱ� �߰��ȴٸ� ������ isFront�� false�� �Ǿ�� ��
				continue; // ���� �ҰŴ� ����.
			}
			else // ���ڰ� �ֱ� �ִٸ�
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // ���ڰ� �Ѱ� ���̴�
				{
					if (isFront) // Ŀ���� �׸����� �� ���̴�
						continue; // �Ұ� ����
					else // �׳��� ���� �ڿ� Ŀ���� �־���
					{
						isFront = true; // Ŀ������ �� ������ ���ܿ´�
						continue;
					}
				}
				else if (ptr->front == nullptr) // ���ڰ� �������� �ѵ� �� �ձ��ڴ�
				{
					if (isFront) // Ŀ���� �׸����� �� ���̴�
						continue; // �Ұ� ����
					else // �׳��� ���� �ڿ� Ŀ���� �־���
					{
						isFront = true; // Ŀ������ �� ������ ���ܿ´�
						continue;
					}
				}
				else if (ptr->back == nullptr)
				{
					isFront = false; // Ȥ�� �𸣴ϱ� �ٽ� �ѹ� Ȯ��
					ptr = ptr->front; // �������� ������ �̵�
					continue;
				}
				else // ���ڰ� �������ε��ٰ� �� �ձ��� �ʿ� Ŀ���� ���� ����
				{
					isFront = false; // Ȥ�� �𸣴ϱ� �ٽ� �ѹ� Ȯ��
					ptr = ptr->front; // �������� ������ �̵�
					continue;
				}
			}
		}
		else if ((int)temp_c == (int)'D') // �ڷ� ��ĭ Ŀ�� �̵�
		{
			if (ptr == nullptr) // ���ڰ� �ƿ� ����
			{
				isFront = false; // ������ ���� �߰��Ǹ� false�� �ǰ� �Ǿ�����
				continue; // ���� �� �� ����
			}
			else // �ϴ� ���ڰ� �ֱ� �ִ�
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // ���ڰ� �� �Ѱ���
				{
					if (isFront) // Ŀ���� �� �տ��ִ�
					{
						isFront = false; // Ŀ�� ��ġ�� �ٲٰ� �Ѿ��
						continue;
					}
					else // Ŀ���� �� �ڸ� �� �� ����.
					{
						continue;
					}
				}
				else if (ptr->back == nullptr) // ���ڰ� �������� �ѵ� �� �����̴�
				{
					isFront = false; // Ȥ�� ���� �ٽ� üũ
					continue; // �̹� �� �ڴϱ� �� ���� ����
				}
				else if (ptr->front == nullptr)
				{
					if (isFront)
						isFront = false;
					else
						ptr = ptr->back;
					continue;
				}
				else // ���ڰ� �������� �ڿ� ���ڰ� �ִ�.
				{
					isFront = false;
					ptr = ptr->back; // �������� �̵�
					continue;
				}
			}
		}
		else if ((int)temp_c == (int)'B') // ���� ���� ����
		{
			if (ptr == nullptr) // ���ڰ� �ƿ� ����
			{
				isFront = false; // ������ ���� �߰��Ǹ� false�� �ǰ� �Ǿ�����
				continue; // ���� �� �� ����
			}
			else // �ϴ� ���ڰ� �ֱ� �ִ�
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // ���ڰ� �� �Ѱ���
				{
					if (isFront) // Ŀ���� �� ���̸� ���� �� ����.
					{
						continue;
					}
					else // Ŀ���� �� �ڸ�
					{
						delete ptr;
						ptr = nullptr; // ������ ���� ���� �����ֱ�
						ptr_first = nullptr; // �� �� ���� �����͵� ����.
						continue;
					}
				}
				else if (ptr->back == nullptr) // ���ڰ� �������� �ѵ� �� �����̴�
				{
					_linked_List* tp = ptr->front;
					ptr->front->back = nullptr; // �� ���� ���� �޳��� �� �����̹Ƿ� �ճ��� ���� �����͸� ���ش�.
					delete ptr; // �� �޳��� ptr�� ����� �� �ճ����� �Űܰ�
					ptr = tp;
					continue;
				}
				else if (ptr->front == nullptr) // ���ڰ� �������� �ѵ� �� �����̴�
				{
					if (isFront) // ���� �Ǿ��̸� ����� ����.
						continue;
					else
					{
						ptr_first = ptr->back; // �� ��ģ���� �ٲ��ش�.
						ptr->back->front = nullptr; // �� ��ģ���� �� �޳��� �� �����͸� ���ش�
						delete ptr; // �� �ճ��� ���ش�.
						ptr = ptr_first; // �� �ճ��̶� ���� �����͸� �����Ѵ�.
						isFront = true; // �� ���� ���������� �ٶ��� �����Ͱ� ���� ������ �̵��ߴ�.
						continue;
					}
				}
				else // ���ڰ� �������� �� �ڿ� ���ڰ� �ִ�.
				{
					isFront = false; // ���� �߰��̴� front�ϸ� ����.
					_linked_List* tp = ptr->front; // ptr�� �������� Ŀ���� �� �ճ��� ���ʿ� ��ġ�ϰ� �ȴ�.
					ptr->front->back = ptr->back; // �ճ��� �ڸ� �� �޳�� ����
					ptr->back->front = ptr->front; // �޳��� ���� �� �ճ�� ����
					delete ptr; // ȥ�� ������ ���� ptr ����
					ptr = tp; // Ŀ���� �ճ����� ������ �� ����
					continue;
				}
			}
		}
		else if ((int)temp_c == (int)'P') // ���� �߰�
		{
			char c_add;
			while (true)
			{
				scanf(" %c", &c_add); // �߰� �Է�
				if ((int)c_add != (int)'\n' && (int)c_add != (int)' ')
					break;
			}

			_linked_List* new_ll = new _linked_List(c_add);

			if (ptr == nullptr) // ���ڰ� �ƿ� ����
			{
				ptr = new_ll;
				ptr_first = new_ll;
				isFront = false; // Ŀ�� ���ʿ� ���ڰ� �߰��ǹǷ� Ŀ���� ���� �ڿ� ��ġ�Ѵ�.
				continue;
			}
			else // �ϴ� ���ڰ� �ֱ� �ִ�
			{
				if (ptr->front == nullptr && ptr->back == nullptr) // ���ڰ� �� �Ѱ���
				{
					if (isFront) // Ŀ���� �� ���̸�
					{
						new_ll->back = ptr;
						ptr->front = new_ll; // ptr ���� new_ll�� �����Ѵ�
						ptr_first = new_ll; // ù��° ptr�� �������ش�.
						isFront = false; // Ŀ�� ���ʿ� ���ڰ� �߰��Ǿ� Ŀ���� �� ���� �ƴ�
						ptr = ptr_first;
						continue;
					}
					else // Ŀ���� �� �ڸ�
					{
						new_ll->front = ptr; // ptr�� �ڸ� new_ll�� �����Ѵ�.
						ptr->back = new_ll; // �̹� ptr�� ù��°�� ���̴� ���� ���������� �ʴ´�.
						ptr = new_ll; // Ŀ���� �� �����̴� ���� �����ͷ� ����
						continue;
					}
				}
				else if (ptr->back == nullptr) // ���ڰ� �������� �ѵ� �� �����̴�
				{
					new_ll->front = ptr; // ptr�� �ڸ� new_ll�� �����Ѵ�.
					ptr->back = new_ll; // �̹� ptr�� ù��°�� ���̴� ���� ���������� �ʴ´�.
					ptr = new_ll; // Ŀ���� �� �����̴� ���� �����ͷ� ����
					continue;
				}
				else if (ptr->front == nullptr) // ���ڰ� �������� �ѵ� �� �����̴�
				{
					if (isFront) // Ŀ���� �� ���̸�
					{
						new_ll->back = ptr;
						ptr->front = new_ll; // ptr ���� new_ll�� �����Ѵ�
						ptr_first = new_ll; // ù��° ptr�� �������ش�.
						isFront = false; // Ŀ�� ���ʿ� ���ڰ� �߰��Ǿ� Ŀ���� �� ���� �ƴ�
						ptr = ptr_first;
						continue;
					}
					else // ���� �տ��ִ� ���� �ٷ� �ڿ� Ŀ�� = ���ڰ� �������� �� �ڿ� ����
					{
						new_ll->front = ptr;
						new_ll->back = ptr->back;
						ptr->back->front = new_ll;
						ptr->back = new_ll; // new_ll�� ��, �ڸ� ptr�� ptr->back���� üũ�ϰ� ������ ��, ���� new_ll�� �����ش�.
						ptr = new_ll; // Ŀ�� ���ʿ� ���ڰ� �߰��Ǿ����Ƿ� ���� Ŀ���� new_ll ���ʿ� ��ġ�ϰ� �ִ�.
						continue;
					}
				}
				else // ���ڰ� �������� �� �ڿ� ���ڰ� �ִ�.
				{
					new_ll->front = ptr;
					new_ll->back = ptr->back;
					ptr->back->front = new_ll;
					ptr->back = new_ll; // new_ll�� ��, �ڸ� ptr�� ptr->back���� üũ�ϰ� ������ ��, ���� new_ll�� �����ش�.
					ptr = new_ll; // Ŀ�� ���ʿ� ���ڰ� �߰��Ǿ����Ƿ� ���� Ŀ���� new_ll ���ʿ� ��ġ�ϰ� �ִ�.
					continue;
				}
			}
		}
	}

	ptr = ptr_first;
	while (true)
	{
		if (ptr == nullptr)
			break;
		printf("%c", ptr->data);
		if (ptr->back == nullptr)
			break;
		ptr = ptr->back;
	}
}

/* // ������ Ȱ��, ���� 2���� Ȱ���ؼ� Ŀ���� �������� 1�� ���� 2�� �������� ���ڵ��� �����д�.
#include<iostream>
#include<stack>
using namespace std;


int main() {
    string str;
    int n, i;
    stack<char> stk1, stk2;
    getline(cin, str);
    for (i = 0; i < str.size(); i++) {
        stk1.push(str[i]);
    }
    cin >> n;
    for (i = 0; i < n; i++) {
        char c;
        char input;
        cin >> c;
        if (c == 'P') {
            cin >> input;
            stk1.push(input);
        }
        else if (c == 'L') {
            if (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        else if (c == 'D') {
            if (!stk2.empty()) {
                stk1.push(stk2.top());
                stk2.pop();
            }
        }
        else if (c == 'B') {
            if (!stk1.empty()) {
                stk1.pop();
            }
        }
    }
    while (!stk1.empty()) {
        stk2.push(stk1.top());
        stk1.pop();
    }
    while (!stk2.empty()) {
        cout << stk2.top();
        stk2.pop();
    }
    return 0;
}
*/