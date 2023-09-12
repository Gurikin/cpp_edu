#include <iostream>
#include <climits>
#include "typedefs.h"

using namespace std;

int main(int, char**){
    uint score = 5000;
    cout << endl << "score: " << score << endl;
    score += 200;
    cout << "score += 200: " << score << endl;
    score = UINT_MAX;
    cout << "score int wrap: " << score << endl;
    ++score;
    cout << "score = max uint + 1: " << score << endl;
    return 0;
}
