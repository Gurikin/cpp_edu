#include <iostream>
#include "Vector.h"

using namespace std;

int main(int, char**){
    Vector v(3);
    cout << "Input the 3 numbers of Vector: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cin>>v[i];
    }
    int sum = 0;
    cout << "In the Vector we have: ";
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        cout << v[i] << " ";
    }
    cout << endl;
    cout << "Sum of the elements: " << sum << endl;
}
