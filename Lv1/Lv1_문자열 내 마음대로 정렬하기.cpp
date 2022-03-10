#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	vector<pair<char, string>> vecPair;	// key : n번째 문자, val : 문자열 전체
	for (string s : strings)
		vecPair.push_back(make_pair(s[n], s));

	// vecPair 의 key 값 기준 오름차순 정렬
	sort(vecPair.begin(), vecPair.end()
		, [](pair<char, string> a, pair<char, string> b) -> bool {
			if (a.first == b.first)
				return a.second < b.second;
			return a.first < b.first;
		});

	for (auto vec : vecPair)
		answer.push_back(vec.second);

	return answer;
}