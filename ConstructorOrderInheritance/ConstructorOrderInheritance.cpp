#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A ctor\n";
    }
    ~A()
    {
        std::cout << "A destr\n";
    }

};

class B : A
{
public:
    B()
    {
        std::cout << "B ctor\n";
    }
    ~B()
    {
        std::cout << "B destr\n";
    }
};

class C : B
{
public:
    C()
    {
        std::cout << "C ctor\n";
    }
    ~C()
    {
        std::cout << "C destr\n";
    }
};

int main()
{
    {
        C* c = new C();
        delete c;
    }
    
}
