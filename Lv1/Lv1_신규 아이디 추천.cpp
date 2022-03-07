#include <string>

using namespace std;

string solution(string new_id) {
  
    string answer = "";

    string tmp_answer = "";
    for (auto c : new_id)
    {
        // 1�ܰ� : �빮�� -> �ҹ���
        char c1 = tolower(c);

        // 2�ܰ� : �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���� ����
        if (c1 >= 'a' && c1 <= 'z')
            tmp_answer.push_back(c1);
        else if (c1 >= '0' && c1 <= '9')
            tmp_answer.push_back(c1);
        else if (c1 == '-' || c1 == '_' || c1 == '.')
            tmp_answer.push_back(c1);
    }
    
    // 3�ܰ� : ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ
    for (auto iter = tmp_answer.begin(); iter != tmp_answer.end()-1; )
    {
        char c1 = *iter;
        char c2 = *(iter+1);

        if (c1 == '.' && c2 == '.')
        {
            tmp_answer.erase(iter);
        }
        else
        {
            iter++;
        }
    }

    // 4�ܰ� : ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� ����
    if (!tmp_answer.empty())
    {
        if (tmp_answer.front() == '.')
            tmp_answer.erase(tmp_answer.begin());
       
        if (tmp_answer.back() == '.')
            tmp_answer.pop_back();
    }

    // 5�ܰ� : �� ���ڿ��̶�� "a" �� ����
    if (tmp_answer.empty())
        tmp_answer = "a";

    // 6�ܰ� : ���̰� 16�� �̻��̸�, ù 15���� ������ ������ ���ڿ��� ��� ���� �� ������ ��ħǥ(.) ����
    answer = tmp_answer.substr(0, 15);
    if (answer.back() == '.')
        answer.pop_back();

    // 7�ܰ� : ���̰� 2�� ���϶��, ������ ���ڸ� ���̰� 3�� �� �� ���� �ݺ�
    while (answer.size() < 3)
    {
        answer.push_back(answer.back());
    };

    return answer;
}