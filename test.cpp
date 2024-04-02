#include <iostream>


using namespace std;

const int i =20;
const int j = 30;
const int* p = &i;
const int* q = &j;

int main() {
    cout << "i: " << i << endl;
    cout << "p: " << p << endl;
    cout << "j: " << j << endl;
    cout << "q: " << q << endl;
    (p+1)->q;
    delete p;

    return 0;
}