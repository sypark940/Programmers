#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    size_t length = s.length();

    // �ܾ��� ���̰� ¦���� ���
    if (length % 2 == 0)
    {
        answer += s[length / 2 - 1];
        answer += s[length / 2];
    }
    // �ܾ��� ���̰� Ȧ���� ���
    else
    {
        answer += s[length / 2];
    }

    return answer;
}