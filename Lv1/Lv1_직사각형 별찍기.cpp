#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;

    for (size_t ii = 0; ii < b; ii++)
    {
        for (size_t jj = 0; jj < a; jj++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}