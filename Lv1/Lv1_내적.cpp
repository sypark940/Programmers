#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
	int answer = 0;

	// Dot(a,b) = a1*b1 + a2*b2 + a3*b3 + ... + an*bn;
	for (size_t ii = 0; ii < a.size() && ii < b.size(); ii++)
	{
		answer += (a[ii] * b[ii]);
	}

	return answer;
}