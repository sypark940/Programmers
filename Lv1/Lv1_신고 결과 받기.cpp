#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, set<string>> mapReport; // key : 이용자 id, val : 신고한 id
    unordered_map<string, int> mapReportCnt;      // key : 이용자 id, val : 신고당한 횟수
    unordered_map<string, int> mapNoticeCnt;      // key : 이용자 id, val : 정지 메일 수신 횟수

    // unordered map 초기화
    for (string id : id_list)
    {
        mapReport[id] = set<string>();
        mapReportCnt[id] = 0;
        mapNoticeCnt[id] = 0;
    }

    // report 의 데이터를 mapReport 에 저장
    for (string reportData : report)
    {
        // 공백문자를 기준으로 앞쪽은 userID, 뒷쪽은 reportID 로 분리
        int pos = reportData.find(" ");
        string userID = reportData.substr(0, pos);
        string reportID = reportData.substr(pos + 1, reportData.length());

        // mapReport 에 userID, reportID 를 중복 없이 저장
        mapReport[userID].insert(reportID);
    }

    // 각 이용자 별 신고당한 횟수 저장
    for (auto iter_report = mapReport.begin(); iter_report != mapReport.end(); iter_report++)
    {
        // mapReport 에 저장되어 있는 각 사용자가 신고한 id 에 순서대로 접근
        for (auto iter_report2 = iter_report->second.begin(); iter_report2 != iter_report->second.end(); iter_report2++)
        {
            mapReportCnt[*iter_report2]++;
        }
    }

    // 각 이용자 별 정지메일 수신 횟수 저장
    for (auto iter_reportCnt = mapReportCnt.begin(); iter_reportCnt != mapReportCnt.end(); iter_reportCnt++)
    {
        // k 번 이상 신고당한 이용자의 경우, 해당 이용자를 신고한 이용자의 정지메일 수신 횟수 갱신
        if (iter_reportCnt->second >= k)
        {
            for (auto iter_report = mapReport.begin(); iter_report != mapReport.end(); iter_report++)
            {
                if (iter_report->second.find(iter_reportCnt->first) != iter_report->second.end())
                    mapNoticeCnt[iter_report->first]++;
            }
        }
    }

    // 각 이용자 별 정지메일 수신 횟수를 answer 에 저장
    for (string id : id_list)
    {
        answer.push_back(mapNoticeCnt[id]);
    }

    return answer;
}