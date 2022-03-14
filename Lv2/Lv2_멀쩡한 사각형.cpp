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

	// w 와 h 를 각각 둘의 최대공약수로 나눠서 서로소로 만든다. (-> ww, hh)
	long long gcd = GCD(w, h);
	int ww = w / gcd;
	int hh = h / gcd;

	// ww, hh 로 이루어진 직사각형의 문제로 단순화하면,
	// ww, h 로 이루어진 직사각형 중 사용 불가능한 1x1 정사각형의 개수는 ww + hh - 1 이다.
	// 
	// [설명]
	// 대각선이 출발점에서 시작하여 마주보는 코너로 가는 동안,
	// => (0, 0) 위치에 있는 맨 첫 번째 1x1 정사각형을 지남
	// => ww - 1 개의 세로선을 지남 -> 세로선을 지날 때 마다 사용 불가능한 1x1 정사각형 1개씩 추가
	// => hh - 1 개의 가로선을 지남 -> 가로선을 지날 때 마다 사용 불가능한 1x1 정사각형 1개씩 추가
	// => 1 + (ww - 1) + (hh - 1) = ww + hh - 1
	// => 단순화한 문제를 원래대로 복구시키면, w x h 에서 사용 불가능한 1x1 정사각형의 개수는 gcd x (ww + hh - 1)
	answer = (long long)w * h - gcd * (ww + hh - 1);
	return answer;
}