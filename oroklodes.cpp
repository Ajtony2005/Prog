#include <iostream>

using namespace std;

struct A
{
    A() { cout << "constr A " << this << endl; }
    virtual ~A() { cout << "destr A " << this << endl; }
    virtual void f() { cout << "Af" << endl; }
    int m;
};

struct B : public A
{
    B() { cout << "constr B " << this << endl; }
    ~B() { cout << "destr B " << this << endl; }
    void f() { cout << "Bf" << endl; }
    int masikm;
};
int main()
{
    cout << "___" << endl;
    A *aa = new A;
    cout << "___" << endl;
    A *ab = new B;
    cout << "___" << endl;
    A *bb = new B;
    cout << "___" << endl;
    aa->f();
    cout << "___" << endl;
    ab->f();
    cout << "___" << endl;
    bb->f();
    cout << "___" << endl;
    delete aa;
    cout << "___" << endl;
    delete ab;
    cout << "___" << endl;
    delete bb;

    return 0;
}
