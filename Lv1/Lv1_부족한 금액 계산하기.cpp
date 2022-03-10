using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = (long long)money;

    // ���̱ⱸ�� count �� Ż ����� �� ���� �ݾ��� ���
    long long pay = 0;
    for (int ii = 1; ii <= count; ii++)
    {
        pay += (ii * price);
    }

    // ������ �ִ� �ݾ��� �������� ���� ��� -> 0
    // ������ �ִ� �ݾ��� ������ ��� -> ���ڶ� �ݾ� ����
    if (pay < money)
        answer = 0;
    else
        answer = pay - money;

    return answer;
}