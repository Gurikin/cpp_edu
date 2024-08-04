#include <iostream>
using namespace std;

/**
 *
 */
int main()
{
    int t = 0;
    cin >> t;
    int pows[t];
    for (int i = 0; i < t; ++i)
    {
        int a = 0;
        cin >> a;
        int x = 1;
        int p = 0;
        while (x < a) {
            x *= 2;
            pows[i] = p++;
        }
    }
    for (int c = 0; c < t; c++) {
        cout << pows[c] << '\n';
    }
    return 0;
}
