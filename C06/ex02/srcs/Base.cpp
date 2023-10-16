#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>

Base::~Base(){};

static Base* genA()
{
    return (new A());
}

static Base*genB()
{
    return (new B());
}

static Base* genC()
{
    return (new C());
}

typedef Base* (*genBase)();

Base * Base::generate(void)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0,2);
    genBase constructors[3] = {&genA, &genB, &genC};

    int number = dist(rd);
    return (constructors[number]());
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type is C" << std::endl;
    else
        std::cout << "Cast was not succefull" << std::endl;
}

// You cannot verify the success of a dynamic cast using reference types by comparing the result
// (the reference that results from the dynamic cast) with zero because there is no such thing as a zero reference.
// A failing dynamic cast to a reference type throws a bad_cast exception.
void Base::identify(Base& p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "Type is A" << std::endl;
    }
    catch (const std::bad_cast& e){
        try
        {
            B b = dynamic_cast<B&>(p);
            std::cout << "Type is B" << std::endl;
        }
        catch(const std::bad_cast& e)
        {
            try
            {
                C c = dynamic_cast<C&>(p);
                std::cout << "Type is C" << std::endl;
            }
            catch(const std::bad_cast& e)
            {
                std::cout << "Cast was not succefull" << std::endl;
            }
        }
    }
}
