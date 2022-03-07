#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    unordered_map<string, set<string>> mapReport; // key : �̿��� id, val : �Ű��� id
    unordered_map<string, int> mapReportCnt;      // key : �̿��� id, val : �Ű���� Ƚ��
    unordered_map<string, int> mapNoticeCnt;      // key : �̿��� id, val : ���� ���� ���� Ƚ��

    // unordered map �ʱ�ȭ
    for (string id : id_list)
    {
        mapReport[id] = set<string>();
        mapReportCnt[id] = 0;
        mapNoticeCnt[id] = 0;
    }

    // report �� �����͸� mapReport �� ����
    for (string reportData : report)
    {
        // ���鹮�ڸ� �������� ������ userID, ������ reportID �� �и�
        int pos = reportData.find(" ");
        string userID = reportData.substr(0, pos);
        string reportID = reportData.substr(pos + 1, reportData.length());

        // mapReport �� userID, reportID �� �ߺ� ���� ����
        mapReport[userID].insert(reportID);
    }

    // �� �̿��� �� �Ű���� Ƚ�� ����
    for (auto iter_report = mapReport.begin(); iter_report != mapReport.end(); iter_report++)
    {
        // mapReport �� ����Ǿ� �ִ� �� ����ڰ� �Ű��� id �� ������� ����
        for (auto iter_report2 = iter_report->second.begin(); iter_report2 != iter_report->second.end(); iter_report2++)
        {
            mapReportCnt[*iter_report2]++;
        }
    }

    // �� �̿��� �� �������� ���� Ƚ�� ����
    for (auto iter_reportCnt = mapReportCnt.begin(); iter_reportCnt != mapReportCnt.end(); iter_reportCnt++)
    {
        // k �� �̻� �Ű���� �̿����� ���, �ش� �̿��ڸ� �Ű��� �̿����� �������� ���� Ƚ�� ����
        if (iter_reportCnt->second >= k)
        {
            for (auto iter_report = mapReport.begin(); iter_report != mapReport.end(); iter_report++)
            {
                if (iter_report->second.find(iter_reportCnt->first) != iter_report->second.end())
                    mapNoticeCnt[iter_report->first]++;
            }
        }
    }

    // �� �̿��� �� �������� ���� Ƚ���� answer �� ����
    for (string id : id_list)
    {
        answer.push_back(mapNoticeCnt[id]);
    }

    return answer;
}