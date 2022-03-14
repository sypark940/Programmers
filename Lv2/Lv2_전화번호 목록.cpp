#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	// ��� ��ȭ��ȣ�� key ������ ������ map ����
	map<string, int> map_phone;
	for (string s : phone_book)
		map_phone[s] = 1;

	// ��ȭ��ȣ���� �� ��ȭ��ȣ�� ���� ���� �� �ִ� ���ξ ������
	// �ش� ���ξ map �� �����ϴ��� Ȯ��
	for (string s : phone_book)
	{
		for (size_t ii = 1; ii < s.length(); ii++)
		{
			string sub_s = s.substr(0, ii);
			if (map_phone[sub_s])
				return false;
		}
	}
	return answer;
}