#define _CRT_SECURE_NO_WARNINGS

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

using namespace std;

int main(void)
{
	string str;
	cin >> str; // 55-50+40
	istringstream s(str);
	string stringBuffer;

	vector<string> v;
	// 1. �� ���ڸ��� ������ = - ���ö����� ��������� �˴� ������ ���� �� �ִ� -> �ڿ� ���� ���ڵ� �׳� �� ���ؼ� ������ ����
	if (str[0] == '-')
	{
		vector<string> vTemp;
		istringstream ss(str);
		string strTemp;
		while (getline(ss, strTemp, '-'))
		{
			vTemp.push_back(strTemp);
		}
		for (int i = 0; i < vTemp.size(); i++)
		{
			string st = vTemp[i];
			if (st.find('+') == string::npos) // - ���ڵ� + ���ڵ� ���� ���ڸ� �ִ� string�̶��
				v.push_back(st);
			else
			{
				istringstream str1(st);
				string temp1;
				while (getline(str1, temp1, '+'))
				{
					v.push_back(temp1);
				}
			}
		}

		int result = 0;
		for (int i = 0; i < v.size(); i++)
		{
			result += stoi(v[i]);
		}
		printf("%d", result);
		return 0;
	}
	else
	{
		// �� ���ڸ��� -�� �ƴϸ� -> ó�� ������ '-' �պκ��� ���, �޺κ��� ���� ����
		while (getline(s, stringBuffer, '-'))
		{
			if (stringBuffer.empty())
				continue;
			v.push_back(stringBuffer);
		}
		// ���� v�� ù��° ���ڴ� ���ؼ� �����, ������ ���� ģ������ ���� ���ϰ� �������� ������ ����
		istringstream streamTemp1(v[0]);
		string maybelast;
		vector<string> lastVector;
		int _plus = 0;
		int _minus = 0;
		if (v[0].find('+') == string::npos)
			_plus += stoi(v[0]);
		else
		{
			while (getline(streamTemp1, maybelast, '+'))
			{
				lastVector.push_back(maybelast);
			}

			for (int j = 0; j < lastVector.size(); j++)
			{
				_plus += stoi(lastVector[j]);
			}
		} // ���� ��� �κ� üũ �Ϸ�

		if (v.size() > 1) // v ���� ������ 2 �̻� = ��� �κа� ���� �κ��� �ִ� 
		{
			for (int k = 1; k < v.size(); k++)
			{
				istringstream notthelast(v[k]);
				string stringcensored;
				while (getline(notthelast, stringcensored, '+'))
				{
					_minus += stoi(stringcensored);
				}
			}
			printf("%d", _plus - _minus);
			return 0;
		}
		else // = 1 ���ϸ� ��� �κи� �ִ�
		{
			printf("%d", _plus);
			return 0;
		}
	}

}