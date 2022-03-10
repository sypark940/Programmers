#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	vector<pair<char, string>> vecPair;	// key : n��° ����, val : ���ڿ� ��ü
	for (string s : strings)
		vecPair.push_back(make_pair(s[n], s));

	// vecPair �� key �� ���� �������� ����
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