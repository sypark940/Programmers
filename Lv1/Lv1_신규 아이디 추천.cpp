#include <string>

using namespace std;

string solution(string new_id) {
  
    string answer = "";

    string tmp_answer = "";
    for (auto c : new_id)
    {
        // 1단계 : 대문자 -> 소문자
        char c1 = tolower(c);

        // 2단계 : 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자 제거
        if (c1 >= 'a' && c1 <= 'z')
            tmp_answer.push_back(c1);
        else if (c1 >= '0' && c1 <= '9')
            tmp_answer.push_back(c1);
        else if (c1 == '-' || c1 == '_' || c1 == '.')
            tmp_answer.push_back(c1);
    }
    
    // 3단계 : 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환
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

    // 4단계 : 마침표(.)가 처음이나 끝에 위치한다면 제거
    if (!tmp_answer.empty())
    {
        if (tmp_answer.front() == '.')
            tmp_answer.erase(tmp_answer.begin());
       
        if (tmp_answer.back() == '.')
            tmp_answer.pop_back();
    }

    // 5단계 : 빈 문자열이라면 "a" 를 대입
    if (tmp_answer.empty())
        tmp_answer = "a";

    // 6단계 : 길이가 16자 이상이면, 첫 15개를 제외한 나머지 문자열을 모두 제거 및 마지막 마침표(.) 제거
    answer = tmp_answer.substr(0, 15);
    if (answer.back() == '.')
        answer.pop_back();

    // 7단계 : 길이가 2자 이하라면, 마지막 문자를 길이가 3이 될 때 까지 반복
    while (answer.size() < 3)
    {
        answer.push_back(answer.back());
    };

    return answer;
}