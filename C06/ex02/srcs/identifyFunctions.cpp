#include "identifyFunction.hpp"
#include <cstdlib>
#include <ctime>

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

Base * generate(void)
{
    std::srand(std::time(0));
    int RandNumber = (std::rand() % 3);
    genBase constructors[3] = {&genA, &genB, &genC};

    return (constructors[RandNumber]());
}

void identify(Base* p)
{
	std::cout << "\033[1;30mIdentifying with a Base Pointer \033[0m" << std::endl;
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
void identify(Base& p)
{
	std::cout << "\033[1;30mIdentifying with a Base Reference \033[0m" << std::endl;
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "Type is A" << std::endl;
        return ;
    }
    catch (std::exception &e){
    }
    try
    {
        B b = dynamic_cast<B&>(p);
        std::cout << "Type is B" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {
    }
    try
    {
        C c = dynamic_cast<C&>(p);
        std::cout << "Type is C" << std::endl;
        return ;
    }
    catch(std::exception &e)
    {
        std::cout << "Cast was not succefull: " << e.what() << std::endl;
    }
}
