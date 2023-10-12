#include <iostream>

using namespace std;

int main(int, char**){
    char v[] = {33,34,35,36,37};
    char* p = &v[3];
    char x = *p;
    cout << reinterpret_cast<void *>(p) << endl; // print memory pointer (not char '$')
    cout << x << endl;
    cout << v[4] << endl;
    cout << reinterpret_cast<void *>(&v[4]) << endl; // print memory pointer (not char '%')
}
