#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    int pos = -1;
    for (int ii = 0; ii < seoul.size(); ii++)
    {
        if (seoul[ii] == "Kim")
        {
            pos = ii;
            break;
        }
    }

    answer = "�輭���� " + to_string(pos) + "�� �ִ�";
    return answer;
}