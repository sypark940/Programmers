#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	map<string, string> mapRecord;			// key : ����� ���̵�, val : �г���	
	vector<pair<string, bool>> vecStatus;	// ������� ���� ���¸� ������� ������ ����

	for (string s : record)
	{
		// ���ڿ� s ���� status, id, nickname �� ����
		int start_pos = 0;
		int target_pos = s.find(" ");
		string status = s.substr(start_pos, target_pos);
		start_pos = target_pos + 1;

		target_pos = s.find(" ", start_pos);
		string id = s.substr(start_pos, target_pos - start_pos);
		start_pos = target_pos + 1;

		string nickname = s.substr(start_pos, s.length() - start_pos);

		//
		if (status == "Enter")
		{
			mapRecord[id] = nickname;
			vecStatus.push_back(make_pair(id, true));
		}
		else if (status == "Leave")
		{
			vecStatus.push_back(make_pair(id, false));
		}
		else if (status == "Change")
		{
			mapRecord[id] = nickname;
		}
	}

	// answer �� ��� �޽��� �߰�
	for (auto status : vecStatus)
	{
		if (status.second)
		{
			answer.push_back(mapRecord[status.first] + "���� ���Խ��ϴ�.");
		}
		else
		{
			answer.push_back(mapRecord[status.first] + "���� �������ϴ�.");
		}
	}

	return answer;
}