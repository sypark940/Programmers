#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    long long root = sqrt(n);
    if (pow(root, 2) == n)
        answer = pow(root + 1, 2);
    else
        answer = -1;

    return answer;
}