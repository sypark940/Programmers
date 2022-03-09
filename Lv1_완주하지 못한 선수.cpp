#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> mapCompletion;	// key : 참가자 이름, val : 참가 및 완주 여부

	// participant 정보를 이용해 mapCompletion 생성
	for (string name : participant)
	{
		// mapCompletion 에 저장되지 않은 참가자 -> 저장
		// mapCompletion 에 저장된 참가자 -> 인원 갱신 (동명이인)
		// 
		if (mapCompletion.find(name) == mapCompletion.end())
			mapCompletion[name] = 1;
		else
			mapCompletion[name]++;
	}

	// completion 정보를 이용해 mapCompletion 에 완주 여부 업데이트
	for (string name : completion)
	{
		if (mapCompletion.find(name) != mapCompletion.end())
		{
			mapCompletion[name]--;
		}
	}

	// 완주하지 못한 선수 탐색
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