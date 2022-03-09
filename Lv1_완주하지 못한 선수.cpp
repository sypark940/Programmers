#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> mapCompletion;	// key : ������ �̸�, val : ���� �� ���� ����

	// participant ������ �̿��� mapCompletion ����
	for (string name : participant)
	{
		// mapCompletion �� ������� ���� ������ -> ����
		// mapCompletion �� ����� ������ -> �ο� ���� (��������)
		// 
		if (mapCompletion.find(name) == mapCompletion.end())
			mapCompletion[name] = 1;
		else
			mapCompletion[name]++;
	}

	// completion ������ �̿��� mapCompletion �� ���� ���� ������Ʈ
	for (string name : completion)
	{
		if (mapCompletion.find(name) != mapCompletion.end())
		{
			mapCompletion[name]--;
		}
	}

	// �������� ���� ���� Ž��
	for (auto iter = mapCompletion.begin(); iter != mapCompletion.end(); iter++)
	{
		if (iter->second == 1)
		{
			answer = iter->first;
			break;
		}
	}

	return answer;
}