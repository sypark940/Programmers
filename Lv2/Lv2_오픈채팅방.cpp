#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	map<string, string> mapRecord;			// key : 사용자 아이디, val : 닉네임	
	vector<pair<string, bool>> vecStatus;	// 사용자의 입출 상태를 순서대로 저장한 벡터

	for (string s : record)
	{
		// 문자열 s 에서 status, id, nickname 을 구분
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

	// answer 에 출력 메시지 추가
	for (auto status : vecStatus)
	{
		if (status.second)
		{
			answer.push_back(mapRecord[status.first] + "님이 들어왔습니다.");
		}
		else
		{
			answer.push_back(mapRecord[status.first] + "님이 나갔습니다.");
		}
	}

	return answer;
}