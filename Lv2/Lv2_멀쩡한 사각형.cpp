using namespace std;

long long GCD(int a, int b)
{
	int r = a % b;
	if (r == 0)
		return b;

	return GCD(b, r);
}

long long solution(int w, int h) {
	long long answer = 0;

	// w �� h �� ���� ���� �ִ������� ������ ���μҷ� �����. (-> ww, hh)
	long long gcd = GCD(w, h);
	int ww = w / gcd;
	int hh = h / gcd;

	// ww, hh �� �̷���� ���簢���� ������ �ܼ�ȭ�ϸ�,
	// ww, h �� �̷���� ���簢�� �� ��� �Ұ����� 1x1 ���簢���� ������ ww + hh - 1 �̴�.
	// 
	// [����]
	// �밢���� ��������� �����Ͽ� ���ֺ��� �ڳʷ� ���� ����,
	// => (0, 0) ��ġ�� �ִ� �� ù ��° 1x1 ���簢���� ����
	// => ww - 1 ���� ���μ��� ���� -> ���μ��� ���� �� ���� ��� �Ұ����� 1x1 ���簢�� 1���� �߰�
	// => hh - 1 ���� ���μ��� ���� -> ���μ��� ���� �� ���� ��� �Ұ����� 1x1 ���簢�� 1���� �߰�
	// => 1 + (ww - 1) + (hh - 1) = ww + hh - 1
	// => �ܼ�ȭ�� ������ ������� ������Ű��, w x h ���� ��� �Ұ����� 1x1 ���簢���� ������ gcd x (ww + hh - 1)
	answer = (long long)w * h - gcd * (ww + hh - 1);
	return answer;
}